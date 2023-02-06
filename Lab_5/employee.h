#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

enum Sex {Man, Woman};

class Employee
{

public:

    int num, birth_year;
    QString full_name;
    Sex sex;

    Employee();

    virtual QString to_string()
    {
        std::string class_str = std::to_string(this->num) + ";" + this->full_name.toStdString()+ ";"\
                + std::to_string(this->birth_year)+ ";" + std::to_string(this->sex);

        QString class_str_1 = QString::fromStdString(class_str);

        return class_str_1;
    }

    ~Employee();

};

class Student : public Employee
{

public:

    int degree;
    QString birth_place;

    Student();

   QString to_string() override
    {
        /* std::string class_str = std::to_string(this->num)+ ";" + this->full_name.toStdString()+ ";"\
                + std::to_string(this->birth_year)+ ";" + std::to_string(this->sex)+ ";" \
                + std::to_string(this ->degree)+ ";" + this->birth_place.toStdString()+ ";"; */

        std::string class_str = std::to_string(this->num)+ ";" + this->full_name.toStdString()+ ";"\
                + std::to_string(this->birth_year)+ ";" + std::to_string(this->sex)+ ";" \
                + "курс"+ ";" + "место рождения"+ ";";

        QString class_str_1 = QString::fromStdString(class_str);

        return class_str_1;
    }

    ~Student();
};

class Worker : Employee
{

public:

    Worker();

    int general_labour, salary; // Стаж, зарплата

   QString to_string() override
    {
        /* std::string class_str = std::to_string(this->num)+ ";" + this->full_name.toStdString()+ ";"\
                + std::to_string(this->birth_year) + std::to_string(this->sex) \
                + std::to_string(this ->general_labour) + std::to_string(this ->salary); */

       std::string class_str = std::to_string(this->num)+ ";" + this->full_name.toStdString()+ ";"\
                       + std::to_string(this->birth_year) + std::to_string(this->sex) + ";"\
                       + "стаж" + ";"+ "зарплата";

        QString class_str_1 = QString::fromStdString(class_str);

        return class_str_1;
    }

    ~Worker();

};

class Teacher : Employee
{

public:

    Teacher();

    int teaching_exp;
    QString post;

   QString to_string() override
    {
       /* std::string class_str = std::to_string(this->num)+ ";" + this->full_name.toStdString()+ ";"\
                + std::to_string(this->birth_year)+ ";" + std::to_string(this->sex)+ ";" \
                + std::to_string(this ->teaching_exp) + this->post.toStdString(); */

        std::string class_str = std::to_string(this->num)+ ";" + this->full_name.toStdString()+ ";"\
                + std::to_string(this->birth_year)+ ";" + std::to_string(this->sex)+ ";" \
                + "опыт преподавания"+ ";" + "должность";

        QString class_str_1 = QString::fromStdString(class_str);

        return class_str_1;
    }

    ~Teacher();

};

#endif // EMPLOYEE_H
