#include "vector.h"

template<typename T>
_vector::_vector(T a, int size)
{
	vec.resize(size, a);
}

_vector::_vector()
{

}

_vector::~_vector()
{
}

double _vector::operator[](int index) const
{
	return vec[index];
}

vector<double> _vector::get() const
{
	return vec;
}
//void _vector::operator+(const _vector&, const _vector&)
//{
//}

_vector& _vector::operator=(const _vector&)
{
	return *this;
}
