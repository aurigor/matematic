#ifndef SPLINE
#define SPLINE

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include"funct.h"
#include"array.h"
#include"methods.h"

using namespace std;

double zeros(double x)
{
    return 0.0;
}


class _splineSlay {
public:
    _splineSlay(double x_start, double x_end, int num_nodes, function<double(double)> func)
    {
        this->numNodes = num_nodes;
        this->x.resize(num_nodes);
        this->y.resize(num_nodes);
        this->a.resize(num_nodes);
        this->b.resize(num_nodes - 1);
        this->c.resize(num_nodes);
        this->d.resize(num_nodes - 1);
        this->fi.resize(4);
        this->m.resize(num_nodes);
        this->alf.resize(num_nodes);
        this->bet.resize(num_nodes);
        fun = func;


        fi[0] = convertFunct<double, double>([](double t) { return (1 - t)*(1-t) * (1 + 2 * t); });
        fi[1] = convertFunct<double, double>([](double t) { return (t * t) * (3 - 2 * t); });
        fi[2] = convertFunct<double, double>([](double t) { return t * (1 - t) * (1 - t); });
        fi[3] = convertFunct<double, double>([](double t) { return -t * t * (1 - t); });


        double step = (x_end - x_start) / (num_nodes - 1);

        

        //cout << "\n\n";
        for (int i = 0; i < num_nodes; ++i)
        {
            this->x[i] = x_start + i * step;
            this->y[i] = func(this->x[i]);
            //zaglushka
            this->alf[i] = 1 / 2.0;
            this->bet[i] = 1 / 2.0;
            
            //cout << "(" << x[i] << ", " << y[i] << ")" << endl;
        }
        //cout << "\n\n";
        //this->c[0] = 0;
        double dxl = (func(x_start + 1e-10) - func(x_start)) / 1e-10;
        double dxr = (func(x_end + 1e-10) - func(x_end)) / 1e-10;
        this->c[0] = (y[1]-y[0])/step;
        //this->c[0] = dxl;
        for (int i = 1; i < num_nodes -1; ++i)
        {
            this->c[i] = 3 * (alf[i] * (y[i + 1] - y[i]) / step + bet[i] * (y[i] - y[i - 1]) / step);
            //this->c[i] = (alf[i] * (y[i + 1] - y[i]) / step + bet[i] * (y[i] - y[i - 1]) / step);
        }
        //this->c[numNodes-1] = 0;
        //this->c[numNodes - 1] = 2* x_end;
        this->c[numNodes-1] = (y[num_nodes-1] - y[num_nodes-2]) / step;
        _vector<double> A{0,num_nodes }, B{ 0,num_nodes }, C{ 0,num_nodes }, D{ 0,num_nodes };

        initCoefficientsForProgon(A, B, C, D);
        




        // Заполнение узлов и значений функции
        /*T step = (x_end - x_start) / (num_nodes - 1);
        cout << "\n\n";
        for (int i = 0; i < num_nodes; ++i)
        {
            this->x[i] = x_start + i * step;
            this->y[i] = func(this->x[i]);
            cout << "(" << x[i] << ", " << y[i] << ")" << endl;
        }
        cout << "\n\n";*/
        // Вычисление коэффициентов сплайна
        computeCoefficients(A, B, C, D);
    }
    void initCoefficientsForProgon(_vector<double>& A, _vector<double>& B, _vector<double>& C, _vector<double>& D)
    {
        A[0] = 0;
        B[0] = 1;
        C[0] = 0;
        D[0] = c[0];
        for (int i = 1; i < numNodes - 1; ++i)
        {
            A[i] = alf[i];
            B[i] = 2;
            C[i] = bet[i];
            //D[i] = y[i];
            D[i] = c[i];
        }
        A[numNodes-1] = 0;
        B[numNodes-1] = 1;
        C[numNodes-1] = 0;
        D[numNodes-1] = c[numNodes-1];
    }
    void computeCoefficients(_vector<double> A, _vector<double> B, _vector<double> C, _vector<double> D)
    {
        progonka(A, B, C, D, numNodes, m);
        //std::vector<T> h(numNodes - 1);
        //std::vector<T> alpha(numNodes - 1);
        //for (int i = 0; i < numNodes - 1; ++i)
        //{
        //    h[i] = x[i + 1] - x[i];
        //}

        //// Обработка коэффициентов для уравнений
        //std::vector<T> l(numNodes);
        //std::vector<T> mu(numNodes);
        //std::vector<T> z(numNodes);

        //// Начальные условия для треугольной системы
        //l[0] = 1;
        //z[0] = 0;
        //mu[0] = 0;

        //// Заполнение системы для c
        //for (int i = 1; i < numNodes - 1; ++i)
        //{
        //    alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
        //    l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        //    mu[i] = h[i] / l[i];
        //    z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        //}

        //// Граничные условия для второго производного
        //l[numNodes - 1] = 1; // Для естественных сплайнов
        //z[numNodes - 1] = 0;

        //// Обратное решение для c
        //for (int j = numNodes - 2; j >= 0; --j)
        //{
        //    c[j] = z[j] - mu[j] * c[j + 1];
        //}

        //// Вычисление b и d
        //for (int i = 0; i < numNodes - 1; ++i)
        //{
        //    b[i] = (y[i + 1] - y[i]) / h[i] - (h[i] * (2 * c[i] + c[i + 1])) / 3;
        //    d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
        //}

        //// Значения a - это просто y
        //a = y;
    }

    double cubicSpline(double xi) const
    {
        int i = 0;

        // Найти интервал, в котором находится xi
        while (i < numNodes - 1 && xi > x[i + 1])
        {
            ++i;
        }

        // Вычисление значения сплайна
        double dx = x[i+1] - x[i];
        double t1 = (xi - x[i]);
        double t = (xi - x[i]) / (dx);


        double cc1 = fi[0](t), cc2 = fi[1](t), cc3 = fi[2](t), cc4 = fi[3](t);
        return fi[0](t)*y[i] + fi[1](t)*y[i+1] + fi[2](t) * dx*m[i] + fi[3](t) * dx*m[i+1];

    }

    // Генерация данных для построения графика
    void generateSplineData(_vector<double>& spline_x, _vector<double>& spline_y, int num_points = 50) const
    {
        spline_x.resize(num_points);
        spline_y.resize(num_points);

        double x_start = x[0];
        double x_end = x[numNodes - 1];
        double step = (x_end - x_start) / (num_points - 1);

        for (int i = 0; i < num_points; ++i)
        {
            spline_x[i] = x_start + i * step;
            spline_y[i] = cubicSpline(spline_x[i]);
        }
    }
    const _vector<double> deviation()
    {
        int a;
        double step=(this->x[numNodes - 1] - this->x[0]) / (numNodes - 1);
        //double step = (this->x[numNodes - 1]-this->x[1]) / (numNodes - 2);


        _vector<double> x1, y1, sp1;
        x1.resize(numNodes - 1);
        y1.resize(numNodes - 1);
        sp1.resize(numNodes - 1);
        //cout << "\n\n";
        for (int i = 0; i < numNodes -1; ++i)
        {
            x1[i] = this->x[0] + (1/2.0+i) * step;
            y1[i] = fun(x1[i]);
            sp1[i] = cubicSpline(x1[i]);
        }
        _vector<double> diff;
        diff = y1 - sp1;
        //temp
        //diff.map(fabs);
        for (int i = 0; i < numNodes - 1; ++i)
        {
            diff[i] = fabs(diff[i]);
        }
        
        return diff;
        //diff=fabs

    }

    // Получение узлов
    const _vector<double>& getX() const
    {
        return x;
    }

    // Получение значений функции
    const _vector<double>& getY() const
    {
        return y;
    }

    void printSplinePoints() const
    {
        for (int i = 0; i < numNodes; ++i)
        {
            std::cout << "x: " << x[i] << ", y: " << y[i] << std::endl;
        }
    }

private:

    /*_polynom S(0, 3);*/
    function<double(double)> fun;
    _array<_function<double, double>> fi;
    //_array<_function<double, double>> fi(convertFunct<double, double>(zeros), 4, L"fi");

    //_array<_function<double, double>> fi(convertFunct<double,double>(fzero<double>),4);
    //_array<_function<double, double>> fi(convertFunct<double, double>([](double x) { return 0.0; }), 4, L"fi");
    //_array<_function<double, double>> fi(convertFunct(fzero<double>), 4, L"fi");
    //_array<_function<double, double>> fi(convertFunct(fzero<double>), 4, L"fi");
    //_array<_function<double, double>> fi(convertFunct<double,double>(fzero<double, double>), 4, L"fi");
    //double alf, bet;
    _vector<double> alf, bet;
    _vector<double> m;
    _vector<double> x, y, a, b, c, d;
    int numNodes;
};


template<typename T>
class _spline {
public:
    _spline(T x_start, T x_end, int num_nodes, std::function<T(T)> func)
    {
        this->numNodes = num_nodes;
        this->x.resize(num_nodes);
        this->y.resize(num_nodes);
        this->a.resize(num_nodes);
        this->b.resize(num_nodes - 1);
        this->c.resize(num_nodes);
        this->d.resize(num_nodes - 1);

        // Заполнение узлов и значений функции
        T step = (x_end - x_start) / (num_nodes - 1);
        cout << "\n\n";
        for (int i = 0; i < num_nodes; ++i)
        {
            this->x[i] = x_start + i * step;
            this->y[i] = func(this->x[i]);
            cout << "(" << x[i] << ", " << y[i]<<")" << endl;
        }
        cout << "\n\n";
        // Вычисление коэффициентов сплайна
        computeCoefficients();
    }

    void computeCoefficients()
    {
        std::vector<T> h(numNodes - 1);
        std::vector<T> alpha(numNodes - 1);
        for (int i = 0; i < numNodes - 1; ++i)
        {
            h[i] = x[i + 1] - x[i];
        }

        // Обработка коэффициентов для уравнений
        std::vector<T> l(numNodes);
        std::vector<T> mu(numNodes);
        std::vector<T> z(numNodes);

        // Начальные условия для треугольной системы
        l[0] = 1;
        z[0] = 0;
        mu[0] = 0;

        // Заполнение системы для c
        for (int i = 1; i < numNodes - 1; ++i)
        {
            alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
            l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }

        // Граничные условия для второго производного
        l[numNodes - 1] = 1; // Для естественных сплайнов
        z[numNodes - 1] = 0;

        // Обратное решение для c
        for (int j = numNodes - 2; j >= 0; --j)
        {
            c[j] = z[j] - mu[j] * c[j + 1];
        }

        // Вычисление b и d
        for (int i = 0; i < numNodes - 1; ++i)
        {
            b[i] = (y[i + 1] - y[i]) / h[i] - (h[i] * (2 * c[i] + c[i + 1])) / 3;
            d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
        }

        // Значения a - это просто y
        a = y;
    }

    T cubicSpline(T xi) const
    {
        int i = 0;

        // Найти интервал, в котором находится xi
        while (i < numNodes - 1 && xi > x[i + 1])
        {
            ++i;
        }

        // Вычисление значения сплайна
        T dx = xi - x[i];
        return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
    }

    // Генерация данных для построения графика
    void generateSplineData(std::vector<T>& spline_x, std::vector<T>& spline_y, int num_points = 50) const
    {
        spline_x.resize(num_points);
        spline_y.resize(num_points);

        T x_start = x[0];
        T x_end = x[numNodes - 1];
        T step = (x_end - x_start) / (num_points - 1);

        for (int i = 0; i < num_points; ++i)
        {
            spline_x[i] = x_start + i * step;
            spline_y[i] = cubicSpline(spline_x[i]);
        }
    }

    // Получение узлов
    const std::vector<T>& getX() const
    {
        return x;
    }

    // Получение значений функции
    const std::vector<T>& getY() const
    {
        return y;
    }

    void printSplinePoints() const
    {
        for (int i = 0; i < numNodes; ++i)
        {
            std::cout << "x: " << x[i] << ", y: " << y[i] << std::endl;
        }
    }

private:
    std::vector<T> x, y, a, b, c, d;
    int numNodes;
};


#endif