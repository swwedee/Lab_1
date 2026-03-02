#include <iostream>
#include <fstream>
#include <string>
#include "Price.h"

using namespace std;

void addPrice(Price a, Price b, Price& result)
{
    result.hryvnia = a.hryvnia + b.hryvnia;
    result.kopiyka = a.kopiyka + b.kopiyka;

    if (result.kopiyka >= 100)
    {
        result.hryvnia++;
        result.kopiyka -= 100;
    }    
}

void multiplyPrice(Price a, int count, Price& result)
{
    result.hryvnia = a.hryvnia * count;
    result.kopiyka = a.kopiyka * count;

 if (result.kopiyka >= 100)
    {
        result.hryvnia++;
        result.kopiyka -= 100;
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
        a.hryvnia ++;
        a.kopiyka -= 100;
    }
}

void printPrice(Price a)
{
    cout << a.hryvnia << " грн " << a.kopiyka << " коп" << endl;
}

void runProgram()
{
    ifstream file("input.txt");

    Price total = {0, 0};

    string name;
    int grn;
    short int kop;
    int count;
    string temp;

    while (file >> name)
    {
       file >> name;
       file >> name;

       file >> grn;
       file >> name;
       file >> kop;
       file >> name;
       file >> count;
       file >> name;

        Price one = {grn, kop};
        Price multiplied = {0, 0};
        

        multiplyPrice(one, count, multiplied);
        addPrice(total, multiplied,total);
    }

    file.close();

    cout << "Загальна сума: ";
    printPrice(total);

    roundPrice(total);

    cout << "Сума до оплати (після заокруглення): ";
    printPrice(total);
}