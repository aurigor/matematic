#include <iostream>
#include "mymath/mymath.h"
#include "math.h"
#include <fstream>
#include <cstdlib> // Для system()
#include <cstdio>    // Для _popen и _pclose
#include <memory>
#include <sstream>
//#include <gnuplot-iostream.h>

FILE* gnuplotPipe;
void openGnuplot()
{
    gnuplotPipe = _popen("gnuplot -persist", "w");
    if (!gnuplotPipe)
    {
        std::cerr << "Ошибка: не удалось открыть Gnuplot." << std::endl;
        exit(1);
    }
}

void closeGnuplot()
{
    if (gnuplotPipe)
    {
        _pclose(gnuplotPipe);
    }
}
void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
{
    if (!gnuplotPipe) return;

    // Формирование команд для gnuplot
    std::ostringstream commands;

    commands << "set title 'Cubic Spline vs. Original Points'\n";
    commands << "set xlabel 'X'\n";
    commands << "set ylabel 'Y'\n";
    commands << "set grid\n";

    // Отправляем таблицу исходных точек
    commands << "$data << EOD\n";
    for (size_t i = 0; i < x.size(); ++i)
    {
        commands << x[i] << " " << y[i] << "\n";  // Используем стандартный вывод
    }
    commands << "EOD\n";

    // Отправляем данные для сплайна
    commands << "$spline << EOD\n";
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        commands << spline_x[i] << " " << spline_y[i] << "\n";  // Используем стандартный вывод
    }
    commands << "EOD\n";

    // Построение графика: сплайн и точки
    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";

    // Отправляем команды в gnuplot
    fprintf(gnuplotPipe, "%s", commands.str().c_str());

    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    Gnuplot gp;
//
//    gp << "set title 'Cubic Spline vs. Original Points'\n";
//    gp << "set xlabel 'X'\n";
//    gp << "set ylabel 'Y'\n";
//    gp << "set grid\n";
//
//    gp << "plot '-' with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', "
//        "'-' with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";
//
//    gp.send1d(boost::make_tuple(x, y));     // Отправка оригинальных данных
//    gp.send1d(boost::make_tuple(spline_x, spline_y)); // Отправка сплайн данных
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // Отправляем команды в gnuplot
//    std::ostream out(gnuplotPipe);
//    out << "set title 'Cubic Spline vs. Original Points'\n";
//    out << "set xlabel 'X'\n";
//    out << "set ylabel 'Y'\n";
//    out << "set grid\n";
//
//    // Отправляем таблицу исходных точек
//    out << "$data << EOD\n";
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        out << x[i] << " " << y[i] << "\n";
//    }
//    out << "EOD\n";
//
//    // Отправляем данные для сплайна
//    out << "$spline << EOD\n";
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        out << spline_x[i] << " " << spline_y[i] << "\n";
//    }
//    out << "EOD\n";
//
//    // Построение графика: сплайн и точки
//    out << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
//    out << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";
//
//    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // Отправляем команды в gnuplot
//    fprintf(gnuplotPipe, "set title 'Cubic Spline vs. Original Points'\n");
//    fprintf(gnuplotPipe, "set xlabel 'X'\n");
//    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
//    fprintf(gnuplotPipe, "set grid\n");
//
//    // Отправляем таблицу исходных точек
//    fprintf(gnuplotPipe, "$data << EOD\n");
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%e %e\n", x[i], y[i]);
//        printf("%e %e\n", x[i], y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // Отправляем данные для сплайна
//    fprintf(gnuplotPipe, "$spline << EOD\n");
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%f %f\n", spline_x[i], spline_y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // Построение графика: сплайн и точки
//    fprintf(gnuplotPipe, "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n");
//    fprintf(gnuplotPipe, "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n");
//
//    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // Отправляем команды в gnuplot
//    fprintf(gnuplotPipe, "set title 'Cubic Spline vs. Original Points'\n");
//    fprintf(gnuplotPipe, "set xlabel 'X'\n");
//    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
//    fprintf(gnuplotPipe, "set grid\n");
//
//    // Отправляем таблицу исходных точек
//    fprintf(gnuplotPipe, "$data << EOD\n");
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%f %f\n", x[i], y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // Отправляем данные для сплайна
//    fprintf(gnuplotPipe, "$spline << EOD\n");
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%f %f\n", spline_x[i], spline_y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // Построение графика: сплайн и точки
//    fprintf(gnuplotPipe, "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n");
//    fprintf(gnuplotPipe, "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n");
//
//    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
//}
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
double twoe1(double x, double y)
{
    return y * y - x * x;  // Возвращает y^2 - x^2
}
double twoe2(double x, double y)
{
    return y * y - x * x-10;  // Возвращает y^2 - x^2
}
double twoe3(double x, double y)
{
    return y * y - x * x*x;  // Возвращает y^2 - x^2
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //// Пример данных: исходные точки
    //std::vector<double> x = { 0, 1, 2, 3, 4, 5 };
    //std::vector<double> y = { 0, 1, 4, 9, 16, 25 };

    //// Пример данных: значения сплайна (эти значения можно получить из вашего класса `_spline`)
    //std::vector<double> spline_x = { 0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5 };
    //std::vector<double> spline_y = { 0, 0.5, 1, 2.5, 4, 6.5, 9, 12.5, 16, 20.5, 25 };


    //std::vector<double> x = { 0, 1, 2, 3, 4, 5 };
    //std::vector<double> y = { 0, 1, 4, 9, 16, 25 };  // Парабола для теста

    //_spline<double> mySpline(0.0, 5.0, x.size(), [](double x)
    //    {
    //        return x * x; // Используем функцию y = x^2 для теста
    //    });

    //// Генерация данных для построения графика
    //std::vector<double> spline_x, spline_y;
    //mySpline.generateSplineData(spline_x, spline_y);
    auto func = [](double x) { return std::exp(x); };
    _spline<double> mySpline(0.0, 5.0, 6, func);
    //mySpline.printSplinePoints();
    // Генерация данных для построения графика
    std::vector<double> spline_x, spline_y;
    mySpline.generateSplineData(spline_x, spline_y,101);
    std::cout << "Spline data:" << std::endl;
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        std::cout << spline_x[i] << " " << spline_y[i] << std::endl;
    }
    // Открытие gnuplot
    openGnuplot();
    std::vector<double>xs = mySpline.getX();
    std::vector<double>ys = mySpline.getY();
    std::cout << "Spline data:" << std::endl;
    for (size_t i = 0; i < xs.size(); ++i)
    {
        std::cout << xs[i] << " " << ys[i] << std::endl;
    }
    
    // Построение графика с исходными точками и значениями сплайна
    //plotSplineWithPoints(x, y, spline_x, spline_y);
    plotSplineWithPoints(mySpline.getX(), mySpline.getY(), spline_x, spline_y);

    std::cout << "Нажмите любую клавишу, чтобы закрыть gnuplot..." << std::endl;
    std::cin.get();  // Ожидаем, пока пользователь нажмет клавишу

    // Закрытие gnuplot
    closeGnuplot();

    return 0;
}

//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    _spline<double> spline;
//
//    // Добавляем точки (узлы) для построения сплайна
//    spline.add_point(0.0, 0.0);
//    spline.add_point(1.0, 2.0);
//    spline.add_point(2.0, 3.0);
//    spline.add_point(3.0, 2.0);
//    spline.add_point(4.0, 0.0);
//
//    // Строим сплайн
//    spline.build_spline();
//
//    // Сохраняем результаты в файл
//    std::ofstream file("spline_data.txt");
//    if (!file.is_open())
//    {
//        std::cerr << "Не удалось открыть файл для записи данных.\n";
//        return 1;
//    }
//
//    // Записываем значения сплайна в файл с шагом 0.1
//    for (double x = 0.0; x <= 4.0; x += 0.1)
//    {
//        file << x << " " << spline.get_value(x) << "\n";
//    }
//    file.close();
//
//    // Запускаем gnuplot для отображения данных
//    std::string gnuplot_command = "gnuplot -e \"set terminal png; set output 'spline.png'; plot 'spline_data.txt' with lines title 'Cubic Spline'\"";
//    std::system(gnuplot_command.c_str());
//
//    std::cout << "График построен и сохранен в 'spline.png'.\n";
//    return 0;
//}
 

//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    //test::tVector();
//
//    _spline<double> spline;
//
//    spline.add_point(0.0, 0.0);
//    spline.add_point(1.0, 2.0);
//    spline.add_point(2.0, 3.0);
//    spline.add_point(3.0, 2.0);
//    spline.add_point(4.0, 0.0);
//
//    spline.build_spline();
//
//    cout << "Коэффициенты сплайна:\n";
//    spline.print_spline();
//
//
//    cout << "\nЗначения сплайна в промежуточных точках:\n";
//    for (double x = 0.0; x <= 4.0; x += 0.5)
//    {
//        double y = spline.get_value(x);
//        cout << "spline(" << x << ") = " << y << endl;
//    }
////
////    // Создаем две матрицы 3x3
////    _matrix<double> mat1(2.0, 3, 3);
////    _matrix<double> mat2(1.0, 3, 3);
////
////    // Инициализируем элементы матриц
////    for (int i = 0; i < 3; ++i)
////    {
////        for (int j = 0; j < 3; ++j)
////        {
////            mat1(i, j) = i + j;   // mat1 = [[0, 1, 2], [1, 2, 3], [2, 3, 4]]
////            mat2(i, j) = i - j;   // mat2 = [[0, -1, -2], [1, 0, -1], [2, 1, 0]]
////        }
////    }
////
////    cout << "Матрица 1:\n";
////    mat1.print();
////
////    cout << "\nМатрица 2:\n";
////    mat2.print();
////
////    // Операция сложения матриц
////    _matrix<double> sum = mat1 + mat2;
////    cout << "\nСумма матриц 1 и 2:\n";
////    sum.print();
////
////    // Операция вычитания матриц
////    _matrix<double> diff = mat1 - mat2;
////    cout << "\nРазность матриц 1 и 2:\n";
////    diff.print();
////
////    // Операция умножения матриц
////    _matrix<double> prod = mat1 * mat2;
////    cout << "\nПроизведение матриц 1 и 2:\n";
////    prod.print();
////
////    // Умножение матрицы на константу
////    _matrix<double> scalarProd = mat1 * 3.0;
////    cout << "\nУмножение матрицы 1 на 3.0:\n";
////    scalarProd.print();
////
////
////
////    _matrix<double> mat11(2.0, 2, 2);
////    _matrix<double> mat22(1.0, 3, 3);
////    _matrix<double> diff1 = mat11 - mat22;
////    _matrix<double> mult1 = mat11 * mat22;
////    _matrix<double> sum1 = mat11 + mat22;
////    cout << "\nРазность матриц 11 и 22:\n";
////    diff1.print();
////    mat11.print();
////    mat22.print();
////
////    //Function f1([](double& x) { return x * x; });
////    //Function f1(square);
////    //Function f2([](double x, double y) { return y * y - x * x; });  // y^2 - x^2
////    //Function f3([](double x, double y, double z) { return x * y + z; });
////    //Function f1(square);                      // f1 представляет x^2
////    //Function f2(difference);                  // f2 представляет y^2 - x^2
////    //Function f3(customFunction);              // f3 представляет x*y + z
////
////    // Используем функции
////    double x = 3.0;
////    double y = 4.0;
////    double z = 5.0;
////
////    //cout << "f1(" << x << ") = " << f1(x) << endl;            // Вычисляет f1(3.0) = 9.0
////    //cout << "f2(" << x << ", " << y << ") = " << f2(x, y) << endl;  // Вычисляет f2(3.0, 4.0) = 7.0
////    //cout << "f3(" << x << ", " << y << ", " << z << ") = " << f3(x, y, z) << endl;  // Вычисляет f3(3.0, 4.0, 5.0) = 17.0
////#define inline_function(params) \
////class \
////{ \
////    public: void operator() (params)\
////    {\
////
////#define with_name(value) \
////    }\
////} value;
////
////#define with_params(...) __VA_ARGS__ // А это-то зачем тут? Читай ниже.
////
////
////    inline_function(with_params(int a, int b))
////    {
////        printf("%d+%d=%d\n", a, b, a + b);
////    } with_name(plus);
////
////    plus(2, 2);
////
////#define inline_funct(params) \
////class \
////{ \
////    public: double operator() (params)\
////    {\
////
////#define with_name(value) \
////    }\
////} value;
////
////#define with_params(...) __VA_ARGS__ // А это-то зачем тут? Читай ниже.
////
////
////    inline_funct(with_params(double a, double b))
////    {
////        return a + b;
////    } with_name(plus1);
////
////    cout << "\n sum = " << plus1(2, 2) << endl;
////
////    inline_funct(with_params(double x))
////    {
////        return x * x;
////    }with_name(squars)
////        //Function f1(squars);
////        //_vector<inline_funct(with_params(double, double))> a;
////        /*function asd = square;
////        Function a(asd);
////        cout << "f1(" << x << ") = " << a(x) << endl;*/
////
////        //Function f1([](double x) { return square(x); });
////    //std::cout << "f1(" << x << ") = " << f1(x) << std::endl;
////    //Function f2([](double x, double y) { return difference(x, y); });
////   // std::cout << "f2(" << x << ", " << y << ") = " << f2(x, y) << std::endl;
////    //cout << "\ntFunct = " << tFunct<double>(x, y, z) << endl;
////    tfunct1 = square;
////    cout << "\ntFunct = " << tfunct1(x)<< endl;
////
////    //Fun<double, double> obj(square);
////    //auto obj = Fun<double, double>(square);
////    _function obj(tfunct1);
////    /*Fun<double, double> obj();
////    obj.set(tfunct1);*/
////    cout << "\nobj = " << obj(x) << endl;
////    //Fun obj1(difference);
////    //auto perefod = square;
////    tfunct2 = difference;
////    _function obj1(tfunct2);
////    cout << "\nobj1 = " << obj1(x, y) << endl;
////
////    //Fun<double,(double,double)> obj2;
////    _function<double, double, double> obj2;
////    obj2.set(difference);
////    cout << "\nobj2 = " << obj2(x, y) << endl;
////
////
////    _function<double, double, double> obj3(difference);
////    cout << "\nobj3 = " << obj3(x, y) << endl;
////
////    //_vector<_function<double, double, double>> vfun;
////    _vector<_function<double, double, double>> vfun(_function<double, double, double>(), 3);
////    vfun[0].set(difference);
////    vfun[1].set([](double x, double y) { return sin(x) + cos(y); });
////    vfun[2].set([](double x, double y) { return pow(x,3) + cos(y); });
////    cout << endl;
////    for (int i = 0; i < 3; ++i)
////    {
////        cout << "vfun[" << i << "](" << x << ", " << y << ") =" << vfun[i](x,y) << endl;
////    }
////    //_vector<_function> vfun;
////    //Fun obj(tfunct1);
//    return 0;
//}