#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;



/// сделать обработчик исключений
/// перегрузить все операторы
/// добавить методы 
/// решить проблему с делением на ноль
/// 

template<typename T>
class _vector {
public:
    // Конструктор с параметрами
    _vector(T a = 0, int size = 1) : vec(size, a) {}

    // Конструктор по умолчанию
    _vector() {}

    // Деструктор
    ~_vector() {}

    T& operator[](int index)
    {
        return vec[index]; // Возвращаем ссылку для модификации
    }

    const T& operator[](int index) const
    {
        return vec[index]; // Константная версия для доступа только для чтения
    }

    std::vector<T> get() const
    {
        return vec;
    }

    void print() const
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    }

    void add(T element) 
    {
        vec.push_back(element);
    }



    ////////////////////////////////////////////////////////////////////////////////
    // операторы
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
                if (other.vec[i]!=0)
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
    _vector& operator =(const _vector& other)
    {
        if (this != &other)
        {
            vec = other.vec;
        }
        return *this;
    }
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


    int size() const
    {
        return vec.size();
    }

    

private:
    vector<T> vec;
};

#endif



