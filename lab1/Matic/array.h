#ifndef ARRAY
#define ARRAY
#include<iostream>
#include<vector>
#include <cmath>      // ��� pow � NAN
#include <stdexcept>  // ��� ����������
#include"const.h"
#include<string>

#include <ranges>

using namespace std;

//��� ������ �� � �������������� ������
//�������� �� ������?
//������� ������ ��������������
//������ ��?

//
// ��������� �������� - ���, ������, �������� ���������
// ��������� ������� ��������
//
//�������� ��� ��������� �������� ������� ����



/// ������� ���������� ����������
/// ����������� ��� ���������
/// �������� ������ 
/// ������ �������� � �������� �� ����
/// 

template<typename T>
class _array {
public:
    // ����������� � �����������
    //_vector(T a = 0, int size = 1) : vec(size, a) {}
    _array(T a = T{}, int size = 1, string name = _undName) : vec(size, a), name(name) {}

    // ����������� �� ���������
   // _vector() {}

    // ����������� �����������
    _array(const _array& other) : vec(other.vec), name(other.name) {}

    // ����������� �����������
    _array(_array&& other) noexcept : vec(std::move(other.vec)), name(std::move(other.name)) {}


    // ����������
    ~_array() {}

    //T& operator[](int index)
    //{
    //    return vec[index]; // ���������� ������ ��� �����������
    //}

    //const T& operator[](int index) const
    //{
    //    return vec[index]; // ����������� ������ ��� ������� ������ ��� ������
    //}

    



    


    //////////////////////////////////////////////////////////////////////////
    // ������
    int size() const
    {
        return vec.size();
    }

    std::vector<T> get() const
    {
        return vec;
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
    // ������ ������ ����������
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
        vec.clear(); // ������� ����������� �������
    }
    bool isBigger(const _array& other) const
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
    bool isLess(const _array& other) const
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
    bool isEquals(const _array& other) const
    {
        /*if (vec::value_type != other::value_type)
        {
            cout << "���� �������� �� ���������";
        }*/
        if (vec.size() == other.size())
        {
            return true;
        }
        else
        {
            //cout << "������� �������� �� ���������";
            return false;
        }
    }
    //in terms of size
    //template<typename G>
    //bool isEquals(const _vector<G>& other) const
    //{
    //    // �������� ����� ��������
    //    if constexpr (!std::is_same<G, typename decltype(other)::value_type>::value)
    //    {
    //        std::cout << "���� �������� �� ���������." << std::endl;
    //        //return false;
    //    }

    //    // �������� ��������
    //    if (this->size() != other.size())
    //    {
    //        std::cout << "������� �������� �� ���������." << std::endl;
    //        return false;
    //    }

    //    // ���� ���� ��������� � ������� �����
    //    return true;
    //}
    /*bool isEquals(const _vector& other) const
    {
        if (vec::value_type != other::value_type)
        {
            cout << "���� �������� �� ���������";
        }
        if (vec.size() == other.size())
        {
            return true;
        }
        else
        {
            cout << "������� �������� �� ���������";
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
    _array<T> filter(Func func) const
    {
        _array<T> result;
        for (const auto& item : vec)
        {
            if (func(item))
            {
                result.add(item);
            }
        }
        return result;
    }

    // ����� map
    template <typename Func, typename U = decltype(std::declval<Func>()(std::declval<T>()))>
    _array<U> map(Func func) const
    {
        _array<U> result;
        for (const auto& item : vec)
        {
            result.add(func(item));
        }
        return result;
    }
    void resize(size_t newSize, const T& value = T())
    {
        vec.resize(newSize, value);
    }

    void add(T element)
    {
        vec.push_back(element);
    }
    void pop_back()
    {
        vec.pop_back();
    }

    /*void description() const
    {
        cout << "\n _vector ��� ������� ��� ������� vector\n";
        cout << " _vector ����� ����������, ��������, ������, ��������� � �������(������� �����, ��� ���������� ������� � ������� ������� �������)\n";
        cout << " � �������������� ��������, ������� _vector ������ ���� ���������\n";
        cout << " �� ������������� ������������ _vector ��� ������������� ������ � ������ ����������� ��������\n\n";

    }*/
    //void help() const
    //{
    //    /*cout << " _vector ������������ ��������� ��������, ������, � �������: \n";
    //    cout << " \"+\", \"-\",\"*\",\"/\",\"%\"  \n";*/
    //    cout << "_vector ������������ ��������� �������� � ������:\n";
    //    cout << "+, -, *, /, %, ^ (���������� � �������)\n";
    //    cout << "���������: ==, !=\n";
    //    cout << "���������� ��������: &&, ||\n";
    //    cout << "������: size(), add(element), print(), get()\n\n";

    //}
    //

    //void help(const std::string& query) const
    //{
    //    // �������� ������� �� �������� ��� �������
    //    if (query == "+")
    //    {
    //        cout << "_vector ������������ �������� �������� (+).\n";
    //        cout << "��� �������� �������� ������������ ��������������� ��������.\n";
    //        cout << "������: [1, 2, 3] + [4, 5, 6] = [5, 7, 9]\n";
    //    }
    //    else if (query == "-")
    //    {
    //        cout << "_vector ������������ �������� ��������� (-).\n";
    //        cout << "��� ��������� �������� ���������� ��������������� ��������.\n";
    //        cout << "������: [1, 2, 3] - [4, 5, 6] = [-3, -3, -3]\n";
    //    }
    //    else if (query == "*")
    //    {
    //        cout << "_vector ������������ �������� ��������� (*) �����������.\n";
    //        cout << "������: [1, 2, 3] * [4, 5, 6] = [4, 10, 18]\n";
    //    }
    //    else if (query == "/")
    //    {
    //        cout << "_vector ������������ �������� ������� (/).\n";
    //        cout << "��� ������� ��������� �������� ����������� ������� �� ����.\n";
    //        cout << "� ������ ������� �� 0 � ��������������� ������� ������������ NAN.\n";
    //        cout << "������: [4, 9, 0] / [2, 3, 0] = [2, 3, NAN]\n";
    //    }
    //    else if (query == "&&")
    //    {
    //        cout << "_vector ������������ ���������� �������� � (&&).\n";
    //        cout << "������: [1, 0, 1] && [1, 1, 0] = [1, 0, 0]\n";
    //    }
    //    else if (query == "||")
    //    {
    //        cout << "_vector ������������ ���������� �������� ��� (||).\n";
    //        cout << "������: [1, 0, 1] || [1, 1, 0] = [1, 1, 1]\n";
    //    }
    //    else if (query == "^")
    //    {
    //        cout << "_vector ������������ ���������� � ������� (^).\n";
    //        cout << "������: [1, 2, 3] ^ [4, 5, 6] = [1, 32, 729] (������������ ���������� � �������)\n";
    //    }
    //    else if (query == "description")
    //    {
    //        cout << "����� description() ������� ����� ���������� � ������ _vector.\n";
    //        cout << "�������� �������� ��������� ���������, ������ � ��������� ��������.\n";
    //    }
    //    else if (query == "print")
    //    {
    //        cout << "����� print() ������� ��� �������� ������� � ������, ����������� ���������.\n";
    //        cout << "������: ��� _vector<int> v{1, 2, 3} ����� v.print() �������: 1 2 3\n";
    //    }
    //    else if (query == "size")
    //    {
    //        cout << "����� size() ���������� ���������� ��������� �������.\n";
    //        cout << "������: ��� ������� _vector<int> v{1, 2, 3} ����� v.size() ������ 3.\n";
    //    }
    //    else if (query == "add")
    //    {
    //        cout << "����� add(element) ��������� ������� � ����� �������.\n";
    //        cout << "������: ��� ������� _vector<int> v{1, 2} ����� v.add(3) ������� ������ �� {1, 2, 3}.\n";
    //    }
    //    else if (query == "scalar_product")
    //    {
    //        cout << "����� scalar_product(const _vector&) ���������� ��������� ������������ ���� ��������.\n";
    //        cout << "������: ��� �������� _vector<int> v1{1, 2, 3} � _vector<int> v2{4, 5, 6},\n";
    //        cout << "����� v1.scalar_product(v2) ������: 1*4 + 2*5 + 3*6 = 32.\n";
    //    }
    //    else
    //    {
    //        cout << "�������� ��� ����� \"" << query << "\" �� �������������� ��� �� ������.\n";
    //        cout << "����������, ����������� ���� �� ��������� ������:\n";
    //        cout << "\"+\", \"-\", \"*\", \"/\", \"%\", \"^\", \"&&\", \"||\", \"description\", \"print\", \"size\", \"add\", \"scalar_product\".\n";
    //    }

    //    cout << "\n";
    //}

    

private:
    string name{"UNDEFINED"};
    vector<T> vec;


public:

    ////////////////////////////////////////////////////////////////////////////////
    // ���������
    // 
    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& out, const _array<T>& v)
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

    // ���������� ��������� �����
    /*friend std::istream& operator>>(std::istream& in, _vector<T>& v)
    {
        T element;
        std::cout << "������� �������� (��� ���������� ������� 'end'):\n";
        while (in >> element)
        {
            v.add(element);
        }
        in.clear();
        return in;
    }*/
    //friend std::istream& operator>>(std::istream& in, _vector<T>& v)
    //{
    //    v.vec.clear();  // ������� ������� ������
    //    std::string input;

    //    std::cout << "������� �������� (��� ���������� ������� 'end'):\n";

    //    while (true)
    //    {
    //        in >> input;  // ��������� ���� ��� ������
    //        if (input == "end")
    //        {
    //            break;  // ����� �� ����� ��� ����� 'end'
    //        }

    //        try
    //        {
    //            // ������� ������������� ������ � �����
    //            T element = static_cast<T>(std::stod(input)); // ����������� ������ � �����
    //            v.add(element);  // ��������� ������� � ������
    //        }
    //        catch (const std::invalid_argument& e)
    //        {
    //            std::cout << "������: \"" << input << "\" �� �������� ������. ���������� ��� ���.\n";
    //        }
    //        catch (const std::out_of_range& e)
    //        {
    //            std::cout << "������: ����� \"" << input << "\" ������� �� ������� ����������� ���������.\n";
    //        }
    //    }
    //    in.clear();
    //    return in;
    //}
    
    friend std::istream& operator>>(std::istream& in, _array<T>& v)
    {
        cout << "������� �������� (��� ���������� ������� 'end'):\n";
        v.clear();  // ������� ������� ������
        T element;
        while (in >> element)
        {  // ������ ��������
            v.add(element);
        }
        return in;
    }
    // 
    T& operator[](int index)
    {
        if (index < 0 || index >= vec.size())
        {
            throw std::out_of_range("������ ������� �� ������� �������.");
        }
        return vec[index]; // ���������� ������ ��� �����������
    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= vec.size())
        {
            throw std::out_of_range("������ ������� �� ������� �������.");
        }
        return vec[index]; // ����������� ������ ��� ������� ������ ��� ������
    }

    // �������� �����������
    _array& operator=(const _array& other)
    {
        if (this != &other)
        {
            vec = other.vec;
            name = other.name;
        }
        return *this;
    }

    // �������� �����������
    _array& operator=(_array&& other) noexcept
    {
        if (this != &other)
        {
            vec = std::move(other.vec);
            name = std::move(other.name);
        }
        return *this;
    }

    // �������� ��������� �� ���������
    bool operator==(const _array& other) const
    {
        //return vec == other.vec;
        return vec.size() == other.vec.size() && vec == other.vec;
    }

    // �������� ��������� �� �����������
    bool operator!=(const _array& other) const
    {
        return vec != other.vec;
    }



};

#endif



