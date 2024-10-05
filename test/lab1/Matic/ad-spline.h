#ifndef AD-SPLINE
#define AD-SPLINE

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

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