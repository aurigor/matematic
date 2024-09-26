#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<vector>

using namespace std;

//export vec {
	class _vector {
	public:

		//template<typename T>
		_vector(double a, int size);
		~_vector();


		//void operator +(const _vector&, const _vector&);
		_vector& operator =(const _vector&);

	private:
		vector<double> vec;
	};

//};

#endif