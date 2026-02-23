#ifndef PRICE_H
#define PRICE_H

#include <iostream>

struct Price
{
    int hryvnia;
    short int kopiyka;

    void add(Price other);
    void multiply(int number);
    void round();
    void print();
};

#endif