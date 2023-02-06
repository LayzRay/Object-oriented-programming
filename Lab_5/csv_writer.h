#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <fstream>
#include <QString>
#include "employee.h"
#include <vector>


class csv_writer
{
    std::ofstream class_file;

public:

    csv_writer(const QString &filename);
    bool if_open(){return class_file.is_open();};
    void Write_all(std::vector<Employee> class_all_employees);

    csv_writer(const csv_writer &other) = delete; // ?
   csv_writer& operator = (const csv_writer &other) = delete; // Для чего нужен &?

    csv_writer (csv_writer &&other) // Два &?
    {
        this -> class_file = std:: move(other.class_file);
        other.class_file.close();
    }

    csv_writer& operator = (csv_writer &&other)
    {

        this -> class_file.close();
        this -> class_file = std:: move(other.class_file);
        other.class_file.close();

    }


    ~csv_writer();

};

#endif // CSV_WRITER_H
