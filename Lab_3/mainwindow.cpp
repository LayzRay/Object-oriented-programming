#include "mainwindow.h" // Сам класс лежит в заголовочном файле
#include "ui_mainwindow.h"
#include "csv_reader.h"
#include "csv_writer.h"
#include <string>
#include <QString>

MainWindow::MainWindow(QWidget *parent) // Тело метода класса MainWindow (конструктор)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // this - указатель на объект

    ui->Text_browser->append("Введите в поле поиска номер сотрудника, чтобы показать всю информацию о нём.");
    ui->Text_browser->append("(При других входных данных ничего не будет происходить).");
    ui->Text_browser->append("При введении слова 'sort' список сотрудников будет отсортирован по году рождения.");

    CSV_reader file("Data base.csv");

    if (file.if_open())
    {
       all_employees = file.read_all();
    }

}

MainWindow::~MainWindow() // Деструктор
{
    delete ui;
}

void MainWindow::Find_employee()
{
    // Поиск сотрудников по номеру
    for (const auto &e: all_employees)
        if (ui->Search_edit->text() == QString::fromStdString(std::to_string(e.num)))
            ui->Text_browser->append("\n" + QString::fromStdString(std::to_string(e.num)) + ", " + e.full_name\
            + ", " + QString::fromStdString(std::to_string(e.birth_year)) + "," + QString::fromStdString(e.sex == 0? "Муж":"Жен"));

    // Сортировка по году рождения
    if (ui->Search_edit->text() == "sort")
    {
        std::sort(all_employees.begin(), all_employees.end(), [](const Employee &e1, const Employee &e2)
                {
                    return e1.birth_year > e2.birth_year;
                });
        ui->Text_browser->append("\n");
        for (const auto &e: all_employees)
            ui->Text_browser->append(QString::fromStdString(std::to_string(e.num)) + ", " + e.full_name\
            + ", " + QString::fromStdString(std::to_string(e.birth_year)) + ", " + QString::fromStdString(e.sex == 0? "Муж":"Жен"));
    }
}

void MainWindow::Add_employee()
{
    Employee new_employee;

    new_employee.num = ui ->ID_Edit -> text().toInt();
    new_employee.full_name = ui ->Name_Edit ->text();
    new_employee.birth_year = ui ->Year_Edit ->text().toInt();
    new_employee.sex = static_cast<Sex>(ui ->Sex_Edit ->currentIndex());

    all_employees.push_back(new_employee);

    csv_writer file("New Data Base.csv");

    if (file.if_open())
        file.Write_all(all_employees);
}
