#ifndef SPLINE
#define SPLINE

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
//template<typename T>
//class _spline {
//public:
//    _spline(const std::vector<T>& x, const std::vector<T>& y, bool natural = true)
//    {
//        numNodes = x.size();
//        this->x = x;
//        this->y = y;
//        calculateCoefficients(natural);
//    }
//    _spline(T start, T end, int numNodes, std::function<T(T)> func)
//                : start(start), end(end), numNodes(numNodes), func(func)
//            {
//                calculateNodes();
//                computeCoefficients();
//            }
//
//    void calculateCoefficients(bool natural)
//    {
//        // Заполнение коэффициентов a, b, c, d и решение системы уравнений
//        a = y; // a[i] равен y[i]
//
//        // Создание системы для b и c
//        std::vector<T> h(numNodes - 1);
//        std::vector<T> alpha(numNodes - 1);
//        for (int i = 0; i < numNodes - 1; ++i)
//        {
//            h[i] = x[i + 1] - x[i];
//            alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
//        }
//
//        // Решение системы для c
//        std::vector<T> c(numNodes);
//        std::vector<T> l(numNodes);
//        std::vector<T> mu(numNodes);
//        std::vector<T> z(numNodes);
//
//        l[0] = 1; // Начальное условие
//        mu[0] = 0; // Начальное условие
//        z[0] = 0; // Начальное условие
//
//        for (int i = 1; i < numNodes - 1; ++i)
//        {
//            l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
//            mu[i] = h[i] / l[i];
//            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
//        }
//
//        // Граничные условия
//        l[numNodes - 1] = (natural) ? 1 : 0;
//        z[numNodes - 1] = (natural) ? 0 : 0;
//
//        // Решение для c
//        for (int j = numNodes - 2; j >= 0; --j)
//        {
//            c[j] = z[j] - mu[j] * c[j + 1];
//        }
//
//        // Решение для b и d
//        b.resize(numNodes - 1);
//        d.resize(numNodes - 1);
//        for (int i = 0; i < numNodes - 1; ++i)
//        {
//            b[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (2 * c[i] + c[i + 1]) / 3;
//            d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
//        }
//    }
//
//    T cubicSpline(T xi) const
//    {
//        int i = 0;
//        // Найти интервал
//        while (i < numNodes - 1 && xi > x[i + 1])
//        {
//            ++i;
//        }
//        T dx = xi - x[i];
//        return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
//    }
//
//private:
//    std::vector<T> x, y, a, b, c, d;
//    int numNodes;
//};


//template<typename T>
//class _spline {
//public:
//    _spline(T start, T end, int numNodes, std::function<T(T)> func)
//        : start(start), end(end), numNodes(numNodes), func(func)
//    {
//        calculateNodes();
//        computeCoefficients();
//    }
//
//    void printSplinePoints() const
//    {
//        for (size_t i = 0; i < x.size(); ++i)
//        {
//            std::cout << "Node " << i << ": (" << x[i] << ", " << y[i] << ")\n";
//        }
//    }
//
//    void generateSplineData(std::vector<T>& spline_x, std::vector<T>& spline_y) const
//    {
//        int numSplinePoints = 100; // Количество точек для сплайна
//        T step = (end - start) / (numSplinePoints - 1);
//        for (int i = 0; i < numSplinePoints; ++i)
//        {
//            T xi = start + i * step;
//            spline_x.push_back(xi);
//            spline_y.push_back(cubicSpline(xi));
//        }
//    }
//
//    const std::vector<T>& getX() const { return x; }
//    const std::vector<T>& getY() const { return y; }
//
//private:
//    T start, end;
//    int numNodes;
//    std::function<T(T)> func;
//    std::vector<T> x, y;
//    std::vector<T> a, b, c, d;
//
//    void calculateNodes()
//    {
//        double step = (end - start) / (numNodes - 1);
//        for (int i = 0; i < numNodes; ++i)
//        {
//            T xi = start + i * step;
//            x.push_back(xi);
//            y.push_back(func(xi));
//        }
//    }
//
//    void computeCoefficients()
//    {
//        int n = numNodes - 1;
//        a.resize(n);
//        b.resize(n);
//        c.resize(n);
//        d.resize(n);
//
//        for (int i = 0; i < n; ++i)
//        {
//            a[i] = y[i];
//        }
//
//        // Расчет h и alpha
//        std::vector<T> h(n), alpha(n);
//        for (int i = 0; i < n; ++i)
//        {
//            h[i] = x[i + 1] - x[i];
//            if (i > 0)
//            {
//                alpha[i] = (3 / h[i]) * (a[i + 1] - a[i]) - (3 / h[i - 1]) * (a[i] - a[i - 1]);
//            }
//        }
//
//        // Система уравнений для c
//        std::vector<T> l(n + 1), mu(n), z(n + 1);
//        l[0] = 1;
//        for (int i = 1; i < n; ++i)
//        {
//            l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
//            mu[i] = h[i] / l[i];
//            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
//        }
//        l[n] = 1;
//        z[n] = 0;
//
//        // Обратное подстановка
//        for (int j = n - 1; j >= 0; --j)
//        {
//            c[j] = z[j] - mu[j] * c[j + 1];
//            b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
//            d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
//        }
//    }
//
//    T cubicSpline(T xi) const
//    {
//        int i = 0;
//        // Найти интервал
//        while (i < numNodes - 1 && xi > x[i + 1])
//        {
//            ++i;
//        }
//
//        // Вычисление значения сплайна
//        T dx = xi - x[i];
//        return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
//    }
//};

//template<typename T>
//class _spline {
//public:
//    _spline(T start, T end, int numNodes, std::function<T(T)> func)
//        : start(start), end(end), numNodes(numNodes), func(func)
//    {
//        calculateNodes();
//    }
//
//    void printSplinePoints() const
//    {
//        for (size_t i = 0; i < x.size(); ++i)
//        {
//            std::cout << "Node " << i << ": (" << x[i] << ", " << y[i] << ")\n";
//        }
//    }
//
//    void generateSplineData(std::vector<T>& spline_x, std::vector<T>& spline_y) const
//    {
//        int numSplinePoints = 100; // Количество точек для сплайна
//        T step = (end - start) / (numSplinePoints - 1);
//        for (int i = 0; i < numSplinePoints; ++i)
//        {
//            T xi = start + i * step;
//            spline_x.push_back(xi);
//            spline_y.push_back(cubicSpline(xi));
//        }
//    }
//    const std::vector<T>& getX() const { return x; }
//    const std::vector<T>& getY() const { return y; }
//private:
//    T start, end;
//    int numNodes;
//    std::function<T(T)> func;
//    std::vector<T> x, y;
//
//    void calculateNodes()
//    {
//        T step = (end - start) / (numNodes - 1);
//        for (int i = 0; i < numNodes; ++i)
//        {
//            T xi = start + i * step;
//            x.push_back(xi);
//            y.push_back(func(xi));
//        }
//    }
//
//    T cubicSpline(T xi) const
//    {
//        // Простейшая интерполяция для примера
//        // Здесь нужно реализовать кубическую интерполяцию
//        // Для упрощения вернем значение функции, как есть
//        // Вы должны добавить реальную логику кубического сплайна
//        return func(xi);
//    }
//};

//template<typename T>
//class _spline {
//public:
//    // Конструктор с параметрами: принимает отрезок [a, b], количество узлов и функцию
//    _spline(T a, T b, int n, std::function<T(T)> func)
//    {
//        // Генерация узлов сетки и вычисление значений функции в узлах
//        for (int i = 0; i <= n; ++i)
//        {
//            T x_val = a + i * (b - a) / n; // Шаг равномерного распределения
//            x.push_back(x_val);
//            y.push_back(func(x_val)); // Вычисляем значение функции в узле
//        }
//
//        // Построение коэффициентов сплайна
//        buildSpline();
//    }
//
//    // Метод для вывода узлов сплайна и значений
//    void printSplinePoints() const
//    {
//        cout << "Spline points (x, y):" << endl;
//        for (size_t i = 0; i < x.size(); ++i)
//        {
//            cout << "(" << x[i] << ", " << y[i] << ")" << endl;
//        }
//    }
//
//    // Получение значения сплайна в точке x_val
//    T getValue(T x_val) const
//    {
//        // Найти сегмент, в котором находится x_val
//        size_t idx = findSegment(x_val);
//        if (idx >= a.size()) return 0; // Пограничный случай: если значение x_val за пределами отрезка
//
//        // Вычислить значение сплайна на найденном сегменте
//        T dx = x_val - x[idx];
//        return a[idx] + b[idx] * dx + c[idx] * dx * dx + d[idx] * dx * dx * dx;
//    }
//
//    // Генерация данных для построения сплайна (например, для построения графика)
//    void generateSplineData(std::vector<T>& spline_x, std::vector<T>& spline_y, int num_points = 100) const
//    {
//        // Генерация num_points значений сплайна на интервале [x[0], x[x.size()-1]]
//        T step = (x.back() - x.front()) / (num_points - 1);
//        for (int i = 0; i < num_points; ++i)
//        {
//            T x_val = x.front() + i * step;
//            spline_x.push_back(x_val);
//            spline_y.push_back(getValue(x_val));
//        }
//    }
//
//private:
//    std::vector<T> x;  // Узлы сетки по x
//    std::vector<T> y;  // Значения функции в узлах
//    std::vector<T> a, b, c, d;  // Коэффициенты сплайна
//
//    // Метод для построения сплайна
//    void buildSpline()
//    {
//        size_t n = x.size() - 1;
//        a = y;
//
//        // Вспомогательные массивы для решения системы уравнений
//        std::vector<T> alpha(n), beta(n);
//        std::vector<T> h(n);
//        c.resize(n + 1);
//
//        for (size_t i = 0; i < n; ++i)
//        {
//            h[i] = x[i + 1] - x[i];  // Шаг на каждом сегменте
//        }
//
//        // Решение системы уравнений методом прогонки
//        for (size_t i = 1; i < n; ++i)
//        {
//            T A = h[i - 1];
//            T B = -2 * (h[i - 1] + h[i]);
//            T C = h[i];
//            T F = -3 * ((a[i + 1] - a[i]) / h[i] - (a[i] - a[i - 1]) / h[i - 1]);
//
//            T z = A * alpha[i - 1] + B;
//            alpha[i] = -C / z;
//            beta[i] = (F - A * beta[i - 1]) / z;
//        }
//
//        c[n] = 0;
//        for (int i = static_cast<int>(n) - 1; i > 0; --i)
//        {
//            c[i] = alpha[i] * c[i + 1] + beta[i];
//        }
//        c[0] = 0;
//
//        // Определение коэффициентов b и d
//        b.resize(n);
//        d.resize(n);
//        for (size_t i = 0; i < n; ++i)
//        {
//            b[i] = (a[i + 1] - a[i]) / h[i] - h[i] * (c[i + 1] + 2 * c[i]) / 3;
//            d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
//        }
//    }
//
//    // Поиск сегмента, в который попадает x_val
//    size_t findSegment(T x_val) const
//    {
//        if (x_val < x[0]) return 0;
//        if (x_val > x.back()) return x.size() - 2;
//
//        size_t left = 0, right = x.size() - 1;
//        while (right - left > 1)
//        {
//            size_t mid = left + (right - left) / 2;
//            if (x[mid] <= x_val)
//            {
//                left = mid;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//        return left;
//    }
//};

#endif




//#ifndef SPLINE
//#define SPLINE
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//template<typename T>
//class _spline {
//public:
//    //_spline() {}
//    _spline(T a, T b, int n, std::function<T(T)> func)
//    {
//        // Генерация узлов сетки и вычисление значений функции в узлах
//        for (int i = 0; i <= n; ++i)
//        {
//            T x_val = a + i * (b - a) / n; // Шаг равномерного распределения
//            x.push_back(x_val);
//            y.push_back(func(x_val)); // Вычисляем значение функции в узле
//        }
//
//        // Построение коэффициентов сплайна
//        buildSpline();
//    }
//    // Метод добавления точек для аппроксимации
//    void add_point(T x, T y)
//    {
//        X.push_back(x);
//        Y.push_back(y);
//    }
//
//    // Метод для построения сплайна
//    void build_spline()
//    {
//        int n = X.size() - 1;
//        a = Y;
//
//        vector<T> h(n); // Вектор длин интервалов
//        for (int i = 0; i < n; ++i)
//        {
//            h[i] = X[i + 1] - X[i];
//        }
//
//        // Вычисление системы уравнений для коэффициентов c
//        vector<T> alpha(n);
//        vector<T> beta(n);
//
//        alpha[0] = beta[0] = 0;  // Граничные условия для естественного сплайна
//        for (int i = 1; i < n; ++i)
//        {
//            T A = h[i - 1];
//            T C = 2 * (h[i - 1] + h[i]);
//            T B = h[i];
//            T F = 3 * ((Y[i + 1] - Y[i]) / h[i] - (Y[i] - Y[i - 1]) / h[i - 1]);
//            T z = (A * alpha[i - 1] + C);
//            alpha[i] = -B / z;
//            beta[i] = (F - A * beta[i - 1]) / z;
//        }
//
//        // Обратный ход метода прогонки для нахождения c[i]
//        c.resize(n + 1);
//        c[n] = 0;
//        for (int i = n - 1; i >= 0; --i)
//        {
//            c[i] = alpha[i] * c[i + 1] + beta[i];
//        }
//
//        // Находим коэффициенты b и d
//        b.resize(n);
//        d.resize(n);
//        for (int i = 0; i < n; ++i)
//        {
//            b[i] = (Y[i + 1] - Y[i]) / h[i] - h[i] * (c[i + 1] + 2 * c[i]) / 3;
//            d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
//        }
//
//        built = true;
//    }
//
//    // Метод для получения значения сплайна в точке x
//    T get_value(T x)
//    {
//        if (!built)
//        {
//            std::cerr << "Сплайн не построен. Сначала вызовите build_spline()." << std::endl;
//            return T();  // Возврат значения по умолчанию
//        }
//
//        int n = X.size() - 1;
//
//        // Находим подходящий интервал для x
//        int i = n - 1;
//        while (i > 0 && x < X[i])
//        {
//            --i;
//        }
//
//        T dx = x - X[i];
//        return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
//    }
//
//    // Метод для вывода коэффициентов сплайна
//    void print_spline()
//    {
//        if (!built)
//        {
//            std::cerr << "Сплайн не построен. Сначала вызовите build_spline()." << std::endl;
//            return;
//        }
//
//        cout << "Коэффициенты сплайна:\n";
//        for (int i = 0; i < X.size() - 1; ++i)
//        {
//            cout << "Интервал [" << X[i] << ", " << X[i + 1] << "]: ";
//            cout << "a = " << a[i] << ", b = " << b[i] << ", c = " << c[i] << ", d = " << d[i] << endl;
//        }
//    }
//
//private:
//    vector<T> X; // Узловые точки по оси X
//    vector<T> Y; // Узловые точки по оси Y
//
//    // Коэффициенты сплайна для каждого сегмента
//    vector<T> a, b, c, d;
//
//    bool built = false;  // Флаг, указывающий, что сплайн построен
//};
//
//#endif
