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





    // Создаем две матрицы 3x3
    _matrix<double> mat1(2.0, 3, 3);
    _matrix<double> mat2(1.0, 3, 3);

    // Инициализируем элементы матриц
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mat1(i, j) = i + j;   // mat1 = [[0, 1, 2], [1, 2, 3], [2, 3, 4]]
            mat2(i, j) = i - j;   // mat2 = [[0, -1, -2], [1, 0, -1], [2, 1, 0]]
        }
    }

    cout << "Матрица 1:\n";
    mat1.print();

    cout << "\nМатрица 2:\n";
    mat2.print();

    // Операция сложения матриц
    _matrix<double> sum = mat1 + mat2;
    cout << "\nСумма матриц 1 и 2:\n";
    sum.print();

    // Операция вычитания матриц
    _matrix<double> diff = mat1 - mat2;
    cout << "\nРазность матриц 1 и 2:\n";
    diff.print();

    // Операция умножения матриц
    _matrix<double> prod = mat1 * mat2;
    cout << "\nПроизведение матриц 1 и 2:\n";
    prod.print();

    // Умножение матрицы на константу
    _matrix<double> scalarProd = mat1 * 3.0;
    cout << "\nУмножение матрицы 1 на 3.0:\n";
    scalarProd.print();

   

    _matrix<double> mat11(2.0, 2, 2);
    _matrix<double> mat22(1.0, 3, 3);
    _matrix<double> diff1 = mat11 - mat22;
    cout << "\nРазность матриц 11 и 22:\n";
    diff1.print();
    mat11.print();
    mat22.print();

    return 0;
}