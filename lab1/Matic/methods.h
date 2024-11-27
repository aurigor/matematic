#ifndef METHODS
#define METHODS
#include<iostream>
#include<vector>
#include <cmath>      // Для pow и NAN
#include <stdexcept>  // Для исключений
#include"const.h"
#include<string>
#include<map>"
#include"vector.h"

#include <ranges>

using namespace std;
void progonka(_vector<double> a, _vector<double> b, _vector<double> c, _vector<double> d, int size, _vector<double>& out)
{
	/*if (abs(b) >= abs(a) + abs(c))
	{*/
		std::map<char, std::vector<double>> coef;

		coef['P'].resize(size);
		coef['Q'].resize(size);
		coef['A'].resize(size);
		coef['B'].resize(size);
		coef['C'].resize(size);
		coef['F'].resize(size);
		//c = b*5;
		//b = b*( - 1);
		coef['A'][0] = a[0];
		coef['B'][0] = b[0];
		coef['C'][0] = c[0];
		for (int i = 1; i < size-1; ++i)
		{
			coef['A'][i] = a[i];
			coef['B'][i] = b[i];
			coef['C'][i] = c[i];
		}
		coef['A'][size-1] = a[size-1];
		coef['B'][size-1] = b[size-1];
		coef['C'][size-1] = c[size-1];

		_vector<double> y1;
		y1.resize(size);
		for (int i = 0; i <= size-1; ++i)
		{
			coef['F'][i] = d[i];
		}

		coef['P'][0] = -coef['C'][0] / coef['B'][0];
		coef['Q'][0] = coef['F'][0] / coef['B'][0];
		for (int i = 1; i <= size-1; ++i)
		{
			coef['P'][i] = -coef['C'][i] / (coef['A'][i] * coef['P'][i - 1] + coef['B'][i]);
			coef['Q'][i] = (coef['F'][i] - coef['A'][i] * coef['Q'][i - 1]) / (coef['A'][i] * coef['P'][i - 1] + coef['B'][i]);
		}

		y1[size-1] = (coef['F'][size-1] - coef['Q'][size - 2] * coef['A'][size-1]) / (coef['B'][size-1] + coef['P'][size - 2] * coef['A'][size-1]);
		for (int i = size-1; i >= 1; --i)
		{
			y1[i - 1] = coef['P'][i - 1] * y1[i] + coef['Q'][i - 1];
		}
		out = y1;
		/*for (int i = 0; i <= size; ++i)
		{
			out[i] = y1[i];
		}*/

	/*}
	else
	{
		cout << "not have direct diagonal " << endl;
	}*/

}
//void progonka(double a, double b, double c, double left, double right, int size)
//{
//	if (abs(b) >= abs(a) + abs(c))
//	{
//		std::map<char, std::vector<double>> coef;
//
//		coef['P'].resize(size + 1);
//		coef['Q'].resize(size + 1);
//		coef['A'].resize(size + 1);
//		coef['B'].resize(size + 1);
//		coef['C'].resize(size + 1);
//		coef['F'].resize(size + 1);
//		b = -b;
//		coef['A'][0] = 0;
//		coef['B'][0] = -1;
//		coef['C'][0] = 0;
//		for (int i = 1; i < size; ++i)
//		{
//			coef['A'][i] = a;
//			coef['B'][i] = b;
//			coef['C'][i] = c;
//		}
//		coef['A'][size] = 0;
//		coef['B'][size] = -1;
//		coef['C'][size] = 0;
//
//		std::vector<double> y1;
//		y1.resize(size + 1);
//		double dx = lx / (size + 1);
//		coef['F'][0] = left;
//		for (int i = 1; i < size; ++i)
//		{
//			coef['F'][i] = d(ro[i], ro_nd[i], dx);
//		}
//		coef['F'][size] = right
//		cout << "\n different fi is " << coef['F'][0] - coef['F'][size] << "; \n";
//
//		coef['P'][0] = coef['C'][0] / coef['B'][0];
//		coef['Q'][0] = -coef['F'][0] / coef['B'][0];
//		for (int i = 1; i <= size; ++i)
//		{
//			coef['P'][i] = coef['C'][i] / (-coef['A'][i] * coef['P'][i - 1] + coef['B'][i]);
//			coef['Q'][i] = (-coef['F'][i] + coef['A'][i] * coef['Q'][i - 1]) / (-coef['A'][i] * coef['P'][i - 1] + coef['B'][i]);
//		}
//
//		y1[size] = (coef['F'][size] - coef['Q'][size - 1] * coef['A'][size]) / (-coef['B'][size] + coef['P'][size - 1] * coef['A'][size]);
//		for (int i = size; i >= 1; --i)
//		{
//			y1[i - 1] = coef['P'][i - 1] * y1[i] + coef['Q'][i - 1];
//		}
//		for (int i = 0; i <= size; ++i)
//		{
//			fi[i] = y1[i];
//		}
//		(*f->fi) = y1;
//		WritenInFile(x, y1, format("test_{}", 0), sizeX);
//	}
//	else
//	{
//		cout << "not have direct diagonal " << endl;
//	}
//	 
//}





#endif



