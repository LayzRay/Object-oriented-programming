#include "mywidget.h"
#include <QPainter>
#include <iostream>
#include <QPointF>
#include <memory.h>
#include <QMenu>
#include "ui_mywidget.h"


MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::MyWidget)
{

    ui->setupUi(this);
    this->setMouseTracking(true);
    figures.clear();

    std::list<QPoint> center_circle = {{50,40},{180,500}};
    std::list<int> rad_circle = {20,20};

    std::list<std::array<QPoint, 3>> verts_triangle = {{QPoint(100,100),QPoint(50,150),QPoint(150,150)}};
    std::list<std::array<QPoint, 4>> verts_square = {{QPoint(220,110),QPoint(220,300),QPoint(410,300),QPoint(410,110)}};


    std::list<int>:: iterator it = rad_circle.begin();
    int i = -1;
    for (auto& l: center_circle)
    {
        i++;
        advance(it,i);
        figures.push_back(std::unique_ptr<circle>(new circle(l,*it)));
    }

    for (auto& l: verts_triangle)
    {
        figures.push_back(std::unique_ptr<triangle>(new triangle(l)));
    }

    for (auto& l: verts_square)
    {
        figures.push_back(std::unique_ptr<square>(new square(l)));
    }

    /*
    figures.push_back(new circle({30,40},20));
    figures.push_back(new circle({300,300},200));
    figures.push_back(new triangle({20,10},{100,200},{140,250}));
    figures.push_back(new square({20,10},{20,200},{140,200},{140,10})); */
}

void MyWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    figures.remove_if([](std::unique_ptr<figure>& ptr)
       {
          return ptr->deleteStatus;
       });

    //painter.drawLine(30,40,200,300);
    //painter.drawEllipse(250,250,100,100);

    for (const auto& f: figures)
    {
        //if (f->type == "Triangle")
            //draw triangle

        f->draw(painter,mousePos); // художник

    }

}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && (pressedFigure))
    {
        pressedFigure->changeLocation(event->pos() - mousePos);
    }

   mousePos = { event-> x() , event-> y() };
   update();
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    for (auto &f: figures)
    {
        if ((event->buttons() & Qt::LeftButton) && (f->mouse_inside(event->pos())))
        {
            pressedFigure = f.get();
        }

        if ((event->buttons() & Qt::RightButton) && (f->mouse_inside(event->pos())))
           {
               menuFigure = f.get();
               callMenu(mapToGlobal(event->pos()));
           }
    }


}

void MyWidget::callMenu(QPoint pos)
{
    QMenu menu;
    connect(menu.addAction("Информация"),&QAction::triggered, this, &MyWidget::showInfo);
    connect(menu.addAction("Удалить"),&QAction::triggered, this, &MyWidget::setDelete);
    menu.exec(pos);
}

void MyWidget::setDelete()
{
    menuFigure->deleteStatus = true;
}

void MyWidget::showInfo()
{
    menuFigure->info();

}

void MyWidget::createStatusBar()
{
    //statusBar()->showMessage(tr("Ready"));
}

MyWidget::~MyWidget()
{ /*
    for (auto& f: figures)
    {
        delete f;
    } */
}
