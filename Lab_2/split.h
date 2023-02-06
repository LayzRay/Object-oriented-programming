#ifndef SPLIT_H
#define SPLIT_H

#include <QString>
#include <string>
#include <vector>

using namespace std;

vector<QString> split(const string& str, char delim)
{
    vector<QString> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(QString::fromStdString(str.substr(start, (end - start))));

            start = end + 1;
        } while (end != string::npos);
    }

    return tokens;
}

#endif // SPLIT_H
