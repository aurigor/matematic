#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<vector>
#include <cmath>      // Для pow и NAN
#include <stdexcept>  // Для исключений
#include"const.h"
#include<string>

#include <ranges>

using namespace std;

//что делать не с целочисленными типами
//например со стринг?
//функции должны поддерживаться
//должны ли?

//
// сравнение векторов - тип, размер, значения элементов
// сравнение размера векторов
//
//проблема при сравнении векторов разного типа



/// сделать обработчик исключений
/// перегрузить все операторы
/// добавить методы 
/// решить проблему с делением на ноль
/// 

template<typename T>
class _vector {
public:
    // Конструктор с параметрами
    //_vector(T a = 0, int size = 1) : vec(size, a) {}
    _vector(T a = 0, int size = 1, string name= _undName) : vec(size, a), name(name) {}

    // Конструктор по умолчанию
   // _vector() {}

    // Конструктор копирования
    _vector(const _vector& other) : vec(other.vec), name(other.name) {}

    // Конструктор перемещения
    _vector(_vector&& other) noexcept : vec(std::move(other.vec)), name(std::move(other.name)) {}


    // Деструктор
    ~_vector() {}

    //T& operator[](int index)
    //{
    //    return vec[index]; // Возвращаем ссылку для модификации
    //}

    //const T& operator[](int index) const
    //{
    //    return vec[index]; // Константная версия для доступа только для чтения
    //}

    



    


    //////////////////////////////////////////////////////////////////////////
    // Методы
    int size() const
    {
        return vec.size();
    }

    std::vector<T> get() const
    {
        return vec;
    }

    T max() const
    {
        if (vec.size() != 0)
        {
            T max = vec[0];
            for (const auto& item : vec)
            {
                if (item> max)
                {
                    max = item;
                }
            }
            return max;
        }
        //temp
        return 0;
    }

    /*void print() const
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    }
    void print() const
    {
        if (name == _undName)
        {
            cout << "_vector " << name << " is: \n";
            for (int i = 0; i < vec.size(); ++i)
            {
                std::cout << vec[i] << " ";
            }
            std::cout << "\n";
        }
    }*/
    // Методы вывода информации
    void print() const
    {
        if (name != "UNDEFINED")
        {
            cout << "_vector " << name << " is: ";
        }
        cout << *this << "\n";
    }
    void clear()
    {
        vec.clear(); // Очистка внутреннего вектора
    }


    bool isBigger(const _vector& other) const
    {
        if (vec.size() > other.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isLess(const _vector& other) const
    {
        if (vec.size() < other.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEquals(const _vector& other) const
    {
        /*if (vec::value_type != other::value_type)
        {
            cout << "типы векторов не совпадают";
        }*/
        if (vec.size() == other.size())
        {
            return true;
        }
        else
        {
            //cout << "размеры векторов не совпадают";
            return false;
        }
    }
    //in terms of size
    //template<typename G>
    //bool isEquals(const _vector<G>& other) const
    //{
    //    // Проверка типов векторов
    //    if constexpr (!std::is_same<G, typename decltype(other)::value_type>::value)
    //    {
    //        std::cout << "Типы векторов не совпадают." << std::endl;
    //        //return false;
    //    }

    //    // Проверка размеров
    //    if (this->size() != other.size())
    //    {
    //        std::cout << "Размеры векторов не совпадают." << std::endl;
    //        return false;
    //    }

    //    // Если типы совпадают и размеры равны
    //    return true;
    //}
    /*bool isEquals(const _vector& other) const
    {
        if (vec::value_type != other::value_type)
        {
            cout << "типы векторов не совпадают";
        }
        if (vec.size() == other.size())
        {
            return true;
        }
        else
        {
            cout << "размеры векторов не совпадают";
            return false
        }
    }*/

    /*template < typename Func, typename Seq>
    auto filter(Func func, const Seq& seq)
    {
        typedef typename Seq::value_type value_type;

        std::vector<value_type> result{};
        for (auto i : seq | std::views::filter(func)) result.push_back(i);

        return result;

    }


    template < typename Func, typename Seq>
    auto map(Func func, const Seq& seq)
    {

        typedef typename Seq::value_type value_type;
        using return_type = decltype(func(std::declval<value_type>()));

        std::vector<return_type> result{};
        for (auto i : seq | std::views::transform(func)) result.push_back(i);

        return result;

    }*/
    template <typename Func>
    _vector<T> filter(Func func) const
    {
        _vector<T> result;
        for (const auto& item : vec)
        {
            if (func(item))
            {
                result.add(item);
            }
        }
        return result;
    }

    // Метод map
    template < typename Func>
    auto map(Func func)
    {

        _vector<T> result{};
        for (auto i : this->vec| std::views::transform(func)) result.push_back(i);

        return result;

    }
    /*template < typename Func, typename Seq>
    auto map(Func func, const Seq& seq)
    {

        typedef typename Seq::value_type value_type;
        using return_type = decltype(func(std::declval<value_type>()));

        std::vector<return_type> result{};
        for (auto i : seq | std::views::transform(func)) result.push_back(i);

        return result;

    }*/
   /* template <typename Func, typename U = decltype(std::declval<Func>()(std::declval<T>()))>
    _vector<U> map(Func func) const
    {
        _vector<U> result;
        for (const auto& item : vec)
        {
            result.add(func(item));
        }
        return result;
    }*/
    void resize(size_t newSize, const T& value = T())
    {
        vec.resize(newSize, value);
    }
    void rename(wstring newName)
    {
        this->name = newName;
    }

    void add(T element)
    {
        vec.push_back(element);
    }
    void pop_back()
    {
        vec.pop_back();
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

    

private:
    string name{"UNDEFINED"};
    vector<T> vec;


public:

    ////////////////////////////////////////////////////////////////////////////////
    // операторы
    // 
    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const _vector<T>& v)
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
    }

    // Перегрузка оператора ввода
    /*friend std::istream& operator>>(std::istream& in, _vector<T>& v)
    {
        T element;
        std::cout << "Введите элементы (для завершения введите 'end'):\n";
        while (in >> element)
        {
            v.add(element);
        }
        in.clear();
        return in;
    }*/
    //friend std::istream& operator>>(std::istream& in, _vector<T>& v)
    //{
    //    v.vec.clear();  // Очищаем текущий вектор
    //    std::string input;

    //    std::cout << "Введите элементы (для завершения введите 'end'):\n";

    //    while (true)
    //    {
    //        in >> input;  // Считываем ввод как строку
    //        if (input == "end")
    //        {
    //            break;  // Выход из цикла при вводе 'end'
    //        }

    //        try
    //        {
    //            // Пробуем преобразовать строку в число
    //            T element = static_cast<T>(std::stod(input)); // Преобразуем строку в число
    //            v.add(element);  // Добавляем элемент в вектор
    //        }
    //        catch (const std::invalid_argument& e)
    //        {
    //            std::cout << "Ошибка: \"" << input << "\" не является числом. Попробуйте еще раз.\n";
    //        }
    //        catch (const std::out_of_range& e)
    //        {
    //            std::cout << "Ошибка: число \"" << input << "\" выходит за пределы допустимого диапазона.\n";
    //        }
    //    }
    //    in.clear();
    //    return in;
    //}
    
    friend std::istream& operator>>(std::istream& in, _vector<T>& v)
    {
        cout << "Введите элементы (для завершения введите 'end'):\n";
        v.clear();  // Очищаем текущий вектор
        T element;
        while (in >> element)
        {  // Читаем элементы
            v.add(element);
        }
        return in;
    }
    // 
    T& operator[](int index)
    {
        if (index < 0 || index >= vec.size())
        {
            throw std::out_of_range("Индекс выходит за пределы вектора.");
        }
        return vec[index]; // Возвращаем ссылку для модификации
    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= vec.size())
        {
            throw std::out_of_range("Индекс выходит за пределы вектора.");
        }
        return vec[index]; // Константная версия для доступа только для чтения
    }

    // Оператор копирования
    _vector& operator=(const _vector& other)
    {
        if (this != &other)
        {
            vec = other.vec;
            name = other.name;
        }
        return *this;
    }

    // Оператор перемещения
    _vector& operator=(_vector&& other) noexcept
    {
        if (this != &other)
        {
            vec = std::move(other.vec);
            name = std::move(other.name);
        }
        return *this;
    }

    //Арифметические операторы
    // Оператор сложения
    _vector<T> operator +(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] + other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }

    // Оператор вычитания
    _vector<T> operator -(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] - other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }

    // Оператор поэлементного умножения
    _vector<T> operator *(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] * other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }
    _vector<T> operator /(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
            for (int i = 0; i < vec.size(); ++i)
            {
                if (other.vec[i] != 0)
                {
                    result.vec[i] = vec[i] / other.vec[i];
                }
                else
                {
                    result.vec[i] = NAN;
                    //result.vec[i] = 0;
                }

            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }
    //деление на скаляр
    _vector<T> operator /(T constant) const
    {
        _vector<T> result(0, vec.size());
        for (int i = 0; i < vec.size(); ++i)
        {
            if (constant != 0)
            {
                result.vec[i] = vec[i] / constant;
            }
            else
            {
                result.vec[i] = NAN;  // Используем NAN для обозначения ошибки деления на ноль
            }
        }
        return result;
    }
    _vector<T> operator %(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] % other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }
    _vector<T> operator ^(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = pow(vec[i], other.vec[i]);
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }
    // Оператор скалярного произведения
    T scalar_product(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            T result = 0;
            for (int i = 0; i < vec.size(); ++i)
            {
                result += vec[i] * other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }

    // Оператор умножения на константу
    _vector<T> operator *(T constant) const
    {
        _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
        for (int i = 0; i < vec.size(); ++i)
        {
            result.vec[i] = vec[i] * constant;
        }
        return result;
    }

    /*_vector& operator =(const _vector& other)
    {
        if (this != &other)
        {
            vec = other.vec;
        }
        return *this;
    }*/
    //возведение в степень константу
    _vector<T> operator ^(T constant) const
    {
        _vector<T> result(0, vec.size());  // Создаем результирующий вектор того же размера
        for (int i = 0; i < vec.size(); ++i)
        {
            result.vec[i] = pow(vec[i], constant);
        }
        return result;
    }
    // Оператор +=
    _vector& operator+=(const _vector& other)
    {
        if (vec.size() == other.vec.size())
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                vec[i] += other.vec[i];
            }
        }
        else
        {
            throw std::invalid_argument("Вектора должны быть одинакового размера.");
        }
        return *this;
    }

    // Оператор -=
    _vector& operator-=(const _vector& other)
    {
        if (vec.size() == other.vec.size())
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                vec[i] -= other.vec[i];
            }
        }
        else
        {
            throw std::invalid_argument("Вектора должны быть одинакового размера.");
        }
        return *this;
    }

    // Оператор *= (поэлементное умножение)
    _vector& operator*=(const _vector& other)
    {
        if (vec.size() == other.vec.size())
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                vec[i] *= other.vec[i];
            }
        }
        else
        {
            throw std::invalid_argument("Вектора должны быть одинакового размера.");
        }
        return *this;
    }

    // Оператор *= (умножение на скаляр)
    _vector& operator*=(T scalar)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            vec[i] *= scalar;
        }
        return *this;
    }

    // Оператор /= (поэлементное деление)
    _vector& operator/=(const _vector& other)
    {
        if (vec.size() == other.vec.size())
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                if (other.vec[i] != 0)
                {
                    vec[i] /= other.vec[i];
                }
                else
                {
                    vec[i] = NAN; // Если деление на 0, присвоить NaN
                }
            }
        }
        else
        {
            throw std::invalid_argument("Вектора должны быть одинакового размера.");
        }
        return *this;
    }
    //деление на скаляр
    _vector<T> operator /=(T constant) const
    {
        _vector<T> result(0, vec.size());
        for (int i = 0; i < vec.size(); ++i)
        {
            if (constant != 0)
            {
                result.vec[i] = vec[i] / constant;
            }
            else
            {
                result.vec[i] = NAN;  // Используем NAN для обозначения ошибки деления на ноль
            }
        }

        return result;
    }

    // Оператор логического И (поэлементное сравнение)
    _vector<bool> operator&&(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<bool> result(false, vec.size());
            for (int i = 0; i < vec.size(); ++i)
            {
                result[i] = vec[i] && other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }

    // Оператор логического ИЛИ (поэлементное сравнение)
    _vector<bool> operator||(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<bool> result(false, vec.size());
            for (int i = 0; i < vec.size(); ++i)
            {
                result[i] = vec[i] || other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("Вектора должны быть одинакового размера.");
    }

    // Оператор сравнения на равенство
    bool operator==(const _vector& other) const
    {
        //return vec == other.vec;
        return vec.size() == other.vec.size() && vec == other.vec;
    }

    // Оператор сравнения на неравенство
    bool operator!=(const _vector& other) const
    {
        return vec != other.vec;
    }



};

#endif



