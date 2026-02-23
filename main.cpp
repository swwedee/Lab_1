#include <iostream>
#include "Price.h"

int main()
{
    Price total;
    total.hryvnia = 0;
    total.kopiyka = 0;

    int n;

    std::cout << "Скільки товарів будете вводити? ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int hrn;
        short int kop;
        int count;

        std::cout << "\nТовар " << i + 1 << std::endl;
        std::cout << "Введіть гривні: ";
        std::cin >> hrn;

        std::cout << "Введіть копійки: ";
        std::cin >> kop;

        std::cout << "Введіть кількість: ";
        std::cin >> count;

        Price temp;
        temp.hryvnia = hrn;
        temp.kopiyka = kop;

        temp.multiply(count);
        total.add(temp);
    }

    std::cout << "\nЗагальна сума:" << std::endl;
    total.print();

    Price rounded = total;
    rounded.round();

    std::cout << "Сума до оплати (з округленням):" << std::endl;
    rounded.print();

    return 0;
}