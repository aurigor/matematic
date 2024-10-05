#include <iostream>
#include "Matic/matic.h"
//#include "math.h"
#include <fstream>
#include <cstdlib> // Для system()
#include <cstdio>    // Для _popen и _pclose
#include <memory>
#include <sstream>
#include <thread>
#include <vector>
#include <string>

//#include<spdlog/spdlog.h>
//#include

#include <io.h>
#include <fcntl.h>

double exampleFunction(double x)
{
    return x * x;  // Пример простой функции (x^2)
}

int main()
{
    //setlocale(LC_ALL, "rus");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    //std::wcout << L"Unicode -- English -- Русский -- Ελληνικά -- Español." << std::endl;
    // или
    //wprintf(L"%s", L"Unicode -- English -- Русский -- Ελληνικά -- Español.\n");

    //_polynom<double> p1(1, 5);
    //wcout << p1[2]<<endl;
    //_polynom<double> poly1, poly2, poly3;
    //poly1.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
    //poly1.setName(L"p1");
    //poly1.print();

    //poly2.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
    //poly2.setName(L"p2");
    //poly2.print();
    //
    //poly3.setName(L"p3");
    //poly3 = poly1 + poly2;
    //poly3.print();
    _polynom<int> poly1, poly2, poly3;
    poly1.generateRandom(4, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
    poly1.setName(L"p1");
    poly1.print();

    poly2.generateRandom(4, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
    poly2.setName(L"p2");
    poly2.print();

    poly3.setName(L"p3");
    poly3 = poly1 + poly2;
    poly3.print();
    poly3 = poly1 * poly2;
    poly3.print();

    _polynom<double> poly11, poly12, poly13;
    poly11.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
    poly11.setName(L"p11");
    poly11.print();

    poly12.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
    poly12.setName(L"p12");
    poly12[poly12.degree()] = -poly11[poly11.degree()];
    poly12[poly12.degree()-1] = -poly11[poly11.degree()-1];
    poly12.print();
    
    poly13.setName(L"p3");
    poly13 = poly11 + poly12;
    poly13.print();
    poly13 = poly11 * poly12;
    poly13.print();
    
    //_vector<int> a(0, 5), b(1, 6), d(0,5);
    ////_vector<string> c(0, 5);
    //cout << a.isLess(b) << endl;
    //cout << a.isLess(d) << endl;
    //cout << a.isEquals(d) << endl;

    //cout << a;

    _polynom<double> f(0, 5);
    //test::demoSplineAndPlot();
    //_vector<int> a(0, 5), b(1, 6), d(0,5);
    ////_vector<string> c(0, 5);
    //cout << a.isLess(b) << endl;
    //cout << a.isLess(d) << endl;
    //cout << a.isEquals(d) << endl;
    

    //spdlog::info(L"hello world");
    //spdlog::error(L"oh no");
    //cout << a.isLess(c) << endl;

    ///*std::vector<int> vec1{ 1, 2, 3 };
    //std::vector<char> vec2{ 'a', 'b', 'c' };
    //for (auto [i, c] : std::views::zip(vec1, vec2))
    //{
    //    std::cout << i << ", " << c << std::endl;
    //}

    //std::vector<int> vec1{ 1, 2, 3 };
    //std::vector<char> vec2{ 'a', 'b', 'c' };
    //for (auto [i, c] : std::views::zip(vec1, vec2))
    //{
    //    std::cout << i << ", " << c << std::endl;
    //}*/
    //_vector<int> a(0, 5);
    //a.description();
    //a.help();
    //a.help("+");
    //a.help("add");
    //a.help("print");

    ///*_vector<int> b(3, 5);
    //_vector<int> c(2, 5);
    //c[0] = 0;
    //_vector<int> d = b / c;
    //d.print();*/


    //_vector<double> b(3, 5, "b");
    //_vector<double> c(2, 5);
    //c[0] = 0;
    //_vector<double> d = b / c;
    //b.print();
    //c.print();
    //d.print();

    ////_vector<double> b1;
    ////cin >> b1;
    //////b1 << c;
    //////c>>b1;
    ////_vector<double> c1(2, 5);
    ////c1[0] = 0;
    ////_vector<double> d1 = b1 / c1;
    ////b1.print();
    ////c1.print();
    ////d1.print();


    /*_vector<string> bs("hello ", 5, "bs");
    _vector<string> cs("hi", 5, "cs");
    cs[0] = "bye";
    _vector<string> ds = bs + cs;
    bs.print();
    cs.print();
    ds.print();*/

    /*string s1 = "hello ", s2 = "hi";
    cout << s1 + s2;*/

    //test::demoSplineAndPlot();
    
    //// Пример данных для построения графика
    //std::vector<double> x = { 0, 1, 2, 3, 4, 5 };
    //std::vector<double> y = { 0, 1, 4, 9, 16, 25 };

    //// Пример данных для построения сплайна (можно использовать алгоритм сплайнов)
    //std::vector<double> spline_x = { 0, 1, 2, 3, 4, 5 };
    //std::vector<double> spline_y = { 0, 1.2, 3.8, 8.5, 15.5, 25 };

    //// Открытие Gnuplot
    //openGnuplot();

    //// Построение графика
    //plotSplineWithPoints(x, y, spline_x, spline_y);
    //

    //
    //// Закрытие Gnuplot
    //closeGnuplot();

    //std::cout << "Программа завершена." << std::endl;

    return 0;
}



//FILE* gnuplotPipe;
//
//void openGnuplot()
//{
//    /*gnuplotPipe = _popen("gnuplot -persist", "w");
//    if (!gnuplotPipe)
//    {
//        std::cerr << "Ошибка: не удалось открыть Gnuplot." << std::endl;
//        exit(1);
//    }*/
//    gnuplotPipe = _popen("gnuplot -persist", "w");
//    if (!gnuplotPipe)
//    {
//        std::cerr << "Ошибка: не удалось открыть Gnuplot." << std::endl;
//        exit(1);
//    }
//    else
//    {
//        std::cout << "Gnuplot успешно открыт." << std::endl;
//    }
//}
//
////void closeGnuplot()
////{
////    //if (gnuplotPipe)
////    //{
////    //    fputs("exit\n", gnuplotPipe); // отправляем команду для выхода
////    //    fflush(gnuplotPipe);
////    //    _pclose(gnuplotPipe);
////    //    gnuplotPipe = nullptr; // обнуляем указатель
////    //}
////    if (gnuplotPipe)
////    {
////        cout << "$$$\n";
////        fputs("exit\n", gnuplotPipe); // Отправляем команду для выхода
////        cout << "$$$111\n";
////        if (_pclose(gnuplotPipe) == -1) // Закрываем и проверяем завершение
////        {
////            std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
////        }
////        else
////        {
////            std::cout << "Gnuplot успешно закрыт." << std::endl;
////        }
////        cout << ":::\n";
////        gnuplotPipe = nullptr;
////    }
////    else
////    {
////        cout << "!!!";
////    }
////}
////void closeGnuplot()
////{
////    if (gnuplotPipe)
////    {
////        std::cout << "Попытка отправить команду exit...\n";
////
////        // Отправляем команду выхода в Gnuplot
////        fputs("exit\n", gnuplotPipe);
////        fflush(gnuplotPipe); // Обновляем буфер
////
////        // Добавляем задержку перед закрытием
////        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Ждем полсекунды
////
////        std::cout << "Попытка закрыть Gnuplot...\n";
////        int closeStatus = _pclose(gnuplotPipe); // Пытаемся закрыть Gnuplot
////
////        if (closeStatus == -1)
////        {
////            std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
////        }
////        else
////        {
////            std::cout << "Gnuplot успешно закрыт. Код завершения: " << closeStatus << std::endl;
////        }
////
////        gnuplotPipe = nullptr;
////    }
////    else
////    {
////        std::cout << "!!! GnuplotPipe уже закрыт или не был открыт !!!\n";
////    }
////}
////void closeGnuplot()
////{
////    if (gnuplotPipe)
////    {
////        std::cout << "Попытка отправить команду quit...\n";
////
////        // Отправляем команду завершения работы в Gnuplot
////        fputs("print 'Done'\n", gnuplotPipe);  // Проверка: отправляем сообщение
////        fputs("quit\n", gnuplotPipe);          // Отправляем команду выхода
////        fflush(gnuplotPipe);                   // Обновляем буфер
////
////        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Ждем полсекунды
////
////        std::cout << "Попытка закрыть Gnuplot...\n";
////        int closeStatus = _pclose(gnuplotPipe); // Пытаемся закрыть Gnuplot
////
////        if (closeStatus == -1)
////        {
////            std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
////
////            // Принудительное завершение Gnuplot через системную команду (для Windows)
////            std::system("taskkill /F /IM gnuplot.exe");
////
////        }
////        else
////        {
////            std::cout << "Gnuplot успешно закрыт. Код завершения: " << closeStatus << std::endl;
////        }
////
////        gnuplotPipe = nullptr;
////    }
////    else
////    {
////        std::cout << "!!! GnuplotPipe уже закрыт или не был открыт !!!\n";
////    }
////}
////void closeGnuplot()
////{
////    if (gnuplotPipe)
////    {
////        std::cout << "Попытка отправить команду quit...\n";
////
////        fputs("print 'Done'\n", gnuplotPipe);  // Отправляем сообщение
////        fputs("exit\n", gnuplotPipe);          // Отправляем команду выхода
////        fflush(gnuplotPipe);                   // Сбрасываем буфер
////
////        std::cout << "Попытка закрыть Gnuplot...\n";
////
////        std::thread closeThread([]()
////            {
////                std::cout << "Закрытие в отдельном потоке...\n";
////                int closeStatus = _pclose(gnuplotPipe); // Закрытие в отдельном потоке
////                if (closeStatus == -1)
////                {
////                    std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
////                    std::system("taskkill /F /IM gnuplot.exe"); // Принудительное завершение
////                }
////                else
////                {
////                    std::cout << "Gnuplot успешно закрыт. Код завершения: " << closeStatus << std::endl;
////                }
////                gnuplotPipe = nullptr;
////            });
////
////        closeThread.detach(); // Даем потоку возможность работать независимо
////    }
////    else
////    {
////        std::cout << "!!! GnuplotPipe уже закрыт или не был открыт !!!\n";
////    }
////}
//void closeGnuplot()
//{
//    if (gnuplotPipe)
//    {
//        //system("taskkill /IM gnuplot.exe /F");//work
//        //fputs("print GPVAL_TERM\n", gnuplotPipe);  // Проверяем терминал
//        //fputs("exit\n", gnuplotPipe);
//        //fflush(gnuplotPipe);
//
//        std::cout << "Попытка отправить команду exit...\n";
//
//        // Попробуем отправить несколько вариантов команды закрытия
//        fputs("\n", gnuplotPipe);             // Пустая строка на всякий случай
//        fputs("exit\n", gnuplotPipe);         // Отправляем команду выхода
//        fflush(gnuplotPipe);                  // Сбрасываем буфер
//
//        std::cout << "Попытка закрыть Gnuplot...\n";
//
//        // Проверяем, корректно ли закрывается процесс
//        if (_pclose(gnuplotPipe) == -1)
//        {
//            std::cerr << "Ошибка: не удалось закрыть Gnuplot. Принудительное завершение." << std::endl;
//            system("taskkill /IM gnuplot.exe /F"); // Принудительное завершение
//        }
//        else
//        {
//            std::cout << "Gnuplot успешно закрыт." << std::endl;
//        }
//
//        gnuplotPipe = nullptr;
//    }
//    else
//    {
//        std::cout << "Gnuplot уже закрыт или не был открыт.\n";
//    }
//}
//void plotTest()
//{
//    if (!gnuplotPipe) return;
//
//    // Отправляем простую команду на построение графика sin(x)
//    fputs("plot sin(x)\n", gnuplotPipe);
//    fflush(gnuplotPipe);  // Отправляем данные в Gnuplot
//
//    std::cout << "Команда plot sin(x) отправлена." << std::endl;
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // Формирование команд для gnuplot
//    std::ostringstream commands;
//
//    commands << "set title 'Cubic Spline vs. Original Points'\n";
//    commands << "set xlabel 'X'\n";
//    commands << "set ylabel 'Y'\n";
//    commands << "set grid\n";
//
//    // Отправляем таблицу исходных точек
//    commands << "$data << EOD\n";
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        commands << x[i] << " " << y[i] << "\n";
//    }
//    commands << "EOD\n";
//
//    // Отправляем данные для сплайна
//    commands << "$spline << EOD\n";
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        commands << spline_x[i] << " " << spline_y[i] << "\n";
//    }
//    commands << "EOD\n";
//
//    // Построение графика: сплайн и точки
//    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
//    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";
//
//    // Отправляем команды в gnuplot
//    fputs(commands.str().c_str(), gnuplotPipe);
//    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
//
//
//    closeGnuplot();
//}
//
//
//
//
//void plotInGnuplot(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    openGnuplot();
//    plotSplineWithPoints(x, y, spline_x, spline_y);
//    std::cout << "Нажмите любую клавишу, чтобы закрыть gnuplot..." << std::endl;
//    std::cin.ignore(); // Очищаем буфер
//    std::cin.get();    // Ожидаем, пока пользователь нажмет клавишу
//    closeGnuplot();
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    // Открытие Gnuplot
//    openGnuplot();
//
//    // Построение тестового графика
//    plotTest();
//
//    // Небольшая задержка, чтобы график успел построиться перед закрытием
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    cout << "\n time is end\n";
//    // Закрытие Gnuplot
//    closeGnuplot();
//
//    std::cout << "Программа завершена." << std::endl;
//    return 0;
//    //auto func = [](double x) { return std::exp(x); };
//    //_spline<double> mySpline(0.0, 5.0, 5, func);
//
//    //// Генерация данных для построения графика
//    //std::vector<double> spline_x, spline_y;
//    //mySpline.generateSplineData(spline_x, spline_y);
//
//    //// Открытие gnuplot в отдельном потоке
//    //std::thread plotThread(plotInGnuplot, mySpline.getX(), mySpline.getY(), spline_x, spline_y);
//
//    //// Дождитесь завершения потока перед выходом из программы
//    //plotThread.join();
//
//    //return 0;
//}




//#include <iostream>
//#include "mymath/mymath.h"
//#include "math.h"
//#include <fstream>
//#include <cstdlib> // Для system()
//#include <cstdio>    // Для _popen и _pclose
//#include <memory>
//#include <sstream>
//#include <thread>
////#include <gnuplot-iostream.h>
//
//FILE* gnuplotPipe;
//void openGnuplot()
//{
//    gnuplotPipe = _popen("gnuplot -persist", "w");
//    if (!gnuplotPipe)
//    {
//        std::cerr << "Ошибка: не удалось открыть Gnuplot." << std::endl;
//        exit(1);
//    }
//}
//
////void closeGnuplot()
////{
////    if (gnuplotPipe)
////    {
////        _pclose(gnuplotPipe);
////    }
////}
////void closeGnuplot()
////{
////    if (gnuplotPipe)
////    {
////        // Отправка команды для завершения Gnuplot
////        fprintf(gnuplotPipe, "exit\n");
////        _pclose(gnuplotPipe);
////        gnuplotPipe = nullptr; // обнуляем указатель
////    }
////}
//void closeGnuplot()
//{
//    if (gnuplotPipe)
//    {
//        fprintf(gnuplotPipe, "exit\n"); // отправляем команду для выхода
//        if (_pclose(gnuplotPipe) == -1) // проверяем, завершился ли процесс
//        {
//            std::cerr << "Ошибка: не удалось закрыть Gnuplot." << std::endl;
//        }
//        gnuplotPipe = nullptr; // обнуляем указатель
//    }
//}
//void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    if (!gnuplotPipe) return;
//
//    // Формирование команд для gnuplot
//    std::ostringstream commands;
//
//    commands << "set title 'Cubic Spline vs. Original Points'\n";
//    commands << "set xlabel 'X'\n";
//    commands << "set ylabel 'Y'\n";
//    commands << "set grid\n";
//
//    // Отправляем таблицу исходных точек
//    commands << "$data << EOD\n";
//    for (size_t i = 0; i < x.size(); ++i)
//    {
//        commands << x[i] << " " << y[i] << "\n";  // Используем стандартный вывод
//    }
//    commands << "EOD\n";
//
//    // Отправляем данные для сплайна
//    commands << "$spline << EOD\n";
//    for (size_t i = 0; i < spline_x.size(); ++i)
//    {
//        commands << spline_x[i] << " " << spline_y[i] << "\n";  // Используем стандартный вывод
//    }
//    commands << "EOD\n";
//
//    // Построение графика: сплайн и точки
//    commands << "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n";
//    commands << "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";
//
//    // Отправляем команды в gnuplot
//    fprintf(gnuplotPipe, "%s", commands.str().c_str());
//
//    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
//}
////void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
////{
////    Gnuplot gp;
////
////    gp << "set title 'Cubic Spline vs. Original Points'\n";
////    gp << "set xlabel 'X'\n";
////    gp << "set ylabel 'Y'\n";
////    gp << "set grid\n";
////
////    gp << "plot '-' with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', "
////        "'-' with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n";
////
////    gp.send1d(boost::make_tuple(x, y));     // Отправка оригинальных данных
////    gp.send1d(boost::make_tuple(spline_x, spline_y)); // Отправка сплайн данных
////}
//
////void plotSplineWithPoints(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
////{
////    if (!gnuplotPipe) return;
////
////    // Отправляем команды в gnuplot
////    fprintf(gnuplotPipe, "set title 'Cubic Spline vs. Original Points'\n");
////    fprintf(gnuplotPipe, "set xlabel 'X'\n");
////    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
////    fprintf(gnuplotPipe, "set grid\n");
////
////    // Отправляем таблицу исходных точек
////    fprintf(gnuplotPipe, "$data << EOD\n");
////    for (size_t i = 0; i < x.size(); ++i)
////    {
////        fprintf(gnuplotPipe, "%f %f\n", x[i], y[i]);
////    }
////    fprintf(gnuplotPipe, "EOD\n");
////
////    // Отправляем данные для сплайна
////    fprintf(gnuplotPipe, "$spline << EOD\n");
////    for (size_t i = 0; i < spline_x.size(); ++i)
////    {
////        fprintf(gnuplotPipe, "%f %f\n", spline_x[i], spline_y[i]);
////    }
////    fprintf(gnuplotPipe, "EOD\n");
////
////    // Построение графика: сплайн и точки
////    fprintf(gnuplotPipe, "plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n");
////    fprintf(gnuplotPipe, "     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline'\n");
////
////    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot
////}
//double square(double x)
//{
//    return x * x;  // Возвращает x^2
//}
//
//double difference(double x, double y)
//{
//    return y * y - x * x;  // Возвращает y^2 - x^2
//}
//
//double customFunction(double x, double y, double z)
//{
//    return x * y + z;  // Пример произвольной функции с тремя аргументами
//}
//double twoe1(double x, double y)
//{
//    return y * y - x * x;  // Возвращает y^2 - x^2
//}
//double twoe2(double x, double y)
//{
//    return y * y - x * x-10;  // Возвращает y^2 - x^2
//}
//double twoe3(double x, double y)
//{
//    return y * y - x * x*x;  // Возвращает y^2 - x^2
//}
//
//
//
//void plotInGnuplot(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& spline_x, const std::vector<double>& spline_y)
//{
//    openGnuplot();
//    plotSplineWithPoints(x, y, spline_x, spline_y);
//    std::cout << "Нажмите любую клавишу, чтобы закрыть gnuplot..." << std::endl;
//    std::cin.ignore(); // Очищаем буфер
//    std::cin.get();    // Ожидаем, пока пользователь нажмет клавишу
//    closeGnuplot();
//}
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    auto func = [](double x) { return std::exp(x); };
//    _spline<double> mySpline(0.0, 5.0, 5, func);
//
//    // Генерация данных для построения графика
//    std::vector<double> spline_x, spline_y;
//    mySpline.generateSplineData(spline_x, spline_y);
//
//    // Открытие gnuplot в отдельном потоке
//    std::thread plotThread(plotInGnuplot, mySpline.getX(), mySpline.getY(), spline_x, spline_y);
//
//    // Продолжайте выполнять другие действия в основном потоке, если необходимо
//
//    // Дождитесь завершения потока перед выходом из программы
//    plotThread.join();
//
//    //auto func = [](double x) { return std::exp(x); };
//    //_spline<double> mySpline(0.0, 5.0, 6, func);
//
//    //std::vector<double> spline_x, spline_y;
//    //mySpline.generateSplineData(spline_x, spline_y,101);
//    //std::cout << "Spline data:" << std::endl;
//    //for (size_t i = 0; i < spline_x.size(); ++i)
//    //{
//    //    std::cout << spline_x[i] << " " << spline_y[i] << std::endl;
//    //}
//    //// Открытие gnuplot
//    //openGnuplot();
//    //std::vector<double>xs = mySpline.getX();
//    //std::vector<double>ys = mySpline.getY();
//    //std::cout << "Spline data:" << std::endl;
//    //for (size_t i = 0; i < xs.size(); ++i)
//    //{
//    //    std::cout << xs[i] << " " << ys[i] << std::endl;
//    //}
//    //
//
//    //plotSplineWithPoints(mySpline.getX(), mySpline.getY(), spline_x, spline_y);
//
//    //std::cout << "Нажмите любую клавишу, чтобы закрыть gnuplot..." << std::endl;
//    ////std::cin.get();  // Ожидаем, пока пользователь нажмет клавишу
//    ///*std::system("pause");*/
//    //std::cin.ignore();  // Очищаем буфер
//    //std::cin.get();
//    //// Закрытие gnuplot
//    //closeGnuplot();
//
//    return 0;
//}
//

//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    //test::tVector();
//
//    _spline<double> spline;
//
//    spline.add_point(0.0, 0.0);
//    spline.add_point(1.0, 2.0);
//    spline.add_point(2.0, 3.0);
//    spline.add_point(3.0, 2.0);
//    spline.add_point(4.0, 0.0);
//
//    spline.build_spline();
//
//    cout << "Коэффициенты сплайна:\n";
//    spline.print_spline();
//
//
//    cout << "\nЗначения сплайна в промежуточных точках:\n";
//    for (double x = 0.0; x <= 4.0; x += 0.5)
//    {
//        double y = spline.get_value(x);
//        cout << "spline(" << x << ") = " << y << endl;
//    }
////
////    // Создаем две матрицы 3x3
////    _matrix<double> mat1(2.0, 3, 3);
////    _matrix<double> mat2(1.0, 3, 3);
////
////    // Инициализируем элементы матриц
////    for (int i = 0; i < 3; ++i)
////    {
////        for (int j = 0; j < 3; ++j)
////        {
////            mat1(i, j) = i + j;   // mat1 = [[0, 1, 2], [1, 2, 3], [2, 3, 4]]
////            mat2(i, j) = i - j;   // mat2 = [[0, -1, -2], [1, 0, -1], [2, 1, 0]]
////        }
////    }
////
////    cout << "Матрица 1:\n";
////    mat1.print();
////
////    cout << "\nМатрица 2:\n";
////    mat2.print();
////
////    // Операция сложения матриц
////    _matrix<double> sum = mat1 + mat2;
////    cout << "\nСумма матриц 1 и 2:\n";
////    sum.print();
////
////    // Операция вычитания матриц
////    _matrix<double> diff = mat1 - mat2;
////    cout << "\nРазность матриц 1 и 2:\n";
////    diff.print();
////
////    // Операция умножения матриц
////    _matrix<double> prod = mat1 * mat2;
////    cout << "\nПроизведение матриц 1 и 2:\n";
////    prod.print();
////
////    // Умножение матрицы на константу
////    _matrix<double> scalarProd = mat1 * 3.0;
////    cout << "\nУмножение матрицы 1 на 3.0:\n";
////    scalarProd.print();
////
////
////
////    _matrix<double> mat11(2.0, 2, 2);
////    _matrix<double> mat22(1.0, 3, 3);
////    _matrix<double> diff1 = mat11 - mat22;
////    _matrix<double> mult1 = mat11 * mat22;
////    _matrix<double> sum1 = mat11 + mat22;
////    cout << "\nРазность матриц 11 и 22:\n";
////    diff1.print();
////    mat11.print();
////    mat22.print();
////
////    //Function f1([](double& x) { return x * x; });
////    //Function f1(square);
////    //Function f2([](double x, double y) { return y * y - x * x; });  // y^2 - x^2
////    //Function f3([](double x, double y, double z) { return x * y + z; });
////    //Function f1(square);                      // f1 представляет x^2
////    //Function f2(difference);                  // f2 представляет y^2 - x^2
////    //Function f3(customFunction);              // f3 представляет x*y + z
////
////    // Используем функции
////    double x = 3.0;
////    double y = 4.0;
////    double z = 5.0;
////
////    //cout << "f1(" << x << ") = " << f1(x) << endl;            // Вычисляет f1(3.0) = 9.0
////    //cout << "f2(" << x << ", " << y << ") = " << f2(x, y) << endl;  // Вычисляет f2(3.0, 4.0) = 7.0
////    //cout << "f3(" << x << ", " << y << ", " << z << ") = " << f3(x, y, z) << endl;  // Вычисляет f3(3.0, 4.0, 5.0) = 17.0
////#define inline_function(params) \
////class \
////{ \
////    public: void operator() (params)\
////    {\
////
////#define with_name(value) \
////    }\
////} value;
////
////#define with_params(...) __VA_ARGS__ // А это-то зачем тут? Читай ниже.
////
////
////    inline_function(with_params(int a, int b))
////    {
////        printf("%d+%d=%d\n", a, b, a + b);
////    } with_name(plus);
////
////    plus(2, 2);
////
////#define inline_funct(params) \
////class \
////{ \
////    public: double operator() (params)\
////    {\
////
////#define with_name(value) \
////    }\
////} value;
////
////#define with_params(...) __VA_ARGS__ // А это-то зачем тут? Читай ниже.
////
////
////    inline_funct(with_params(double a, double b))
////    {
////        return a + b;
////    } with_name(plus1);
////
////    cout << "\n sum = " << plus1(2, 2) << endl;
////
////    inline_funct(with_params(double x))
////    {
////        return x * x;
////    }with_name(squars)
////        //Function f1(squars);
////        //_vector<inline_funct(with_params(double, double))> a;
////        /*function asd = square;
////        Function a(asd);
////        cout << "f1(" << x << ") = " << a(x) << endl;*/
////
////        //Function f1([](double x) { return square(x); });
////    //std::cout << "f1(" << x << ") = " << f1(x) << std::endl;
////    //Function f2([](double x, double y) { return difference(x, y); });
////   // std::cout << "f2(" << x << ", " << y << ") = " << f2(x, y) << std::endl;
////    //cout << "\ntFunct = " << tFunct<double>(x, y, z) << endl;
////    tfunct1 = square;
////    cout << "\ntFunct = " << tfunct1(x)<< endl;
////
////    //Fun<double, double> obj(square);
////    //auto obj = Fun<double, double>(square);
////    _function obj(tfunct1);
////    /*Fun<double, double> obj();
////    obj.set(tfunct1);*/
////    cout << "\nobj = " << obj(x) << endl;
////    //Fun obj1(difference);
////    //auto perefod = square;
////    tfunct2 = difference;
////    _function obj1(tfunct2);
////    cout << "\nobj1 = " << obj1(x, y) << endl;
////
////    //Fun<double,(double,double)> obj2;
////    _function<double, double, double> obj2;
////    obj2.set(difference);
////    cout << "\nobj2 = " << obj2(x, y) << endl;
////
////
////    _function<double, double, double> obj3(difference);
////    cout << "\nobj3 = " << obj3(x, y) << endl;
////
////    //_vector<_function<double, double, double>> vfun;
////    _vector<_function<double, double, double>> vfun(_function<double, double, double>(), 3);
////    vfun[0].set(difference);
////    vfun[1].set([](double x, double y) { return sin(x) + cos(y); });
////    vfun[2].set([](double x, double y) { return pow(x,3) + cos(y); });
////    cout << endl;
////    for (int i = 0; i < 3; ++i)
////    {
////        cout << "vfun[" << i << "](" << x << ", " << y << ") =" << vfun[i](x,y) << endl;
////    }
////    //_vector<_function> vfun;
////    //Fun obj(tfunct1);
//    return 0;
//}