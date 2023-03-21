#include <iostream>
#include <fstream>
#include "helper_function.h"
using namespace std;

string readInfoFromFileLineM2N(const string &filename, int begin, int end)
{
    string rawLine;
    string content;
    ifstream infile;
    infile.open(filename);
    for (int i = 0; i < begin;)
    {
        if (infile.get() == '\n')
            i++;
    }
    for (int i = begin; i < end; ++i)
    {
        getline(infile, rawLine);
        content += rawLine + "\n";
    }
    infile.close();
    return content;
}

// 检查数字是否超出范围
// template <class T>
// T CheckInputRange(T input, T min, string errorMsg, T max)
// {
//     if (input > max || input < min)
//     {
//         cout << errorMsg;
//         cin >> input;
//         input = CheckInputRange(input, min, errorMsg, max);
//     }
//     return input;
// }

int CheckInputRange(int input, int min, std::string errorMsg,
                    int max)
{
    if (input > max || input < min)
    {
        cout << errorMsg;
        cin >> input;
        input = CheckInputRange(input, min, errorMsg, max);
    }
    return input;
}

double CheckInputRange(double input, double min, std::string errorMsg,
                    double max)
{
    if (input > max || input < min)
    {
        cout << errorMsg;
        cin >> input;
        input = CheckInputRange(input, min, errorMsg, max);
    }
    return input;
}

int CheckIfNum(string input)
{
    int res;
    try
    {
        res = stoi(input);
    }
    catch (exception e)
    {
        cout << "输入的不是数字,请重新输入: ";
        cin >> input;
        res = CheckIfNum(input);
    }
    return res;
}

string StringInputInformationHelper(const string &requestInfo)
{
    cout << "请输入" << requestInfo << "信息：";
    string info;
    cin >> info;
    return info;
}

double DoubleInputInformationHelper(string requestInfo, double min, string errorMsg, double max)
{
    cout << "请输入" << requestInfo << "信息：";
    string info;
    double res;
    cin >> info;
    // check if double
    try
    {
        res = stod(info);
    }
    catch (const exception &)
    {
        cout << "输入的不是数字，请重新输入。" << endl;
        res = DoubleInputInformationHelper(requestInfo, min, errorMsg, max);
    }
    res = CheckInputRange(res, min, errorMsg, max);
    return res;
}

std::string GenRandom(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

void FormatDivision(const std::string &info, const char divisionChar, const int numOfDivChar)
{
    int len = info.length();
    int halfNumOfDiv = (numOfDivChar - len - 2) / 2;
    for (int i = 0; i < halfNumOfDiv; ++i)
    {
        cout << divisionChar;
    }
    cout << " " << info << " ";
    for (int i = 0; i < halfNumOfDiv; ++i)
    {
        cout << divisionChar;
    }
    cout << endl;
}

void fileEmpty(const string &fileName)
{
    fstream file(fileName, ios::out);
    return;
}