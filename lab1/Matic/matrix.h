#ifndef MATRIX
#define MATRIX
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class _matrix {
public:
    // Конструктор с параметрами (инициализация матрицы значением 'a' и заданным размером)
    _matrix(T a = 0, int rows = 1, int cols = 1) : mat(rows, vector<T>(cols, a)) {}

    // Конструктор по умолчанию
    /*_matrix() {} = default;*/

    // Деструктор
    ~_matrix() {}

    // Доступ к элементам матрицы (по индексу строки и столбца)
    T& operator()(int row, int col)
    {
        return mat[row][col]; // Возвращаем ссылку для модификации
    }

    const T& operator()(int row, int col) const
    {
        return mat[row][col]; // Константная версия для доступа только для чтения
    }

    // Вывод матрицы на экран
    void print() const
    {
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Оператор сложения матриц
    /*_matrix<T> operator +(const _matrix& other) const
    {
        if (mat.size() == other.mat.size() && mat[0].size() == other.mat[0].size())
        {
            _matrix<T> result(0, mat.size(), mat[0].size());
            for (int i = 0; i < mat.size(); ++i)
            {
                for (int j = 0; j < mat[i].size(); ++j)
                {
                    result(i, j) = mat[i][j] + other.mat[i][j];
                }
            }
            return result;
        }
        throw std::invalid_argument("Матрицы должны быть одинакового размера.");
    }*/

    _matrix<T> operator +(const _matrix& other) const
    {
        if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size())
        {
            cout << "Предупреждение: Размеры матриц не совпадают. Операция сложения пропущена." << endl;
            return *this;  // Возвращаем текущую матрицу без изменений
        }

        _matrix<T> result(0, mat.size(), mat[0].size());  // Создаем результирующую матрицу
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
    // Оператор вычитания матриц
    _matrix<T> operator -(const _matrix& other) const
    {
        if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size())
        {
            cout << "Предупреждение: Размеры матриц не совпадают. Операция вычитания пропущена." << endl;
            return *this;  // Возвращаем текущую матрицу без изменений
        }

        _matrix<T> result(0, mat.size(), mat[0].size());  // Создаем результирующую матрицу
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }


    // Оператор умножения матриц
    _matrix<T> operator *(const _matrix& other) const
    {
        if (mat[0].size() != other.mat.size())
        {
            cout << "Предупреждение: Размеры матриц не совпадают. Операция умножения пропущена." << endl;
            return *this;  // Возвращаем текущую матрицу без изменений
        }

        _matrix<T> result(0, mat.size(), mat[0].size());  // Создаем результирующую матрицу
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }
    /*_matrix<T> operator *(const _matrix& other) const
    {
        if (mat[0].size() == other.mat.size())
        {
            _matrix<T> result(0, mat.size(), other.mat[0].size());
            for (int i = 0; i < mat.size(); ++i)
            {
                for (int j = 0; j < other.mat[0].size(); ++j)
                {
                    for (int k = 0; k < mat[0].size(); ++k)
                    {
                        result(i, j) += mat[i][k] * other.mat[k][j];
                    }
                }
            }
            return result;
        }
        throw std::invalid_argument("Число столбцов первой матрицы должно быть равно числу строк второй.");
    }*/

    // Оператор умножения матрицы на константу
    _matrix<T> operator *(T constant) const
    {
        _matrix<T> result(0, mat.size(), mat[0].size());
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                result(i, j) = mat[i][j] * constant;
            }
        }
        return result;
    }

    // Получение количества строк
    int rows() const
    {
        return mat.size();
    }

    // Получение количества столбцов
    int cols() const
    {
        return mat[0].size();
    }

    // Оператор присваивания
    _matrix& operator =(const _matrix& other)
    {
        if (this != &other)
        {
            mat = other.mat;
        }
        return *this;
    }

private:
    vector<vector<T>> mat; // Двумерный вектор для хранения элементов матрицы
};

#endif
