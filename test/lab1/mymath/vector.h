#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;



/// ������� ���������� ����������
/// ����������� ��� ���������
/// �������� ������ 
/// ������ �������� � �������� �� ����
/// 

template<typename T>
class _vector {
public:
    // ����������� � �����������
    _vector(T a = 0, int size = 1) : vec(size, a) {}

    // ����������� �� ���������
    _vector() {}

    // ����������
    ~_vector() {}

    T& operator[](int index)
    {
        return vec[index]; // ���������� ������ ��� �����������
    }

    const T& operator[](int index) const
    {
        return vec[index]; // ����������� ������ ��� ������� ������ ��� ������
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
    // ���������
    // �������� ��������
    _vector<T> operator +(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] + other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }

    // �������� ���������
    _vector<T> operator -(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] - other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }

    // �������� ������������� ���������
    _vector<T> operator *(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] * other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }
    _vector<T> operator /(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
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
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }
    _vector<T> operator %(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = vec[i] % other.vec[i];
            }
            return result;
        }
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }
    _vector<T> operator ^(const _vector& other) const
    {
        if (vec.size() == other.vec.size())
        {
            _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
            for (int i = 0; i < vec.size(); ++i)
            {
                result.vec[i] = pow(vec[i], other.vec[i]);
            }
            return result;
        }
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }
    // �������� ���������� ������������
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
        throw std::invalid_argument("������� ������ ���� ����������� �������.");
    }

    // �������� ��������� �� ���������
    _vector<T> operator *(T constant) const
    {
        _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
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
    //���������� � ������� ���������
    _vector<T> operator ^(T constant) const
    {
        _vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
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



