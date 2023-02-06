#include "csv_reader.h"
#include <iostream>
#include "csv_exception.h"

std::vector<QString> split(const std::string& str, char delim)
{
    std::vector<QString> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(QString::fromStdString(str.substr(start, (end - start))));

            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}


CSV_reader::CSV_reader(const QString &filename)
{
   class_file.open(filename.toLatin1().data());  // Костыль - исправить (изучить)
   count_line = 0;
};

JSON_reader::JSON_reader(const QString &filename)
{
   class_file.open(filename.toLatin1().data());  // Костыль - исправить (изучить)
};

std::vector<Employee> CSV_reader::read_all()
{
    Employee current_employee;
    std::vector<Employee> class_all_employees;

    while (!class_file.eof())
    {
        std::string line;
        getline(class_file, line);
         count_line += 1;

        std::vector <QString>  parts_of_the_line = split(line, ';');
        try {

        current_employee.num = std::stoi(parts_of_the_line[0].toLatin1().data());
        current_employee.full_name = parts_of_the_line[1];
        current_employee.birth_year = std::stoi(parts_of_the_line[2].toLatin1().data());
        if (current_employee.birth_year > 2004)
        {
            throw CSV_exception(count_line);
        }
        current_employee.sex = static_cast<Sex>(std::stoi(parts_of_the_line[3].toLatin1().data()));
        }
    catch (const std::logic_error &e) {
       std::cerr << "Error: incorrect data" << std::endl;
       std::vector<Employee> res;
       return res;
                        }

        class_all_employees.push_back(current_employee);
    }

    return class_all_employees;
};

std::vector<Employee> JSON_reader::read_all()
{
    Employee current_employee;
    std::vector<Employee> class_all_employees;

    while (!class_file.eof())
    {
        std::string line;
        getline(class_file, line);

        std::vector <QString>  parts_of_the_line = split(line, ';');

        current_employee.num = std::stoi(parts_of_the_line[0].toLatin1().data());
        current_employee.full_name = parts_of_the_line[1];
        current_employee.birth_year = std::stoi(parts_of_the_line[2].toLatin1().data());
        current_employee.sex = static_cast<Sex>(std::stoi(parts_of_the_line[3].toLatin1().data()));

        class_all_employees.push_back(current_employee);
    }

    return class_all_employees;
};

CSV_reader& CSV_reader:: operator >> (Employee& current_employee)
{
    if (class_file.is_open() && !class_file.eof()) {
    std::string line;
    getline(class_file, line);
    if (!line.empty()){

        std::vector <QString>  parts_of_the_line = split(line, ';');

        current_employee.num = std::stoi(parts_of_the_line[0].toLatin1().data());
        current_employee.full_name = parts_of_the_line[1];
        current_employee.birth_year = std::stoi(parts_of_the_line[2].toLatin1().data());
        current_employee.sex = static_cast<Sex>(std::stoi(parts_of_the_line[3].toLatin1().data()));
    }
    }
   return *this;

};

JSON_reader& JSON_reader:: operator >> (Employee& current_employee)
{
    if (class_file.is_open() && !class_file.eof()) {
    std::string line;
    getline(class_file, line);
    if (!line.empty()){

        std::vector <QString>  parts_of_the_line = split(line, ';');

        current_employee.num = std::stoi(parts_of_the_line[0].toLatin1().data());
        current_employee.full_name = parts_of_the_line[1];

            current_employee.birth_year = std::stoi(parts_of_the_line[2].toLatin1().data());
            if (current_employee.birth_year > 2004)
            {
                throw 1;
            }

        current_employee.sex = static_cast<Sex>(std::stoi(parts_of_the_line[3].toLatin1().data()));
    }
    }
   return *this;

};

CSV_reader::~CSV_reader()
{
    class_file.close();
};

JSON_reader::~JSON_reader()
{
    class_file.close();
};
