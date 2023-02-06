#include "csv_reader.h"
#include <QString>
#include <string>
#include <vector>

using namespace std;

vector<QString> split(const string& str, char delim)
{
    vector<QString> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(QString::fromStdString(str.substr(start, (end - start))));

            start = end + 1;
        } while (end != string::npos);
    }

    return tokens;
}


CSV_reader::CSV_reader(const QString &filename)
{
    class_file.open(filename.toLatin1().data());
};

std::vector<Employee> CSV_reader::read_all()
{
    Employee current_employee;
    std::vector<Employee> class_all_employees;

    while (!class_file.eof())
    {
        string line;
        getline(class_file, line);

        vector <QString>  parts_of_the_line = split(line, ';');

        current_employee.num = stoi(parts_of_the_line[0].toLatin1().data());
        current_employee.full_name = parts_of_the_line[1];
        current_employee.birth_year = stoi(parts_of_the_line[2].toLatin1().data());
        current_employee.sex = static_cast<Sex>(stoi(parts_of_the_line[3].toLatin1().data()));

        class_all_employees.push_back(current_employee);
    }

    return class_all_employees;
};

CSV_reader::~CSV_reader()
{
    class_file.close();
};
