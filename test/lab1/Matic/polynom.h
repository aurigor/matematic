#ifndef POLYNOM
#define POLYNOM
#include<iostream>
#include<vector>
#include <cmath>      // Для pow и NAN
#include <stdexcept>  // Для исключений
#include"const.h"
#include<string>
#include <random>
#include <ranges>

using namespace std;

//что делать не с целочисленными типами
//например со стринг?


/// сделать обработчик исключений
/// перегрузить все операторы
/// добавить методы 
/// решить проблему с делением на ноль
/// 

template<typename T>
class _polynom {
public:
    // Конструктор с параметрами
    //_vector(T a = 0, int size = 1) : vec(size, a) {}
    _polynom(T a = 0, int degree = 0, wstring name = _wundName) :name(name) {
        pol.resize(degree + 1, a);
    }
    _polynom(const _vector<T>& vec, wstring name):name(name)
    {
        pol = vec;
        // Реализация конструктора
    }
    // Конструктор по умолчанию
   // _vector() {}

    // Конструктор копирования
    _polynom(const _polynom& other) : pol(other.pol), name(other.name) {}

    // Конструктор перемещения
    _polynom(_polynom&& other) noexcept : pol(std::move(other.pol)), name(std::move(other.name)) {}


    // Деструктор
    ~_polynom() {}


    //////////////////////////////////////////////////////////////////////////
    // Методы
    int size() const
    {
        return pol.size();
    }
    int degree() const
    {
        return pol.size() - 1;
    }

    std::vector<T> get() const
    {
        return pol;
    }
    wstring getName() const
    {
        return name;
    }
    // Вычислить значение полинома в точке x
    double evaluate(double x) const
    {
        double result = 0.0;
        for (int i = 0; i <= degree(); ++i)
        {
            result += pol[i] * std::pow(x, i);
        }
        return result;
    }
    void generateRandom(int degree, T minValue, T maxValue)
    {
        // Определяем тип распределения в зависимости от типа T
        using distribution_type = typename std::conditional<
            std::is_integral<T>::value,                  // Если T — целочисленный тип,
            std::uniform_int_distribution<T>,            // используем uniform_int_distribution,
            std::uniform_real_distribution<T>            // иначе — uniform_real_distribution.
        >::type;

        std::random_device rd;  // Источник энтропии
        std::mt19937 gen(rd()); // Стандартный генератор случайных чисел
        distribution_type dist(minValue, maxValue); // Соответствующее распределение для типа T

        pol.resize(degree + 1);  // Задаем размер вектора с коэффициентами
        for (int i = 0; i <= degree; ++i)
        {
            pol[i] = dist(gen);  // Заполняем коэффициенты случайными числами
        }
    }
    //void generateRandom(int degree, T minValue, T maxValue)
    //{
    //    random_device rd;  // Источник энтропии
    //    mt19937 gen(rd()); // Стандартный генератор случайных чисел
    //    uniform_real_distribution<T> dist(minValue, maxValue); // Генерация чисел в диапазоне [minValue, maxValue]

    //    pol.resize(degree + 1);  // Задаем размер вектора с коэффициентами
    //    for (int i = 0; i <= degree; ++i)
    //    {
    //        pol[i] = dist(gen);  // Заполняем коэффициенты случайными числами
    //    }
    //}
    // Методы вывода информации

    void clear()
    {
        pol.clear(); // Очистка внутреннего вектора
    }
    bool isBigger(const _polynom& other) const
    {
        if (pol.size() > other.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isLess(const _polynom& other) const
    {
        if (pol.size() < other.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEquals(const _polynom& other) const
    {
        /*if (vec::value_type != other::value_type)
        {
            cout << "типы векторов не совпадают";
        }*/
        if (pol.size() == other.size())
        {
            return true;
        }
        else
        {
            //cout << "размеры векторов не совпадают";
            return false;
        }
    }

    _polynom chekDegree()
    {
        if (pol[this->degree()] == 0)
        {
            pol.pop_back();
            chekDegree();
        }
        return *this;
    }
    void add(T element)
    {
        pol.push_back(element);
    }

    void description() const
    {
        cout << "\n _vector это обертка над классом vector\n";
        cout << " _vector можно складывать, умножать, делить, возводить в степень(степень числа, или возведение вектора в степень другого вектора)\n";
        cout << " в арифметических операция, размеры _vector должны быть одинаковы\n";
        cout << " не рекомендуется использовать _vector для представления матриц и других многомерных структур\n\n";

    }
    void help() const
    {
        /*cout << " _vector поддерживает следующие операции, методы, и команды: \n";
        cout << " \"+\", \"-\",\"*\",\"/\",\"%\"  \n";*/
        cout << "_vector поддерживает следующие операции и методы:\n";
        cout << "+, -, *, /, %, ^ (возведение в степень)\n";
        cout << "Сравнение: ==, !=\n";
        cout << "Логические операции: &&, ||\n";
        cout << "Методы: size(), add(element), print(), get()\n\n";

    }

    void help(const std::string& query) const
    {
        // Проверка запроса на оператор или команду
        if (query == "+")
        {
            cout << "_vector поддерживает операцию сложения (+).\n";
            cout << "При сложении векторов складываются соответствующие элементы.\n";
            cout << "Пример: [1, 2, 3] + [4, 5, 6] = [5, 7, 9]\n";
        }
        else if (query == "-")
        {
            cout << "_vector поддерживает операцию вычитания (-).\n";
            cout << "При вычитании векторов вычитаются соответствующие элементы.\n";
            cout << "Пример: [1, 2, 3] - [4, 5, 6] = [-3, -3, -3]\n";
        }
        else if (query == "*")
        {
            cout << "_vector поддерживает операцию умножения (*) поэлементно.\n";
            cout << "Пример: [1, 2, 3] * [4, 5, 6] = [4, 10, 18]\n";
        }
        else if (query == "/")
        {
            cout << "_vector поддерживает операцию деления (/).\n";
            cout << "При делении элементов векторов проверяется деление на ноль.\n";
            cout << "В случае деления на 0 в соответствующий элемент записывается NAN.\n";
            cout << "Пример: [4, 9, 0] / [2, 3, 0] = [2, 3, NAN]\n";
        }
        else if (query == "&&")
        {
            cout << "_vector поддерживает логическую операцию И (&&).\n";
            cout << "Пример: [1, 0, 1] && [1, 1, 0] = [1, 0, 0]\n";
        }
        else if (query == "||")
        {
            cout << "_vector поддерживает логическую операцию ИЛИ (||).\n";
            cout << "Пример: [1, 0, 1] || [1, 1, 0] = [1, 1, 1]\n";
        }
        else if (query == "^")
        {
            cout << "_vector поддерживает возведение в степень (^).\n";
            cout << "Пример: [1, 2, 3] ^ [4, 5, 6] = [1, 32, 729] (поэлементное возведение в степень)\n";
        }
        else if (query == "description")
        {
            cout << "Метод description() выводит общую информацию о классе _vector.\n";
            cout << "Описание включает доступные операторы, методы и возможные операции.\n";
        }
        else if (query == "print")
        {
            cout << "Метод print() выводит все элементы вектора в строку, разделенные пробелами.\n";
            cout << "Пример: для _vector<int> v{1, 2, 3} вызов v.print() выведет: 1 2 3\n";
        }
        else if (query == "size")
        {
            cout << "Метод size() возвращает количество элементов вектора.\n";
            cout << "Пример: для вектора _vector<int> v{1, 2, 3} вызов v.size() вернет 3.\n";
        }
        else if (query == "add")
        {
            cout << "Метод add(element) добавляет элемент в конец вектора.\n";
            cout << "Пример: для вектора _vector<int> v{1, 2} вызов v.add(3) изменит вектор на {1, 2, 3}.\n";
        }
        else if (query == "scalar_product")
        {
            cout << "Метод scalar_product(const _vector&) возвращает скалярное произведение двух векторов.\n";
            cout << "Пример: для векторов _vector<int> v1{1, 2, 3} и _vector<int> v2{4, 5, 6},\n";
            cout << "вызов v1.scalar_product(v2) вернет: 1*4 + 2*5 + 3*6 = 32.\n";
        }
        else
        {
            cout << "Операция или метод \"" << query << "\" не поддерживается или не найден.\n";
            cout << "Пожалуйста, используйте одну из следующих команд:\n";
            cout << "\"+\", \"-\", \"*\", \"/\", \"%\", \"^\", \"&&\", \"||\", \"description\", \"print\", \"size\", \"add\", \"scalar_product\".\n";
        }

        cout << "\n";
    }

    //// Метод для получения степени полинома
    //int degree() const
    //{
    //    return coeffs.size() - 1;
    //}

    //// Метод для вычисления значения полинома в точке x
    //double evaluate(double x) const
    //{
    //    double result = 0.0;
    //    int deg = degree();
    //    for (int i = 0; i <= deg; ++i)
    //    {
    //        result += coeffs[i] * pow(x, i);
    //    }
    //    return result;
    //}
    void setName(wstring str)
    {
        name = str;
    }


private:
    wstring name{ "UNDEFINED" };
    _vector<T> pol;


public:
    void print() const
    {
        if (name != L"UNDEFINED")
        {
            wcout << L"_polynom " << name << L" := ";
        }
        wcout << *this << L"\n";
    }

    ////////////////////////////////////////////////////////////////////////////////
    // операторы
    // Перегрузка оператора сложения полиномов
    _polynom operator+(const _polynom& other) const
    {
        int tSize = this->degree(), oSize= other.degree();

        int maxSize = max(tSize, oSize);
        //_polynom<T> result(0, maxSize);
        _polynom<T> result(0, maxSize, this->name+L" + "+other.getName());
        //_vector<T> result(0, maxSize);
        //wcout << result[0];
        //wcout << result.size()<<endl;
        //result.print();
        for (int i = 0; i <= maxSize; ++i)
        {
            if (i <= tSize) result[i] += this->pol[i];
            if (i <= oSize) result[i] += other.pol[i];
        }
        //_polynom<T> resPol(result);
        //return resPol;
        return result.chekDegree();
    }

    // Перегрузка оператора умножения полинома на скаляр
    _polynom operator*(T scalar) const
    {
        _polynom result(0, pol.size());
        for (int i = 0; i < pol.size(); ++i)
        {
            result.pol[i] = pol[i] * scalar;
        }
        return result;
    }
    // Перегрузка оператора умножения полиномов (перемножение полиномов)
    _polynom operator*(const _polynom& other) const
    {
        int newDegree = this->degree() + other.degree();  // Новая степень полинома
        _polynom result(0, newDegree, this->name + L" * " + other.getName());

        for (int i = 0; i <= this->degree(); ++i)
        {
            for (int j = 0; j <= other.degree(); ++j)
            {
                result.pol[i + j] += this->pol[i] * other.pol[j];
            }
        }
        return result.chekDegree();
    }
    //void print() const
    //{
    //    bool isFirst = true; // Флаг для отслеживания первого члена

    //    for (int i = degree(); i >= 0; --i)
    //    {
    //        double coeff = pol[i]; // Коэффициент текущего члена

    //        // Пропускаем нулевые коэффициенты
    //        if (coeff != 0.0)
    //        {
    //            if (!isFirst)
    //            {
    //                // Добавляем '+' перед не первым членом
    //                if (coeff > 0)
    //                {
    //                    std::wcout << " + ";
    //                }
    //                else
    //                {
    //                    std::wcout << " - ";
    //                }
    //                
    //            }
    //            else
    //            {
    //                isFirst = false; // Сбрасываем флаг после первого члена
    //            }

    //            // Выводим коэффициент
    //            if (i == 0 || coeff != 1.0) // Не выводим '1' для x^n (n > 0)
    //            {
    //                // Если коэффициент отрицательный, выводим только знак и его абсолютное значение
    //                std::wcout << abs(coeff);
    //            }

    //            // Выводим переменную и степень
    //            if (i > 0)
    //            {
    //                std::wcout << "x"; // Выводим переменную
    //                printSuperscript(i); // Выводим степень в виде суперскрипта
    //            }
    //        }
    //    }
    //    std::wcout << std::endl;
    //}

    //void printSuperscript(int number) const
    //{
    //    // Функция для вывода степени как суперскрипта
    //    std::wstring superscript = L"";

    //    while (number > 0)
    //    {
    //        int digit = number % 10;
    //        number /= 10;
    //        superscript = getSuperscriptDigit(digit) + superscript;
    //    }

    //    std::wcout << superscript; // Выводим суперскрипт
    //}
    void printSuperscript(wostream& out, int number) const
    {
        wstring superscript = L"";

        while (number > 0)
        {
            int digit = number % 10;
            number /= 10;
            superscript = getSuperscriptDigit(digit) + superscript;
        }

        out << superscript;
    }

    // Метод для получения надстрочного символа Юникода для каждой цифры
    std::wstring getSuperscriptDigit(int digit) const
    {
        switch (digit)
        {
        case 0: return L"⁰";
        case 1: return L"¹";
        case 2: return L"²";
        case 3: return L"³";
        case 4: return L"⁴";
        case 5: return L"⁵";
        case 6: return L"⁶";
        case 7: return L"⁷";
        case 8: return L"⁸";
        case 9: return L"⁹";
        default: return L"";
        }
    }

    // Метод для вывода полинома на экран
    friend wostream& operator<<(wostream& out, const _polynom& poly) {
    bool isFirst = true; // Флаг для отслеживания первого члена
    int degree = poly.degree();
    for (int i = degree; i >= 0; --i)
    {
        double coeff = poly[i]; // Коэффициент текущего члена

        // Пропускаем нулевые коэффициенты
        if (coeff != 0.0)
        {
            /*if (!isFirst)
            {*/
                if (coeff > 0 && i!= degree)
                {
                    out << " + ";
                }
                else if(coeff<0)
                {
                    out << " - ";
                }
            /*}
            else
            {
                isFirst = false;
            }*/

            if (i == 0 || abs(coeff) != 1.0)
            {
                out << abs(coeff);
            }

            if (i > 0)
            {
                out << "x";
                poly.printSuperscript(out, i);
            }
        }
    }
    return out;
    }
    //friend ostream& operator<<(ostream& out, const _polynom& poly)
    //{
    //    bool isFirst = true; // Флаг для отслеживания первого члена

    //    for (int i = poly.degree(); i >= 0; --i)
    //    {
    //        double coeff = poly[i]; // Коэффициент текущего члена

    //        // Пропускаем нулевые коэффициенты
    //        if (coeff != 0.0)
    //        {
    //            if (!isFirst)
    //            {
    //                // Добавляем '+' перед не первым членом
    //                if (coeff > 0)
    //                {
    //                    out << " + ";
    //                }
    //                else
    //                {
    //                    out << " - ";
    //                }

    //            }
    //            else
    //            {
    //                isFirst = false; // Сбрасываем флаг после первого члена
    //            }

    //            // Выводим коэффициент
    //            if (i == 0 || coeff != 1.0) // Не выводим '1' для x^n (n > 0)
    //            {
    //                // Если коэффициент отрицательный, выводим только знак и его абсолютное значение
    //                out << abs(coeff);
    //            }

    //            // Выводим переменную и степень
    //            if (i > 0)
    //            {
    //                out << "x"; // Выводим переменную
    //                poly.printSuperscript(out,(i); // Выводим степень в виде суперскрипта
    //            }
    //        }
    //    }
    //    out << std::endl;
    //    return out;
    //}
    // Перегрузка оператора вывода
   /* friend std::ostream& operator<<(std::ostream& out, const _vector<T>& v)
    {
        out << "[";
        for (int i = 0; i < v.size(); ++i)
        {
            out << v[i];
            if (i != v.size() - 1)
            {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }*/

    
    //friend std::istream& operator>>(std::istream& in, _vector<T>& v)
    //{
    //    cout << "Введите элементы (для завершения введите 'end'):\n";
    //    v.clear();  // Очищаем текущий вектор
    //    T element;
    //    while (in >> element)
    //    {  // Читаем элементы
    //        v.add(element);
    //    }
    //    return in;
    //}
    // 
    T& operator[](int index)
    {
        if (index < 0 || index >= pol.size())
        {
            throw std::out_of_range("Индекс выходит за пределы вектора.");
        }
        return pol[index]; // Возвращаем ссылку для модификации
    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= pol.size())
        {
            throw std::out_of_range("Индекс выходит за пределы вектора.");
        }
        return pol[index]; // Константная версия для доступа только для чтения
    }

    // Оператор копирования
    _polynom& operator=(const _polynom& other)
    {
        if (this != &other)
        {
            pol = other.pol;
            name = other.name;
        }
        return *this;
    }
    _polynom& operator=(const _vector<T>& other)
    {
        this->pol = other;
        return *this;
    }

    // Оператор перемещения
    _polynom& operator=(_polynom&& other) noexcept
    {
        if (this != &other)
        {
            pol = std::move(other.pol);
            name = std::move(other.name);
        }
        return *this;
    }

    //Арифметические операторы
    // Оператор сложения

    // Оператор умножения на константу
    //_polynom<T> operator *(T constant) const
    //{
    //    _vector<T> result(0, pol.size());  // Создаем результирующий вектор того же размера
    //    for (int i = 0; i < pol.size(); ++i)
    //    {
    //        result.vec[i] = pol[i] * constant;
    //    }
    //    return result;
    //}

    // Оператор *= (умножение на скаляр)
    _polynom& operator*=(T scalar)
    {
        for (int i = 0; i < pol.size(); ++i)
        {
            pol[i] *= scalar;
        }
        return *this.chekDegree();
    }


    // Оператор сравнения на равенство
    bool operator==(const _polynom& other) const
    {
        return pol == other.pol;
    }

    // Оператор сравнения на неравенство
    bool operator!=(const _polynom& other) const
    {
        return pol != other.pol;
    }



};

#endif



