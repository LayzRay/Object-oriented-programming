#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include "my_text_class.h"

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

   friend bool operator < (const Employee& a, const Employee& b)
    {
        return a.birth_year < b.birth_year;
    }

   friend std::ostream& operator << (std::ostream& os, const Employee& a)
   {
       os << a.num << " " << a.full_name.toStdString() << " " << a.birth_year << " " << (a.sex == 0? "M":"W") << std::endl;
       return os;
   }


    ~Employee();

};

class Student : public Employee
{

public:

    int degree;
    QString birth_place;

    Student();

   virtual QString to_string() override
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

   virtual QString to_string() override
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

   virtual QString to_string() override
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
