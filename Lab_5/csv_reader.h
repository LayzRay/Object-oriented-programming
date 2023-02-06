#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <vector>
#include "employee.h"
#include "json.hpp"


class Abstract_reader
{
public:

    std::ifstream class_file;

    virtual  std::vector<Employee> read_all() = 0;
    virtual bool if_open() = 0;


    virtual ~Abstract_reader() = default;

};

class CSV_reader: public Abstract_reader
{

public:

    CSV_reader (const QString &filename); // Конструктор

    virtual std::vector<Employee> read_all() override;
    virtual bool if_open() override {return class_file.is_open();};

    CSV_reader(const Abstract_reader &other) = delete; // ?
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

    //~CSV_reader();
};

class JSON_reader: public Abstract_reader
{
public:

    JSON_reader (const QString &filename); // Конструктор

    virtual std::vector<Employee> read_all() override;
    virtual bool if_open() override {return class_file.is_open();};

    JSON_reader(const JSON_reader &other) = delete; // ?
    JSON_reader& operator = (const JSON_reader &other) = delete; // Для чего нужен &?

    JSON_reader (JSON_reader &&other) // Два &?
    {
        this -> class_file = std:: move(other.class_file);
        other.class_file.close();
    }

    JSON_reader& operator = (JSON_reader &&other)
    {

        this -> class_file.close();
        this -> class_file = std:: move(other.class_file);
        other.class_file.close();

    }

    //~JSON_reader();
};

#endif // CSV_READER_H
