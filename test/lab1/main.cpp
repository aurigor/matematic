#include <iostream>
#include "mymath/mymath.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    _vector<double> a(0, 10); // Инициализация вектора размером 10
    _vector<double> b(0, 10);

    for (int i = 0; i < 10; ++i)
    {
        a[i] = i * i;
        b[i] = -i;
    }

    cout << "a is ";
    a.print();

    cout << "b is ";
    b.print();

    // Складываем векторы a и b
    _vector<double> c = a + b;
    cout << "c (a + b) is ";
    c.print();

    // Вычитаем векторы a и b
    _vector<double> c1 = a - b;
    cout << "c1 (a - b) is ";
    c1.print();

    // Поэлементное умножение векторов a и b
    _vector<double> c2 = a * b;
    cout << "c2 (a * b) is ";
    c2.print();

    // Скалярное произведение векторов a и b
    double scalar_product_result = a.scalar_product(b);
    cout << "Scalar product of a and b is " << scalar_product_result << "\n";

    // Умножение вектора a на константу
    _vector<double> c3 = a * 2.0;
    cout << "c3 (a * 2.0) is ";
    c3.print();

    _vector<double> c4 = a * 2;
    cout << "c4 (a * 2.0) is ";
    c4.print();

    return 0;
}