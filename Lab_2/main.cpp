#include "mainwindow.h"

#include <QApplication>

#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::fstream file("Data base.csv", std::fstream::out); // Открытие потока данных файла для записи

        // Запись данных в файл:

        file << 1 << ";" << "Golev Andrey Dmitrievich" << ";" << "2001" << ";" << 0 << std::endl;
        file << 2 << ";" << "Tsipkin Alexander Petrovich" << ";" << "1980" << ";" << 0 << std::endl;
        file << 3 << ";" << "Lavrova Anna Vladimirovna" << ";" << "1999" << ";" << 1;

        file.close();



    return a.exec();
}
