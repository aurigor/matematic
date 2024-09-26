#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class _vector {
public:
    // ����������� � �����������
    _vector(T a = 0, int size = 1) : vec(size, a)
    {
        // ������������� ������� ��������� 'a' � �������� 'size'
    }

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

    std::vector<double> get() const
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

    int size() const
    {
        return vec.size();
    }

    _vector& operator =(const _vector& other)
    {
        if (this != &other)
        {
            vec = other.vec;
        }
        return *this;
    }

private:
    vector<T> vec;
};

#endif





//#ifndef VECTOR
//#define VECTOR
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////export {
//	template<typename T>
//	class _vector {
//	public:
//
//		_vector(T a=0, int size=1);
//		//template<typename T>
//		_vector();
//		~_vector();
//
//		T& operator[](int index)
//		{
//			return vec[index];
//		}
//		const T& operator[](int index) const
//		{
//			return vec[index]; 
//		}
//		std::vector<double> get() const;
//		
//		//template<typename Cont>
//		void print()
//		{
//			/*for (const auto& c : cont)
//			{
//				std::cout << c << " ";
//			}
//			std::cout << "\n";*/
//			for (int i = 0; i < vec.size(); ++i)
//			{
//				std::cout << vec[i] << " ";
//			}
//			std::cout << "\n";
//		}
//		_vector<T> operator +(const _vector& other) const
//		{
//			if (vec.size() == other.vec.size())
//			{
//				_vector<T> result(0, vec.size());  // ������� �������������� ������ ���� �� �������
//				for (int i = 0; i < vec.size(); ++i)
//				{
//					result.vec[i] = vec[i] + other.vec[i];
//				}
//				return result;
//			}
//			throw std::invalid_argument("������� ������ ���� ����������� �������.");
//		}
//		int size() const
//		{
//			return vec.size();
//		}
//		
//		_vector& operator =(const _vector&);
//
//	private:
//		vector<T> vec;
//	};
//
//	//struct vecs{
//	//	_vector* v;
//
//	//	template<typename Cont>
//	//	void print(const Cont& cont)
//	//	{
//	//		/*for (const auto& c : cont)
//	//		{
//	//			std::cout << c << " ";
//	//		}
//	//		std::cout << "\n";*/
//	//		for (int i=0;i<cont.size();++i)
//	//		{
//	//			std::cout << cont[i] << " ";
//	//		}
//	//		std::cout << "\n";
//	//	}
//	//	//void print()
//	//};
//
//
////}
//
//
//#endif