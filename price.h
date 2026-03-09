#ifndef PRICE_H
#define PRICE_H

struct Price
{
    int hryvnia;
    short int kopiyka;
};


void addPrice(Price a, Price b, Price& result);
void multiplyPrice(Price a, int count, Price& result);
void roundPrice(Price& a);
void printPrice(Price a);


void runProgram();

#endif
