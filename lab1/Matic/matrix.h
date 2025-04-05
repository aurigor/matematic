#ifndef MATRIX
#define MATRIX
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class _matrix {
public:
    // ����������� � ����������� (������������� ������� ��������� 'a' � �������� ��������)
    _matrix(T a = 0, int rows = 1, int cols = 1) : mat(rows, vector<T>(cols, a)) {}

    // ����������� �� ���������
    /*_matrix() {} = default;*/

    // ����������
    ~_matrix() {}

    // ������ � ��������� ������� (�� ������� ������ � �������)
    T& operator()(int row, int col)
    {
        return mat[row][col]; // ���������� ������ ��� �����������
    }

    const T& operator()(int row, int col) const
    {
        return mat[row][col]; // ����������� ������ ��� ������� ������ ��� ������
    }

    // ����� ������� �� �����
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

    // �������� �������� ������
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
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }*/

    _matrix<T> operator +(const _matrix& other) const
    {
        if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size())
        {
            cout << "��������������: ������� ������ �� ���������. �������� �������� ���������." << endl;
            return *this;  // ���������� ������� ������� ��� ���������
        }

        _matrix<T> result(0, mat.size(), mat[0].size());  // ������� �������������� �������
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
    // �������� ��������� ������
    _matrix<T> operator -(const _matrix& other) const
    {
        if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size())
        {
            cout << "��������������: ������� ������ �� ���������. �������� ��������� ���������." << endl;
            return *this;  // ���������� ������� ������� ��� ���������
        }

        _matrix<T> result(0, mat.size(), mat[0].size());  // ������� �������������� �������
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }


    // �������� ��������� ������
    _matrix<T> operator *(const _matrix& other) const
    {
        if (mat[0].size() != other.mat.size())
        {
            cout << "��������������: ������� ������ �� ���������. �������� ��������� ���������." << endl;
            return *this;  // ���������� ������� ������� ��� ���������
        }

        _matrix<T> result(0, mat.size(), mat[0].size());  // ������� �������������� �������
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
        throw std::invalid_argument("����� �������� ������ ������� ������ ���� ����� ����� ����� ������.");
    }*/

    // �������� ��������� ������� �� ���������
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

    // ��������� ���������� �����
    int rows() const
    {
        return mat.size();
    }

    // ��������� ���������� ��������
    int cols() const
    {
        return mat[0].size();
    }

    // �������� ������������
    _matrix& operator =(const _matrix& other)
    {
        if (this != &other)
        {
            mat = other.mat;
        }
        return *this;
    }

private:
    vector<vector<T>> mat; // ��������� ������ ��� �������� ��������� �������
};

#endif
