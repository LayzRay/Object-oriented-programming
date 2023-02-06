#include "csv_exception.h"

CSV_exception::CSV_exception(int line)
{
    this->line = line;
}

int CSV_exception::GetLine(){ return line;}
