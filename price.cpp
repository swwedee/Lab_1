#include "Price.h"

void Price::add(Price other)
{
    hryvnia += other.hryvnia;
    kopiyka += other.kopiyka;

    if (kopiyka >= 100)
    {
        hryvnia += kopiyka / 100;
        kopiyka = kopiyka % 100;
    }
}

void Price::multiply(int number)
{
    int totalKop = hryvnia * 100 + kopiyka;
    totalKop = totalKop * number;

    hryvnia = totalKop / 100;
    kopiyka = totalKop % 100;
}

void Price::round()
{
    // округлення до 10 копійок
    if (kopiyka % 10 >= 5)
        kopiyka = kopiyka + (10 - kopiyka % 10);
    else
        kopiyka = kopiyka - (kopiyka % 10);

    if (kopiyka >= 100)
    {
        hryvnia++;
        kopiyka -= 100;
    }
}

void Price::print()
{
    std::cout << hryvnia << " грн " << kopiyka << " коп" << std::endl;
}