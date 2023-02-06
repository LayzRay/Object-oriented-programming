#include "mainwindow.h" // Сам класс лежит в заголовочном файле
#include "ui_mainwindow.h"
#include "csv_reader.h"
#include "csv_writer.h"
#include "my_text_class.h"
#include <QFileDialog>
#include <QFileInfo>
#include <iostream>
#include "csv_exception.h"

MainWindow::MainWindow(QWidget *parent) // Тело метода класса MainWindow (конструктор)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // this - указатель на объект

    ui->Text_browser->append("Введите в поле поиска номер сотрудника, чтобы показать всю информацию о нём.");
    ui->Text_browser->append("(При других входных данных ничего не будет происходить).");
    ui->Text_browser->append("При введении команды 'sort' список сотрудников будет отсортирован по году рождения.");

}

MainWindow::~MainWindow() // Деструктор
{
    delete ui;
}

void MainWindow::Find_employee()
{
    // Сортировка по году рождения
    if (ui->Search_edit->text() == "sort")
    {
        /* std::sort(all_employees.begin(), all_employees.end(), [](const Employee &e1, const Employee &e2)
                {
                    return e1.birth_year > e2.birth_year;
                }); */

        std::sort(all_employees.begin(), all_employees.end());

        ui->Text_browser->append("\n");

        for (const auto &e: all_employees)
            ui->Text_browser->Color_green(QString::fromStdString(std::to_string(e.num)) + ", " + e.full_name\
            + ", " + QString::fromStdString(std::to_string(e.birth_year)) + ", " + QString::fromStdString(e.sex == 0? "Муж":"Жен"));

    }
    else
    {
        bool flag = false;
        // Поиск сотрудников по номеру
        for (auto &e: all_employees)
            if (ui->Search_edit->text() == QString::fromStdString(std::to_string(e.num)))
            {
                flag = true;
                ui->Text_browser->Color_green(e.to_string());
                std::cout << e;
            }


        if (!flag)
        {
            ui->Text_browser->Color_red("\nСотрудник не найден.");
        }

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

void MainWindow::Choose_file()
{

    QString file_name = QFileDialog::getOpenFileName(this,"Open a file","D:\\Users\\angol\\Documents\\OOP");

    QFileInfo fi(file_name);
    QString ext = fi.suffix();

    if (ext == "csv")
    {
        CSV_reader file(file_name);

        if (file.if_open())
        {
           ui->Text_browser->Color_green("\nФайл подключён.");
           try
          {
             all_employees = file.read_all();
           }
           catch (CSV_exception &em)
           {
                ui->Text_browser->Color_red("Малолетний сотрудник обнаружен!");
                std::cerr<< "Error in line " << em.GetLine();
           }

        }
        else
        {
            ui->Text_browser->Color_red("\nФайл не открылся.");
        }
    }
    else if (ext == "json")
    {
        JSON_reader file(file_name);

        Employee c;
        while (file >> c)
            std::cout << c << std::endl;

        if (file.if_open())
        {
           ui->Text_browser->Color_green("\nФайл подключён.");
           all_employees = file.read_all();
        }
        else
        {
            ui->Text_browser->Color_red("\nФайл не открылся.");
        }

    }
    else
        ui->Text_browser->Color_red("\nФайл имеет неверный формат.");

}
