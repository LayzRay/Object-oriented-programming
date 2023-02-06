#include "my_text_class.h"
#include <QTextEdit>

My_text_class::My_text_class(QWidget *parent) :
    QTextBrowser(parent)
{
}

void My_text_class:: Color_red(QString text)
{
    auto color = this->textColor();
    this->setTextColor(Qt:: red);
    this->append(text);
    this->setTextColor(color);
}

void My_text_class:: Color_green(QString text)
{
    auto color = this->textColor();
    this->setTextColor(Qt:: green);
    this->append(text);
    this->setTextColor(color);
}
