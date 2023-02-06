#ifndef FIGURE_H
#define FIGURE_H
#include <QPoint>
#include <array>
#include <QPainter>
#include <iostream>


struct figure
{
    virtual ~figure();
    virtual void draw(QPainter &painter, QPoint& pos) = 0;
    virtual bool mouse_inside(QPoint pos) = 0;
    virtual void info() = 0;
    virtual void changeLocation(QPoint shift) = 0;

    bool deleteStatus = false;

};

struct circle : public figure
{
    QPoint center_;
    int radius_;


    circle(QPoint center, int radius) : center_(center), radius_(radius) {}

    void draw(QPainter &painter, QPoint& pos) override
    {
        painter.setPen(Qt::blue);
        if (mouse_inside(pos))
            painter.setPen(Qt::green);
        painter.drawEllipse(center_, radius_, radius_);
    }

    bool mouse_inside(QPoint pos) override
    {
        if ((center_.x()-pos.x())*(center_.x()-pos.x()) + (center_.y()-pos.y())*(center_.y()-pos.y()) <= radius_*radius_)
            return true;
        else return false;
    }

    void info() override
    {
        std::cout << "circle:" << std::endl;
        std::cout << "x_center = " << center_.x() << " " << "y_center = "<< center_.y() << " " << "rad = " << radius_ << std::endl;
    }

    void changeLocation(QPoint shift) override
    {
        center_ += shift;
    }
};

struct triangle : public figure
{
    std::array<QPoint, 3> verts_;

    triangle(std::array<QPoint, 3> verts) : verts_(verts) {}

    void draw(QPainter& painter, QPoint& pos) override
    {
        painter.setPen(Qt::blue);
        if (mouse_inside(pos))
            painter.setPen(Qt::green);
        painter.drawLine(verts_[0],verts_[1]);
        painter.drawLine(verts_[1],verts_[2]);
        painter.drawLine(verts_[2],verts_[0]);
    }

    bool mouse_inside(QPoint pos) override
    {
        int a = (verts_[0].x() - pos.x()) * (verts_[1].y() - verts_[0].y()) - (verts_[1].x() - verts_[0].x()) * (verts_[0].y() - pos.y());
        int b = (verts_[1].x() - pos.x()) * (verts_[2].y() - verts_[1].y()) - (verts_[2].x() - verts_[1].x()) * (verts_[1].y() - pos.y());
        int c = (verts_[2].x() - pos.x()) * (verts_[0].y() - verts_[2].y()) - (verts_[0].x() - verts_[2].x()) * (verts_[2].y() - pos.y());
        //if ((pos.x() - verts_[0].x())/(verts_[1].x()- verts_[0].x()) - (pos.y() - verts_[0].y())/(verts_[1].y()- verts_[0].y()) >= 0\
             && (pos.x() - verts_[1].x())/(verts_[2].x()- verts_[1].x()) - (pos.y() - verts_[1].y())/(verts_[2].y()- verts_[1].y()) >= 0\
             && (pos.x() - verts_[2].x())/(verts_[0].x()- verts_[2].x()) - (pos.y() - verts_[2].y())/(verts_[0].y()- verts_[2].y()) >= 0)
         if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
              return true;
         else return false;
    }

    void info() override
    {
        std::cout << "Triangle:" << std::endl;
        for (auto &v: verts_)
        std::cout << "x = " << v.x() << " " << "y = " << v.y() << std::endl;

    }

    void changeLocation(QPoint shift) override
    {
        verts_[0] += shift;
        verts_[1] += shift;
        verts_[2] += shift;
    }

};

struct square : public figure
{
    std::array<QPoint, 4> verts_;

    square(std::array<QPoint, 4> verts) : verts_(verts) {}

    void draw(QPainter& painter, QPoint& pos) override
    {
        painter.setPen(Qt::blue);
        if (mouse_inside(pos))
            painter.setPen(Qt::green);
        painter.drawLine(verts_[0],verts_[1]);
        painter.drawLine(verts_[1],verts_[2]);
        painter.drawLine(verts_[2],verts_[3]);
        painter.drawLine(verts_[3],verts_[0]);
    }

    bool mouse_inside(QPoint pos) override
    {
        int a = (verts_[0].x() - pos.x()) * (verts_[1].y() - verts_[0].y()) - (verts_[1].x() - verts_[0].x()) * (verts_[0].y() - pos.y());
        int b = (verts_[1].x() - pos.x()) * (verts_[2].y() - verts_[1].y()) - (verts_[2].x() - verts_[1].x()) * (verts_[1].y() - pos.y());
        int c = (verts_[2].x() - pos.x()) * (verts_[3].y() - verts_[2].y()) - (verts_[3].x() - verts_[2].x()) * (verts_[2].y() - pos.y());
        int d = (verts_[3].x() - pos.x()) * (verts_[0].y() - verts_[3].y()) - (verts_[0].x() - verts_[3].x()) * (verts_[3].y() - pos.y());

         if ((a >= 0 && b >= 0 && c >= 0 && d >= 0) || (a <= 0 && b <= 0 && c <= 0 && d <= 0))
              return true;
         else return false;
    }

    void info() override
    {
        std::cout << "Square:" << std::endl;
        for (auto &v: verts_)
        std::cout << "x = " << v.x() << " " << "y = " << v.y() << std::endl;
    }

    void changeLocation(QPoint shift) override
    {
        verts_[0] += shift;
        verts_[1] += shift;
        verts_[2] += shift;
        verts_[3] += shift;

    }

};

#endif // FIGURE_H
