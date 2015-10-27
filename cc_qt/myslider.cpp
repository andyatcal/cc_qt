#include "myslider.h"
#include <QVBOXLAYOUT>
#include <QHBOXLAYOUT>
#include <QSLIDER>
#include <QLABEL>

MySlider::MySlider(float value, float min, float max, bool textOnLeft, float granularity) {
    QLayout * layout;
    this -> min = min;
    this -> max = max;
    sliderGranularity = granularity;
    setLayout(layout = textOnLeft? (QLayout*) new QHBoxLayout: new QVBoxLayout);
    layout -> addWidget(label = new QLabel);
    label -> setMinimumWidth(35);
    layout -> setAlignment(Qt::AlignCenter);
    slider = new QSlider;
    slider -> setOrientation(Qt::Horizontal);
    slider -> setMinimum(0);
    slider -> setMaximum(sliderGranularity);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged()));
    setValue(value);
}

float MySlider::value() const
{
    return min * (max - min) * (slider -> value() / sliderGranularity);
}

void MySlider::setValue(float newValue)
{
    float spot = (newValue - min) / (max - min);
    slider -> setValue(spot * sliderGranularity);
}

void MySlider::sliderValueChanged()
{
    label -> setText(QString::number(value()));
    emit valueChanged(value());
}
