#include "myglwidget.h"
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include "vertex.h"
#include "edge.h"
#include "face.h"
#include "mesh.h"
#include "makeMesh.h"
#include "subdivision.h"
#include "offset.h"
#include <iostream>

using namespace std;

Mesh glMesh;
Mesh glOffsetMesh;

// Colors
GLfloat WHITE[] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat RED[] = {0.8f, 0.0f, 0.0f, 1.0f};
GLfloat GREEN[] = {0.0f, 0.8f, 0.0f, 1.0f};
GLfloat BLUE[] = {0.0f, 0.0f, 0.8f, 1.0f};
GLfloat YELLOW[] = {.8f, .8f, 0.f, 1.f};
GLfloat PURPLE[] = {.8f, 0.f, .8f, 1.f};
GLfloat CYAN[] = {.0f, .8f, 0.8f, 1.f};

GLWidget::GLWidget()
{
    fr = 1;
    fg = 1;
    fb = 1;
    cubeX = 0.5;
    cubeY = 0.5;
    cubeZ = 0.5;
    ccLevel = 0;
    wireframe = false;
    last_mx=last_my=cur_mx=cur_my = 0.0;
    arcball_on = false;
    cameraDistance = 4.0;
    offset = false;
    offsetValue = 0.11;
    startTimer(0);
}

GLWidget::~GLWidget()
{
}

void GLWidget::init()
{
    makeCube(glMesh, cubeX, cubeY, cubeZ);
    Subdivision myCC(glMesh);
    glMesh = myCC.ccSubdivision(ccLevel);
    glMesh.computeNormals();
    if(offset) {
        makeOffsetMesh();
    }
}

void GLWidget::makeOffsetMesh()
{
    Offset myOff(glMesh, offsetValue);
    myOff.makeFullOffset();
    glOffsetMesh = myOff.offsetMesh;
}

void GLWidget::initRendering()
{
    // Two sided pr ones side;
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_ambient0[] = { 0.8, 0.8, 0.8, 10.0 };
    GLfloat light_diffuse0[] = { 1.0, 1.0, 1.0, 10.0 };
    GLfloat light_specular0[] = { 1.0, 1.0, 1.0, 10.0 };
    GLfloat light_position0[] = { 1, 1, 1, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    transforms[MODE_CAMERA] = lookAt(
        vec3(0.0,  0.0, cameraDistance),   // eye
        vec3(0.0,  0.0, 0.0),   // direction
        vec3(0.0,  1.0, 0.0));  // up
}

vec3 GLWidget::get_arcball_vector(int x, int y) {
    vec3 P = vec3(1.0 * x / this->width() * 2 - 1.0,
      1.0 * y / this->height() * 2 - 1.0, 0);
    P.y = - P.y;
    float OP_squared = P.x * P.x + P.y * P.y;
    if (OP_squared <= 1 * 1) {
        P.z = sqrt(1 * 1 - OP_squared);
    } else {
        P = normalize(P);  // nearest point
    }
    return P;
}

void GLWidget::setBGR(int r)
{
    fr = r * 1.0 / 256;
    repaint();
}

void GLWidget::setBGG(int g)
{
    fg = g * 1.0 / 256;
    repaint();
}

void GLWidget::setBGB(int b)
{
    fb = b * 1.0 / 256;
    repaint();
}

void GLWidget::setCubeX(int x)
{
    cubeX = x * 1.0 / 10;
    init();
    repaint();
}

void GLWidget::setCubeY(int y)
{
    cubeY = y * 1.0 / 10;
    init();
    repaint();
}

void GLWidget::setCubeZ(int z)
{
    cubeZ = z * 1.0 / 10;
    init();
    repaint();
}

void GLWidget::setLevel(int level)
{
    ccLevel = level;
    init();
    repaint();
}

void GLWidget::setWireFrameFalse(bool wireframe)
{
    if(wireframe)
    {
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        repaint();
    }
}

void GLWidget::setWireFrameTrue(bool wireframe)
{
    if(wireframe)
    {
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        repaint();
    }
}

void GLWidget::setWithOffsetTrue(bool withOffset)
{
    if(withOffset)
    {
        offset = true;
        init();
        repaint();
    }
}

void GLWidget::setWithOffsetFalse(bool withOffset)
{
    if(withOffset)
    {
        offset = false;
        repaint();
    }
}

void GLWidget::setOffset(int offsetVal)
{
    offsetValue = offsetVal * 1.0 / 100;
    if(offset) {
        init();
    }
}

void GLWidget::initializeGL()
{
    setMinimumSize(500, 400);
    init();
    initRendering();
}

void GLWidget::paintGL()
{
    glClearColor(fr, fg, fb, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, cameraDistance, 0, 0, 0, 0, 1, 0);
    glMultMatrixf(&glMesh.object2world[0][0]);
    if(!offset)
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, RED);
        glMesh.drawMesh();
    }
    else
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, BLUE);
        glOffsetMesh.drawMesh();
    }
    //glutSwapBuffers();
}

void GLWidget::resizeGL(int w, int h)
{
    if (h == 0) {h = 1;} // prevent a division by zero when setting aspect ratio
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float) w / h, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::timerEvent(QTimerEvent *event) {
    if(last_mx != cur_mx || last_my != cur_my) {
        vec3 va = get_arcball_vector(last_mx, last_my);
        vec3 vb = get_arcball_vector( cur_mx,  cur_my);
        float angle = acos(glm::min(1.0f, dot(va, vb)));
        vec3 axis_in_camera_coord = cross(va, vb);
        mat3 camera2object = inverse(mat3(transforms[MODE_CAMERA]) * mat3(glMesh.object2world));
        vec3 axis_in_object_coord = camera2object * axis_in_camera_coord;
        glMesh.object2world = rotate(glMesh.object2world, angle, axis_in_object_coord);
        last_mx = cur_mx;
        last_my = cur_my;
    }
    repaint();
}

void GLWidget::select(int x, int y)
{
    /*GLuint buff[64] = {0};
    GLint hits, view[4];

    glSelectBuffer(64, buff);
    glGetIntegerv(GL_VIEWPORT, view);
    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(x, y, 4, 4, view);
    gluPerspective(60, 1, 0.0001, 1000);
    int sensitivity = 10;

    int min_x = abs(x - sensitivity);
    int max_x = x + sensitivity;
    int min_y = abs(y - sensitivity);
    int max_y = y + sensitivity;
    for(auto&& vertex: glMesh.vertList){
        std::cout << "x: " << vertex->position[0] << std::endl;
        std::cout << "y: " << vertex->position[1] << std::endl;
        std::cout << "z: " << vertex->position[2] << std::endl;
    }*/
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        arcball_on = true;
        last_mx = cur_mx = event -> x();
        last_my = cur_my = event -> y();
        this->select(event->pos().x(), event->pos().y());
    }
    else
    {
        arcball_on = false;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (arcball_on)
    {
      cur_mx = event -> x();
      cur_my = event -> y();
    }
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    event -> accept();
    if(event -> key() == Qt::Key_W)
    {
        if(wireframe)
        {
            wireframe = false;
            glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        }
        else
        {
            wireframe = true;
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        }
    }
}
