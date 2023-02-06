#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

enum Sex {Man,Woman};

struct Employee
{
    int num, birth_year;
    QString full_name;
    Sex sex;
};

#endif // EMPLOYEE_H
