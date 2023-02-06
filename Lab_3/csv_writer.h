#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <fstream>
#include <QString>
#include "Employee.h"
#include <vector>


class csv_writer
{
    std::ofstream class_file;

public:

    csv_writer(const QString &filename);
    bool if_open(){return class_file.is_open();};
    void Write_all(const std::vector<Employee>& class_all_employees);

    ~csv_writer();

};

#endif // CSV_WRITER_H
