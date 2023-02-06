#ifndef CSV_READER_H
#define CSV_READER_H

#include <QString>
#include <fstream>
#include <vector>
#include "Employee.h"

class CSV_reader
{
    std::ifstream class_file;

public:

    CSV_reader(const QString &filename);

    bool if_open(){return class_file.is_open();};
    std::vector<Employee> read_all();

    ~CSV_reader();
};

#endif // CSV_READER_H
