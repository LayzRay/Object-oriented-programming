#include "mainwindow.h" // Сам класс лежит в заголовочном файле
#include "ui_mainwindow.h"
#include "csv_reader.h"
#include "csv_writer.h"
#include "my_text_class.h"
#include <QFileDialog>
#include <QFileInfo>

std::vector<Employee> MainWindow::read_file(Abstract_reader& file)
{
    if (file.if_open())
    {
       ui->Text_browser->Color_green("\nФайл подключён.");
       return file.read_all();
    }
    else
    {
        ui->Text_browser->Color_red("\nФайл не открылся.");
        return {};
    }
}

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
        std::sort(all_employees.begin(), all_employees.end(), [](const Employee &e1, const Employee &e2)
                {
                    return e1.birth_year > e2.birth_year;
                });
        ui->Text_browser->Color_green("\n");
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
        all_employees = read_file(file);


    }
    else if (ext == "json")
    {
        JSON_reader file(file_name);
        all_employees = read_file(file);
    }
    else
        ui->Text_browser->Color_red("\nФайл имеет неверный формат.");

}
