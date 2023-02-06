#ifndef MY_TEXT_CLASS_H
#define MY_TEXT_CLASS_H

#include <QTextBrowser>
#include "mainwindow.h"

class My_text_class : public QTextBrowser
{
    Q_OBJECT
public:
    explicit My_text_class(QWidget *parent = 0);

signals:

public slots:

    void Color_red(QString text);
    void Color_green(QString text);

};

#endif // MY_TEXT_CLASS_H
