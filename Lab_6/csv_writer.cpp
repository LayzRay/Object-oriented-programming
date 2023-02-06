#include "csv_writer.h"
#include "employee.h"
#include <string>



csv_writer::csv_writer(const QString &filename)
{
    class_file.open(filename.toLatin1().data());
}

void csv_writer:: Write_all(std::vector<Employee> class_all_employees)
{
    for (const auto &e: class_all_employees)
        class_file << e.num << ";" << e.full_name.toStdString() << ";" << e.birth_year << ";" << e.sex << std::endl;
}

csv_writer::~csv_writer()
{
    class_file.close();
};
