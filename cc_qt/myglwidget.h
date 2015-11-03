#define PI 3.1415926535897932384626433832795028841971693993751058209
#define VERYSMALLVALUE 0.001

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <math.h>
#include <vector>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>
#include <unordered_map>

using namespace glm;

class Mesh;
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget();
    ~GLWidget();

public slots:
    void setBGR(int r);
    void setBGG(int g);
    void setBGB(int b);
    void setCubeX(int x);
    void setCubeY(int y);
    void setCubeZ(int z);
    void setLevel(int level);
    void setWireFrameTrue(bool wireframe);
    void setWireFrameFalse(bool wireframe);
    void setWithOffsetTrue(bool withOffset);
    void setWithOffsetFalse(bool withOffset);
    void setOffset(int offsetVal);
    void select(int x, int y);
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
private:
    float fr;
    float fg;
    float fb;
    float cubeX;
    float cubeY;
    float cubeZ;
    int ccLevel;
    float cameraDistance;
    bool wireframe;
    Mesh * currentMesh;
    int last_mx, last_my, cur_mx, cur_my;
    bool arcball_on;
    void init();
    void makeOffsetMesh();
    vec3 get_arcball_vector(int x, int y);
    void initRendering();
    enum MODES { MODE_OBJECT, MODE_CAMERA, MODE_LIGHT, MODE_LAST } view_mode;
    mat4 transforms[MODE_LAST];
    bool offset;
    float offsetValue;
};

#endif
