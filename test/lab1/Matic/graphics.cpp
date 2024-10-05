// plotting.cpp
#include "graphics.h"
#include <sstream>  // Для std::ostringstream
#include <thread>   // Для std::this_thread::sleep_for
#include <chrono>   // Для std::chrono


#include <stdio.h>
#include <stdlib.h>
// Глобальная переменная для указателя на Gnuplot
FILE* gnuplotPipe = nullptr;

// Функция для открытия Gnuplot
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
        std::cerr << "Ошибка: не удалось открыть Gnuplot." << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Gnuplot успешно открыт." << std::endl;
    }
}

void wcloseGnuplot()
{
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    closeGnuplot();
}

// Функция для закрытия Gnuplot
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
//        std::cout << "Попытка отправить команду exit...\n";
//        fprintf(gnuplotPipe, "exit\n");
//        fputs("exit\n", gnuplotPipe);  // Отправляем команду выхода
//        fflush(gnuplotPipe);  // Сбрасываем буфер
//
//        fputs("quit\n", gnuplotPipe);  // Отправляем команду выхода
//        fflush(gnuplotPipe);
//
//        fputs("pkill - fx 'gnuplot -persist.*'", gnuplotPipe);
//        fflush(gnuplotPipe);
//        std::cout << "Попытка закрыть Gnuplot...\n";
//
//        //fprintf(gnuplotPipe, "%s", buff);
//        //fflush(gnuplotPipe);
//        //pclose(gnuplotPipe);
//        if (_pclose(gnuplotPipe) == -1)  // Проверяем завершение процесса Gnuplot
//        {
//            std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
//        }
//        else
//        {
//            std::cout << "Gnuplot успешно закрыт." << std::endl;
//        }
//        gnuplotPipe = nullptr;
//    }
//    else
//    {
//        std::cerr << "Gnuplot уже закрыт или не был открыт.\n";
//    }
//}
void closeGnuplot()
{
    if (gnuplotPipe)
    {
        // Печать сообщения о попытке завершения
        //std::cout << "Попытка отправить команду 'exit gnuplot'...\n";

        // Используем команду `exit gnuplot`, чтобы гарантированно завершить Gnuplot
        fputs("exit gnuplot\n", gnuplotPipe);
        fflush(gnuplotPipe);  // Обновляем буфер и отправляем команду

        // Попытка закрыть Gnuplot
        //std::cout << "Попытка закрыть Gnuplot...\n";
        if (_pclose(gnuplotPipe) == -1)  // Проверяем завершение процесса Gnuplot
        {
            std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
        }
        else
        {
            std::cout << "Gnuplot успешно закрыт." << std::endl;
        }
        gnuplotPipe = nullptr;  // Обнуляем указатель
    }
    else
    {
        std::cerr << "Gnuplot уже закрыт или не был открыт.\n";
    }
}
// Функция для построения графика с использованием данных точек и сплайна
void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y)
{
    if (!gnuplotPipe) return;

    // Формирование команд для gnuplot
    std::ostringstream commands;
    commands << "set title 'Cubic Spline vs. Original Points'\n";
    commands << "set xlabel 'X'\n";
    commands << "set ylabel 'Y'\n";
    commands << "set grid\n";

    // Отправляем таблицу исходных точек
    commands << "$data << EOD\n";
    for (size_t i = 0; i < x.size(); ++i)
    {
        commands << x[i] << " " << y[i] << "\n";
    }
    commands << "EOD\n";

    // Отправляем данные для сплайна
    commands << "$spline << EOD\n";
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        commands << spline_x[i] << " " << spline_y[i] << "\n";
    }
    commands << "EOD\n";

    // Построение графика: сплайн и точки
    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";

    // Отправляем команды в gnuplot
    fputs(commands.str().c_str(), gnuplotPipe);
    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot

    std::cout << "График успешно построен.\n";
}
void plotSplineAndExactFunction(const std::vector<double>& original_x, const std::vector<double>& original_y,
    const std::vector<double>& spline_x, const std::vector<double>& spline_y,
    const std::vector<double>& exact_x, const std::vector<double>& exact_y)
{
    if (!gnuplotPipe) return;

    // Формирование команд для gnuplot
    std::ostringstream commands;
    commands << "set title 'Cubic Spline vs. Original Points and Exact Function'\n";
    commands << "set xlabel 'X'\n";
    commands << "set ylabel 'Y'\n";
    commands << "set grid\n";

    // Отправляем таблицу исходных точек
    commands << "$data << EOD\n";
    for (size_t i = 0; i < original_x.size(); ++i)
    {
        commands << original_x[i] << " " << original_y[i] << "\n";
    }
    commands << "EOD\n";

    // Отправляем данные для сплайна
    commands << "$spline << EOD\n";
    for (size_t i = 0; i < spline_x.size(); ++i)
    {
        commands << spline_x[i] << " " << spline_y[i] << "\n";
    }
    commands << "EOD\n";

    // Отправляем данные для точной функции
    commands << "$exact << EOD\n";
    for (size_t i = 0; i < exact_x.size(); ++i)
    {
        commands << exact_x[i] << " " << exact_y[i] << "\n";
    }
    commands << "EOD\n";

    // Построение графика: сплайн, оригинальные точки и точная функция
    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline', \\\n";
    commands << "     $exact with lines linetype 1 linewidth 2 linecolor 'green' title 'Exact Function'\n";

    // Отправляем команды в gnuplot
    fputs(commands.str().c_str(), gnuplotPipe);
    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot

    std::cout << "График успешно построен.\n";
}
