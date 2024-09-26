#include "vector.h"

_vector::_vector(double a, int size)
{
	vec.resize(size, a);
}

_vector::~_vector()
{
}

//void _vector::operator+(const _vector&, const _vector&)
//{
//}

_vector& _vector::operator=(const _vector&)
{
	return *this;
}
