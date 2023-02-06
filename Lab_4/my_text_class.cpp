#include "my_text_class.h"
#include <QTextEdit>

My_text_class::My_text_class(QWidget *parent) :
    QTextBrowser(parent)
{
}

void My_text_class:: Color_red()
{
    this->setTextColor(Qt:: red);
}

void My_text_class:: Color_green()
{
    this->setTextColor(Qt:: green);
}
