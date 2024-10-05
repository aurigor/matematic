// plotting.cpp
#include "graphics.h"
#include <sstream>  // ��� std::ostringstream
#include <thread>   // ��� std::this_thread::sleep_for
#include <chrono>   // ��� std::chrono


#include <stdio.h>
#include <stdlib.h>
// ���������� ���������� ��� ��������� �� Gnuplot
FILE* gnuplotPipe = nullptr;

// ������� ��� �������� Gnuplot
void openGnuplot()
{
    //gnuplotPipe = _popen("gnuplot -persist", "w");
#ifdef WIN32
    /*FILE* pipe*/ gnuplotPipe = _popen("gnuplot -persist", "w");
    /*FILE* pipe*/  //gnuplotPipe = _popen("pgnuplot -persist", "w");
#else
    /*FILE* pipe*/ gnuplotPipe = popen("gnuplot -persist", "w");
#endif
    if (!gnuplotPipe)
    {
        std::cerr << "������: �� ������� ������� Gnuplot." << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Gnuplot ������� ������." << std::endl;
    }
}

void wcloseGnuplot()
{
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    closeGnuplot();
}

// ������� ��� �������� Gnuplot
//void closeGnuplot()
//{
//    std::cout << "call close \n";
//    if (gnuplotPipe)
//    {
//        //system("taskkill /IM gnuplot.exe /F");
//        //pclose(gnuplotPipe);
////#ifdef WIN32
////        _pclose(gnuplotPipe);
////#else
////        pclose(gnuplotPipe);
////#endif
//
//        fputs("exit gnuplot\n", gnuplotPipe);
//        fflush(gnuplotPipe);
//
//        std::cout << "������� ��������� ������� exit...\n";
//        fprintf(gnuplotPipe, "exit\n");
//        fputs("exit\n", gnuplotPipe);  // ���������� ������� ������
//        fflush(gnuplotPipe);  // ���������� �����
//
//        fputs("quit\n", gnuplotPipe);  // ���������� ������� ������
//        fflush(gnuplotPipe);
//
//        fputs("pkill - fx 'gnuplot -persist.*'", gnuplotPipe);
//        fflush(gnuplotPipe);
//        std::cout << "������� ������� Gnuplot...\n";
//
//        //fprintf(gnuplotPipe, "%s", buff);
//        //fflush(gnuplotPipe);
//        //pclose(gnuplotPipe);
//        if (_pclose(gnuplotPipe) == -1)  // ��������� ���������� �������� Gnuplot
//        {
//            std::cerr << "������: �� ������� ������� Gnuplot." << std::endl;
//        }
//        else
//        {
//            std::cout << "Gnuplot ������� ������." << std::endl;
//        }
//        gnuplotPipe = nullptr;
//    }
//    else
//    {
//        std::cerr << "Gnuplot ��� ������ ��� �� ��� ������.\n";
//    }
//}
void closeGnuplot()
{
    if (gnuplotPipe)
    {
        // ������ ��������� � ������� ����������
        //std::cout << "������� ��������� ������� 'exit gnuplot'...\n";

        // ���������� ������� `exit gnuplot`, ����� �������������� ��������� Gnuplot
        fputs("exit gnuplot\n", gnuplotPipe);
        fflush(gnuplotPipe);  // ��������� ����� � ���������� �������

        // ������� ������� Gnuplot
        //std::cout << "������� ������� Gnuplot...\n";
        if (_pclose(gnuplotPipe) == -1)  // ��������� ���������� �������� Gnuplot
        {
            std::cerr << "������: �� ������� ������� Gnuplot." << std::endl;
        }
        else
        {
            std::cout << "Gnuplot ������� ������." << std::endl;
        }
        gnuplotPipe = nullptr;  // �������� ���������
    }
    else
    {
        std::cerr << "Gnuplot ��� ������ ��� �� ��� ������.\n";
    }
}
// ������� ��� ���������� ������� � �������������� ������ ����� � �������
void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y)
{
    if (!gnuplotPipe) return;

    // ������������ ������ ��� gnuplot
    std::ostringstream commands;
    commands << "set title 'Cubic Spline vs. Original Points'\n";
    commands << "set xlabel 'X'\n";
    commands << "set ylabel 'Y'\n";
    commands << "set grid\n";

    // ���������� ������� �������� �����
    commands << "$data << EOD\n";
    for (size_t i = 0; i < x.size(); ++i)
    {
        commands << x[i] << " " << y[i] << "\n";
    }
    commands << "EOD\n";

    // ���������� ������ ��� �������
    commands << "$spline << EOD\n";
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        commands << spline_x[i] << " " << spline_y[i] << "\n";
    }
    commands << "EOD\n";

    // ���������� �������: ������ � �����
    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";

    // ���������� ������� � gnuplot
    fputs(commands.str().c_str(), gnuplotPipe);
    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot

    std::cout << "������ ������� ��������.\n";
}
void plotSplineAndExactFunction(const std::vector<double>& original_x, const std::vector<double>& original_y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y,
    const std::vector<double>& exact_x, const std::vector<double>& exact_y)
{
    if (!gnuplotPipe) return;

    // ������������ ������ ��� gnuplot
    std::ostringstream commands;
    commands << "set title 'Cubic Spline vs. Original Points and Exact Function'\n";
    commands << "set xlabel 'X'\n";
    commands << "set ylabel 'Y'\n";
    commands << "set grid\n";

    // ���������� ������� �������� �����
    commands << "$data << EOD\n";
    for (size_t i = 0; i < original_x.size(); ++i)
    {
        commands << original_x[i] << " " << original_y[i] << "\n";
    }
    commands << "EOD\n";

    // ���������� ������ ��� �������
    commands << "$spline << EOD\n";
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        commands << spline_x[i] << " " << spline_y[i] << "\n";
    }
    commands << "EOD\n";

    // ���������� ������ ��� ������ �������
    commands << "$exact << EOD\n";
    for (size_t i = 0; i < exact_x.size(); ++i)
    {
        commands << exact_x[i] << " " << exact_y[i] << "\n";
    }
    commands << "EOD\n";

    // ���������� �������: ������, ������������ ����� � ������ �������
    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline', \\\n";
    commands << "     $exact with lines linetype 1 linewidth 2 linecolor 'green' title 'Exact Function'\n";

    // ���������� ������� � gnuplot
    fputs(commands.str().c_str(), gnuplotPipe);
    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot

    std::cout << "������ ������� ��������.\n";
}
