#include <iostream>
#include <fstream>
#include <string>
#include "Price.h"

using namespace std;

void addPrice(Price a, Price b, Price& result)
{
    result.hryvnia = a.hryvnia + b.hryvnia;
    result.kopiyka = a.kopiyka + b.kopiyka;

   result.hryvnia += result.kopiyka / 100;
    result.kopiyka %= 100;
}

void multiplyPrice(Price a, int count, Price& result)
{
    result.hryvnia = a.hryvnia * count;
    result.kopiyka = a.kopiyka * count;

    if (result.kopiyka >= 100)
    {
        result.hryvnia += result.kopiyka / 100;
        result.kopiyka = result.kopiyka % 100;
    }
}

void roundPrice(Price& a)
{
    int lastDigit = a.kopiyka % 10;

    if (lastDigit >= 8)
        a.kopiyka += (10 - lastDigit);
    else
        a.kopiyka -= lastDigit;

    if (a.kopiyka >= 100)
    {
        a.hryvnia += 1;
        a.kopiyka = 0;
    }
}

void printPrice(Price a)
{
    cout << a.hryvnia << " грн " << a.kopiyka << " коп" << endl;
}

void runProgram()
{
    ifstream file("input.txt");

    if (!file.is_open())
    {
        cout << "Файл не відкрився!" << endl;
        return;
    }

    Price total = {0, 0};

    string name;
    int grn;
    short int kop;
    int count;
    string temp;

    while (file >> name)
    {
        getline(file, temp, ',');

        file >> grn;
        file >> temp;
        file >> kop;
        file >> temp;
        file >> count;
        file >> temp;

        Price one = {grn, kop};
        Price multiplied = {0, 0};
        Price newTotal = {0, 0};

        multiplyPrice(one, count, multiplied);
        addPrice(total, multiplied, newTotal);

        total = newTotal;
    }

    file.close();

    cout << "Загальна сума: ";
    printPrice(total);

    roundPrice(total);

    cout << "Сума до оплати (після заокруглення): ";
    printPrice(total);
}