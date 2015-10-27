#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWIDGET>
class QSlider;
class QLabel;

class MySlider : public QWidget
{
    Q_OBJECT

    QSlider * slider;
    QLabel * label;
    float sliderGranularity;
    float min;
    float max;
private slots:
    void sliderValueChanged();
signals:
    void valueChanged(float newValue);
public:
    MySlider(float value = 0.0f, float min = -10.0f, float max = 10.0f, bool textOnLeft = false, float granularity = 40.0);
    float value() const;
    void setValue(float newValue);

};

#endif // MYSLIDER_H
