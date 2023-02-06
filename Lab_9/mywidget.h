#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <figure.h>
#include <QMouseEvent>
#include <memory>
#include <QStatusBar>


QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;
    ~MyWidget();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void callMenu(QPoint pos);


signals:


private:

    QPoint mousePos = {0, 0};
    figure* pressedFigure = nullptr;
    figure* menuFigure = nullptr;
    Ui::MyWidget *ui;
    QStatusBar *statusBar;

    //std::vector<figure*> figures;
    //std::vector<std::unique_ptr<figure>> figures;
    std::list<std::unique_ptr<figure>> figures;

public slots:
    void setDelete();
    void showInfo();
    void createStatusBar();



};

#endif // MYWIDGET_H
