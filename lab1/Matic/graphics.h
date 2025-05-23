// plotting.h
#ifndef GRAPHIC
#define GRAPHIC

#include <vector>
#include <cstdio>  // ��� FILE* � _popen/_pclose
#include <iostream>  // ��� std::cerr
#include <string>  // ��� std::string

#include "vector.h"
// ������� ��� �������� Gnuplot
void openGnuplot();

// ������� ��� �������� Gnuplot
void wcloseGnuplot();
void closeGnuplot();

// ������� ��� ���������� ������� (��������� ������ x � y ��� ����� � �������)
void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y);


//void plotSplineAndExactFunction(const std::vector<double>& original_x, const std::vector<double>& original_y,
//    const std::vector<double>& spline_x, const std::vector<double>& spline_y,
//    const std::vector<double>& exact_x, const std::vector<double>& exact_y);
void plotSplineAndExactFunction(const _vector<double>& original_x, const _vector<double>& original_y,
    const _vector<double>& spline_x, const _vector<double>& spline_y,
    const _vector<double>& exact_x, const _vector<double>& exact_y);




#endif  
