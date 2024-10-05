// plotting.h
#ifndef GRAPHIC
#define GRAPHIC

#include <vector>
#include <cstdio>  // Для FILE* и _popen/_pclose
#include <iostream>  // Для std::cerr
#include <string>  // Для std::string

// Функция для открытия Gnuplot
void openGnuplot();

// Функция для закрытия Gnuplot
void wcloseGnuplot();
void closeGnuplot();

// Функция для построения графика (принимает данные x и y для точек и сплайна)
void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y);


void plotSplineAndExactFunction(const std::vector<double>& original_x, const std::vector<double>& original_y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y,
    const std::vector<double>& exact_x, const std::vector<double>& exact_y);




#endif  
