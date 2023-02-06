#ifndef CSV_EXCEPTION_H
#define CSV_EXCEPTION_H


#include <iostream>


using namespace std;


class CSV_exception : public exception
{
public:
    CSV_exception(int line);
    int GetLine();

private:
    int line;
};

#endif // CSV_EXCEPTION_H
