#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "my_text_class.h"
#include "csv_reader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<Employee> read_file(Abstract_reader& file);



public slots:

    void Find_employee();
    void Add_employee();
    void Choose_file();

private:
    Ui::MainWindow *ui;

    std::vector<Employee> all_employees;
};
#endif // MAINWINDOW_H
