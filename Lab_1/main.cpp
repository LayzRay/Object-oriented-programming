/*

    Разработать программу, которая считывает из текстового файла
    массив записей (в формате CSV), выводит информацию о нём на экран,
    сортирует его и сохраняет в другой файл.

    Записи о сотрудниках: номер записи, ФИО, год рождения, пол (из
    перечисления enum). Сортировка по году рождения. Вывести всех сотрудников
    старше 31 года.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> split( const string& str, char delim )
{
    vector <string> tokens;

    if ( !str.empty() )
    {
        size_t start = 0, end;
        do {

            end = str.find( delim, start );
            tokens.push_back(str.substr( start, (end - start) ) );

            start = end + 1;
        } while ( end != string::npos );
    }

    return tokens;
}

int main()
{
    setlocale( LC_ALL, "Russian" );

    // Область определения:

    enum Sex { Man, Woman }; // Перечисляемый тип данных

    struct employee
    {
        int num, birth_year;
        string full_name;
        Sex sex;

    }	current_employee;


    vector <employee> all_employees; // Вектор данных всех сотрудников


    // Разобьём задачу на подзадачи:

    /* Создадим файл csv, в котором будут записи о сотрудниках.
     Данные будут разделяться символом ";". */

    fstream file( "Data base.csv", fstream::out ); // Открытие потока данных файла для записи

    // Запись данных в файл:

    file << 1 << ";" << "Morozova Tatjana Vladimirovna" << ";" << "1970" << ";" << 1 << endl;
    file << 2 << ";" << "Golev Andrey Dmitrievich" << ";" << "2001" << ";" << 0 << endl;
    file << 3 << ";" << "Ivanov Ivan Yulianovich" << ";" << "1980" << ";" << 0;

    file.close();
    file.open( "Data base.csv", fstream::in );// Открытие потока данных файла для чтение

    // Далее будем считывать файл:

    while ( !file.eof() ) // Цикл будет идти, пока не достигнет конца файла
    {
        string line; // Создаём буферную строку, с которой в дальнейшем будем работать
        getline(file, line);

        vector <string>  parts_of_the_line = split( line, ';' ); // Создаём вектор с частями строки, разделённых символом ";"

        current_employee.num = stoi( parts_of_the_line[0] ); // Преобразование из String в Int;
        current_employee.full_name = parts_of_the_line[1];
        current_employee.birth_year = stoi( parts_of_the_line[2] );
        current_employee.sex = static_cast <Sex>( stoi( parts_of_the_line[3] ) ); // Преобразование номера пола в число, затем в перечисляемый тип

        all_employees.push_back( current_employee ); // Заносим данные сотрудника в вектор всех сотрудников
    }

    file.close(); // Файл проанализирован, все строки прочитаны, закрываем файл

    // Выводим на экран данные всех сотрудников:

    cout << "All employees:\n\n";
    for ( const auto &e : all_employees )
        cout << e.num << ", " << e.full_name << ", " << e.birth_year << ", " << e.sex << endl;

    // Выводим на экран сотрудников, старше 31 года:
    bool flag = false;

    for ( const auto& e : all_employees )
    {
        if ( 2022- e.birth_year > 31 )
        {
            if ( flag == false )
            {
                cout << "\nEmployees over 31 years old:\n\n";
                flag = true;
            }
            cout << e.num << ";" << e.full_name << ";" << e.birth_year << ";" << e.sex << endl;
        }
    }
    if ( flag == false )
        cout << "\nAll employees are very young.\n";

    // Сортируем:

    sort( all_employees.begin(), all_employees.end(), []( const employee &e1, const employee &e2 )
        {
            return e1.birth_year > e2.birth_year;
        });

    cout << "\nSorted list:\n\n";
    for ( const auto& e : all_employees )
    {
       cout << e.num << ";" << e.full_name << ";" << e.birth_year << ";" << e.sex << endl;
    }

    fstream file_2( "New Data base.csv",fstream::out );

    // Запись отсортированных данных в новый файл:
    for ( const auto& e : all_employees )
    {
        file_2 << e.num << ";" << e.full_name << ";" << e.birth_year << ";" << e.sex << endl;
    }

    file_2.close();

    return 0;
}
