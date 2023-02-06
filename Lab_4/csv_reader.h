#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <vector>
#include "employee.h"

class CSV_reader
{

public:

    std::ifstream class_file;

    CSV_reader(const QString &filename); // Конструктор

    CSV_reader(const CSV_reader &other) = delete; // ?
    CSV_reader& operator = (const CSV_reader &other) = delete; // Для чего нужен &?

    CSV_reader (CSV_reader &&other) // Два &?
    {
        this -> class_file = std:: move(other.class_file);
        other.class_file.close();
    }

    CSV_reader& operator = (CSV_reader &&other)
    {

        this -> class_file.close();
        this -> class_file = std:: move(other.class_file);
        other.class_file.close();

    }

    bool if_open(){return class_file.is_open();};
    std::vector<Employee> read_all();

    ~CSV_reader();
};

#endif // CSV_READER_H
