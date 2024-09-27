#include <iostream>
#include "mymath/mymath.h"
#include "math.h"
#include <fstream>
#include <cstdlib> // ��� system()
#include <cstdio>    // ��� _popen � _pclose
#include <memory>
#include <sstream>
//#include <gnuplot-iostream.h>

FILE* gnuplotPipe;
void openGnuplot()
{
    gnuplotPipe = _popen("gnuplot -persist", "w");
    if (!gnuplotPipe)
    {
        std::cerr << "������: �� ������� ������� Gnuplot." << std::endl;
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

    // ������������ ������ ��� gnuplot
    std::ostringstream commands;

    commands << "set title 'Cubic Spline vs. Original Points'\n";
    commands << "set xlabel 'X'\n";
    commands << "set ylabel 'Y'\n";
    commands << "set grid\n";

    // ���������� ������� �������� �����
    commands << "$data << EOD\n";
    for (size_t i = 0; i < x.size(); ++i)
    {
        commands << x[i] << " " << y[i] << "\n";  // ���������� ����������� �����
    }
    commands << "EOD\n";

    // ���������� ������ ��� �������
    commands << "$spline << EOD\n";
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        commands << spline_x[i] << " " << spline_y[i] << "\n";  // ���������� ����������� �����
    }
    commands << "EOD\n";

    // ���������� �������: ������ � �����
    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";

    // ���������� ������� � gnuplot
    fprintf(gnuplotPipe, "%s", commands.str().c_str());

    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot
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
//    gp.send1d(boost::make_tuple(x, y));     // �������� ������������ ������
//    gp.send1d(boost::make_tuple(spline_x, spline_y)); // �������� ������ ������
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // ���������� ������� � gnuplot
//    std::ostream out(gnuplotPipe);
//    out << "set title 'Cubic Spline vs. Original Points'\n";
//    out << "set xlabel 'X'\n";
//    out << "set ylabel 'Y'\n";
//    out << "set grid\n";
//
//    // ���������� ������� �������� �����
//    out << "$data << EOD\n";
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        out << x[i] << " " << y[i] << "\n";
//    }
//    out << "EOD\n";
//
//    // ���������� ������ ��� �������
//    out << "$spline << EOD\n";
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        out << spline_x[i] << " " << spline_y[i] << "\n";
//    }
//    out << "EOD\n";
//
//    // ���������� �������: ������ � �����
//    out << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
//    out << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";
//
//    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // ���������� ������� � gnuplot
//    fprintf(gnuplotPipe, "set title 'Cubic Spline vs. Original Points'\n");
//    fprintf(gnuplotPipe, "set xlabel 'X'\n");
//    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
//    fprintf(gnuplotPipe, "set grid\n");
//
//    // ���������� ������� �������� �����
//    fprintf(gnuplotPipe, "$data << EOD\n");
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%e %e\n", x[i], y[i]);
//        printf("%e %e\n", x[i], y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // ���������� ������ ��� �������
//    fprintf(gnuplotPipe, "$spline << EOD\n");
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%f %f\n", spline_x[i], spline_y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // ���������� �������: ������ � �����
//    fprintf(gnuplotPipe, "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n");
//    fprintf(gnuplotPipe, "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n");
//
//    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // ���������� ������� � gnuplot
//    fprintf(gnuplotPipe, "set title 'Cubic Spline vs. Original Points'\n");
//    fprintf(gnuplotPipe, "set xlabel 'X'\n");
//    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
//    fprintf(gnuplotPipe, "set grid\n");
//
//    // ���������� ������� �������� �����
//    fprintf(gnuplotPipe, "$data << EOD\n");
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%f %f\n", x[i], y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // ���������� ������ ��� �������
//    fprintf(gnuplotPipe, "$spline << EOD\n");
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        fprintf(gnuplotPipe, "%f %f\n", spline_x[i], spline_y[i]);
//    }
//    fprintf(gnuplotPipe, "EOD\n");
//
//    // ���������� �������: ������ � �����
//    fprintf(gnuplotPipe, "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n");
//    fprintf(gnuplotPipe, "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n");
//
//    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot
//}
double square(double x)
{
    return x * x;  // ���������� x^2
}

double difference(double x, double y)
{
    return y * y - x * x;  // ���������� y^2 - x^2
}

double customFunction(double x, double y, double z)
{
    return x * y + z;  // ������ ������������ ������� � ����� �����������
}
double twoe1(double x, double y)
{
    return y * y - x * x;  // ���������� y^2 - x^2
}
double twoe2(double x, double y)
{
    return y * y - x * x-10;  // ���������� y^2 - x^2
}
double twoe3(double x, double y)
{
    return y * y - x * x*x;  // ���������� y^2 - x^2
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //// ������ ������: �������� �����
    //std::vector<double> x = { 0, 1, 2, 3, 4, 5 };
    //std::vector<double> y = { 0, 1, 4, 9, 16, 25 };

    //// ������ ������: �������� ������� (��� �������� ����� �������� �� ������ ������ `_spline`)
    //std::vector<double> spline_x = { 0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5 };
    //std::vector<double> spline_y = { 0, 0.5, 1, 2.5, 4, 6.5, 9, 12.5, 16, 20.5, 25 };


    //std::vector<double> x = { 0, 1, 2, 3, 4, 5 };
    //std::vector<double> y = { 0, 1, 4, 9, 16, 25 };  // �������� ��� �����

    //_spline<double> mySpline(0.0, 5.0, x.size(), [](double x)
    //    {
    //        return x * x; // ���������� ������� y = x^2 ��� �����
    //    });

    //// ��������� ������ ��� ���������� �������
    //std::vector<double> spline_x, spline_y;
    //mySpline.generateSplineData(spline_x, spline_y);
    auto func = [](double x) { return std::exp(x); };
    _spline<double> mySpline(0.0, 5.0, 6, func);
    //mySpline.printSplinePoints();
    // ��������� ������ ��� ���������� �������
    std::vector<double> spline_x, spline_y;
    mySpline.generateSplineData(spline_x, spline_y,101);
    std::cout << "Spline data:" << std::endl;
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        std::cout << spline_x[i] << " " << spline_y[i] << std::endl;
    }
    // �������� gnuplot
    openGnuplot();
    std::vector<double>xs = mySpline.getX();
    std::vector<double>ys = mySpline.getY();
    std::cout << "Spline data:" << std::endl;
    for (size_t i = 0; i < xs.size(); ++i)
    {
        std::cout << xs[i] << " " << ys[i] << std::endl;
    }
    
    // ���������� ������� � ��������� ������� � ���������� �������
    //plotSplineWithPoints(x, y, spline_x, spline_y);
    plotSplineWithPoints(mySpline.getX(), mySpline.getY(), spline_x, spline_y);

    std::cout << "������� ����� �������, ����� ������� gnuplot..." << std::endl;
    std::cin.get();  // �������, ���� ������������ ������ �������

    // �������� gnuplot
    closeGnuplot();

    return 0;
}

//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    _spline<double> spline;
//
//    // ��������� ����� (����) ��� ���������� �������
//    spline.add_point(0.0, 0.0);
//    spline.add_point(1.0, 2.0);
//    spline.add_point(2.0, 3.0);
//    spline.add_point(3.0, 2.0);
//    spline.add_point(4.0, 0.0);
//
//    // ������ ������
//    spline.build_spline();
//
//    // ��������� ���������� � ����
//    std::ofstream file("spline_data.txt");
//    if (!file.is_open())
//    {
//        std::cerr << "�� ������� ������� ���� ��� ������ ������.\n";
//        return 1;
//    }
//
//    // ���������� �������� ������� � ���� � ����� 0.1
//    for (double x = 0.0; x <= 4.0; x += 0.1)
//    {
//        file << x << " " << spline.get_value(x) << "\n";
//    }
//    file.close();
//
//    // ��������� gnuplot ��� ����������� ������
//    std::string gnuplot_command = "gnuplot -e \"set terminal png; set output 'spline.png'; plot 'spline_data.txt' with lines title 'Cubic Spline'\"";
//    std::system(gnuplot_command.c_str());
//
//    std::cout << "������ �������� � �������� � 'spline.png'.\n";
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
//    cout << "������������ �������:\n";
//    spline.print_spline();
//
//
//    cout << "\n�������� ������� � ������������� ������:\n";
//    for (double x = 0.0; x <= 4.0; x += 0.5)
//    {
//        double y = spline.get_value(x);
//        cout << "spline(" << x << ") = " << y << endl;
//    }
////
////    // ������� ��� ������� 3x3
////    _matrix<double> mat1(2.0, 3, 3);
////    _matrix<double> mat2(1.0, 3, 3);
////
////    // �������������� �������� ������
////    for (int i = 0; i < 3; ++i)
////    {
////        for (int j = 0; j < 3; ++j)
////        {
////            mat1(i, j) = i + j;   // mat1 = [[0, 1, 2], [1, 2, 3], [2, 3, 4]]
////            mat2(i, j) = i - j;   // mat2 = [[0, -1, -2], [1, 0, -1], [2, 1, 0]]
////        }
////    }
////
////    cout << "������� 1:\n";
////    mat1.print();
////
////    cout << "\n������� 2:\n";
////    mat2.print();
////
////    // �������� �������� ������
////    _matrix<double> sum = mat1 + mat2;
////    cout << "\n����� ������ 1 � 2:\n";
////    sum.print();
////
////    // �������� ��������� ������
////    _matrix<double> diff = mat1 - mat2;
////    cout << "\n�������� ������ 1 � 2:\n";
////    diff.print();
////
////    // �������� ��������� ������
////    _matrix<double> prod = mat1 * mat2;
////    cout << "\n������������ ������ 1 � 2:\n";
////    prod.print();
////
////    // ��������� ������� �� ���������
////    _matrix<double> scalarProd = mat1 * 3.0;
////    cout << "\n��������� ������� 1 �� 3.0:\n";
////    scalarProd.print();
////
////
////
////    _matrix<double> mat11(2.0, 2, 2);
////    _matrix<double> mat22(1.0, 3, 3);
////    _matrix<double> diff1 = mat11 - mat22;
////    _matrix<double> mult1 = mat11 * mat22;
////    _matrix<double> sum1 = mat11 + mat22;
////    cout << "\n�������� ������ 11 � 22:\n";
////    diff1.print();
////    mat11.print();
////    mat22.print();
////
////    //Function f1([](double& x) { return x * x; });
////    //Function f1(square);
////    //Function f2([](double x, double y) { return y * y - x * x; });  // y^2 - x^2
////    //Function f3([](double x, double y, double z) { return x * y + z; });
////    //Function f1(square);                      // f1 ������������ x^2
////    //Function f2(difference);                  // f2 ������������ y^2 - x^2
////    //Function f3(customFunction);              // f3 ������������ x*y + z
////
////    // ���������� �������
////    double x = 3.0;
////    double y = 4.0;
////    double z = 5.0;
////
////    //cout << "f1(" << x << ") = " << f1(x) << endl;            // ��������� f1(3.0) = 9.0
////    //cout << "f2(" << x << ", " << y << ") = " << f2(x, y) << endl;  // ��������� f2(3.0, 4.0) = 7.0
////    //cout << "f3(" << x << ", " << y << ", " << z << ") = " << f3(x, y, z) << endl;  // ��������� f3(3.0, 4.0, 5.0) = 17.0
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
////#define with_params(...) __VA_ARGS__ // � ���-�� ����� ���? ����� ����.
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
////#define with_params(...) __VA_ARGS__ // � ���-�� ����� ���? ����� ����.
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