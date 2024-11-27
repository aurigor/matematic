#ifndef INTAGRATION
#define INTAGRATION

#include <iostream>
#include <cmath>
#include"funct.h"
#include"array.h"
#include"methods.h"

using namespace std;

template<typename... Args>
double intagration(double a, double b, _function<double, Args...> f)
{

}


double intagration(double a, double b, _function<double, double> f)
{
	int N = 512;
	double h = double((b - a)/(N));
	double result = f(a) + f(b);
	for (int i = 0; i < N-2; i += 2)
	{
		result += 4 * (f(a + (i + 1) * h)) + 2 * f(a + (i + 2) * h);
	}
	result += 4 * (f(a + (N - 1) * h));

	result *= h/3.0;
	return result;
}

#endif