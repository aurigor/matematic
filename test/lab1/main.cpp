#include <iostream>
#include "mymath/mymath.h"




double square(double x)
{
    return x * x;  // Возвращает x^2
}

double difference(double x, double y)
{
    return y * y - x * x;  // Возвращает y^2 - x^2
}

double customFunction(double x, double y, double z)
{
    return x * y + z;  // Пример произвольной функции с тремя аргументами
}


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
    _matrix<double> mult1 = mat11 * mat22;
    _matrix<double> sum1 = mat11 + mat22;
    cout << "\nРазность матриц 11 и 22:\n";
    diff1.print();
    mat11.print();
    mat22.print();

    //Function f1([](double& x) { return x * x; });
    //Function f1(square);
    //Function f2([](double x, double y) { return y * y - x * x; });  // y^2 - x^2
    //Function f3([](double x, double y, double z) { return x * y + z; });
    //Function f1(square);                      // f1 представляет x^2
    //Function f2(difference);                  // f2 представляет y^2 - x^2
    //Function f3(customFunction);              // f3 представляет x*y + z

    // Используем функции
    double x = 3.0;
    double y = 4.0;
    double z = 5.0;

    //cout << "f1(" << x << ") = " << f1(x) << endl;            // Вычисляет f1(3.0) = 9.0
    //cout << "f2(" << x << ", " << y << ") = " << f2(x, y) << endl;  // Вычисляет f2(3.0, 4.0) = 7.0
    //cout << "f3(" << x << ", " << y << ", " << z << ") = " << f3(x, y, z) << endl;  // Вычисляет f3(3.0, 4.0, 5.0) = 17.0
#define inline_function(params) \
class \
{ \
    public: void operator() (params)\
    {\

#define with_name(value) \
    }\
} value;

#define with_params(...) __VA_ARGS__ // А это-то зачем тут? Читай ниже.


        inline_function(with_params(int a, int b))
        {
            printf("%d+%d=%d\n", a, b, a + b);
        } with_name(plus);

        plus(2, 2);

#define inline_funct(params) \
class \
{ \
    public: double operator() (params)\
    {\

#define with_name(value) \
    }\
} value;

#define with_params(...) __VA_ARGS__ // А это-то зачем тут? Читай ниже.


        inline_funct(with_params(double a, double b))
        {
            return a + b;
        } with_name(plus1);

        cout<<"\n sum = "<<plus1(2, 2)<<endl;

        inline_funct(with_params(double x))
        {
            return x * x;
        }with_name(squars)
            //Function f1(squars);
            //_vector<inline_funct(with_params(double, double))> a;
            function asd = square;
            Function a(asd);
            cout << "f1(" << x << ") = " << a(x) << endl;
    return 0;
}