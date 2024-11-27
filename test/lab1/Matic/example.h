#ifndef EXAMPLE
#define EXAMPLE
#include<iostream>
//#include"vector.h"
#include"graphics.h"
#include"spline.h"
#include"polynom.h"
#include"array.h"

using namespace std;

double FunctionForExample_SquareSum(double x, double y)
{
    return x * x+y*y;  // Возвращает x^2
}
double FunctionForExample_CubeSum(double x, double y)
{
    return x * x*x+y*y*y;  // Возвращает x^2
}
double FunctionForExample_DifferentCoord(double x, double y)
{
    return x -y;  // Возвращает x^2
}

namespace test
{
	//example use _vector
	void eVector()
	{
        //setlocale(LC_ALL, "Russian");

        // Int vector
        cout << "\n\n--------------------------------------------------------------------------------";//80
        cout << "\nstart example section for int for vector\n\n";
        //operation
        cout << "operation for vector\n";
		const unsigned N = 5;
		_vector<int> intVec1(5, N), intVec2(3, N), intVecResult(0,N);
		
        for (int i = 1; i <= N; ++i)
        {
            intVec1[i-1] = -i * i;
            intVec2[i-1] = i;
        }

        cout << "vector a is ";
        intVec1.print();
        
        cout << "vector b is ";
        intVec2.print();
		intVecResult = intVec1 + intVec2;
        cout << "result vector for a+b is ";
		intVecResult.print();

        intVecResult = intVec1 - intVec2;
        cout << "result vector for a-b is ";
        intVecResult.print();

        intVecResult = intVec1 * intVec2;
        cout << "result vector for a*b is ";
        intVecResult.print();

        //intVecResult = intVec1 / intVec2;
        //cout << "result vector for a/b is ";
        //intVecResult.print();

        intVecResult = intVec1 % intVec2;
        cout << "result vector for a%b is ";
        intVecResult.print();

        intVecResult = intVec1 ^ intVec2;
        cout << "result vector for a^b is ";
        intVecResult.print();

        //intVecResult = intVec1 * intVec2;
        //cout << "result vector for a*b is ";
        //intVecResult.print();

        //intVecResult = intVec1 + intVec2;
        //cout << "result vector for a+b is ";
        //intVecResult.print();

        cout << "result scalar product is "<<intVec1.scalar_product(intVec2)<<endl;
        //intVecResult.print();


        // Умножение вектора a на константу
        intVecResult = intVec1 * 2.0;
        cout << "resul for product vector and scalar (a * 2.0) is ";
        intVecResult.print();

        //function
        cout << "\nmetods for vector is \n";
        intVec1.add(7);
        intVec1.add(13);
        cout << "resul a before add(7), add(13) is ";
        intVec1.print();


        cout << "\n\nEnd example section for int for vector\n";
        cout << "--------------------------------------------------------------------------------\n\n";//80

	}

    void eArray()
    {
        //setlocale(LC_ALL, "Russian");

        wcout << L"\n\n--------------------------------------------------------------------------------";//80
        wcout << L"\nstart example section for _array<_function>\n\n";
        //function array
        _function<double, double, double> obj1, obj2;
        obj1.set(FunctionForExample_SquareSum);
        obj2.set(FunctionForExample_CubeSum);

        

        _array<_function<double, double, double>> arr1;
        //object.add([](double x) { return x; });

        arr1[0]=obj1;
        arr1.add(obj2);
        arr1.add(convertFunct<double, double, double>(FunctionForExample_DifferentCoord));
        //object.add(square);
        //auto
        arr1.add(convertFunct<double, double, double>([](double x, double y) { return x*x-3*x+5-y*y+3*y-3; }));

        double x = 5, y = 2.73;
        wcout << L"arrq[0]("<<x<< L", "<<y<< L") = "<<arr1[0](x,y)<<endl;
        wcout << L"arrq[1](" << x << L", " << y << L") = " << arr1[1](x, y) << endl;
        wcout << L"arr1[2](" << x << L", " << y << L") = " << arr1[2](x, y) << endl;
        wcout << L"arr1[3](" << x << L", " << y << L") = " << arr1[3](x, y) << endl;

        wcout << L"\ncontruct for _array<_function\n>" << endl;
        _array<_function<double, double>> arr2(convertFunct<double, double>([](double x) { return 0; }), 2);
        wcout << L"arr[0](" << x << L", " << y << L") = " << arr2[0](x) << endl;
        wcout << L"arr[1](" << x << L", " << y << L") = " << arr2[1](x) << endl;
       // wcout << L"--------------------------------------------------------------------------------\n\n";
       

        wcout << L"--------------------------------------------------------------------------------\n\n";//80

    }

    void eFunction()
    {
        ////setlocale(LC_ALL, "Russian");

        //// Int vector
        //cout << "\n\n--------------------------------------------------------------------------------";//80
        //cout << "\nstart example section for int for vector\n\n";
        ////operation
        //cout << "operation for vector\n";
        //const unsigned N = 5;
        //_vector<int> intVec1(5, N), intVec2(3, N), intVecResult(0, N);

        //for (int i = 1; i <= N; ++i)
        //{
        //    intVec1[i - 1] = -i * i;
        //    intVec2[i - 1] = i;
        //}

        //cout << "vector a is ";
        //intVec1.print();

        //cout << "vector b is ";
        //intVec2.print();
        //intVecResult = intVec1 + intVec2;
        //cout << "result vector for a+b is ";
        //intVecResult.print();

        //intVecResult = intVec1 - intVec2;
        //cout << "result vector for a-b is ";
        //intVecResult.print();

        //intVecResult = intVec1 * intVec2;
        //cout << "result vector for a*b is ";
        //intVecResult.print();

        ////intVecResult = intVec1 / intVec2;
        ////cout << "result vector for a/b is ";
        ////intVecResult.print();

        //intVecResult = intVec1 % intVec2;
        //cout << "result vector for a%b is ";
        //intVecResult.print();

        //intVecResult = intVec1 ^ intVec2;
        //cout << "result vector for a^b is ";
        //intVecResult.print();

        ////intVecResult = intVec1 * intVec2;
        ////cout << "result vector for a*b is ";
        ////intVecResult.print();

        ////intVecResult = intVec1 + intVec2;
        ////cout << "result vector for a+b is ";
        ////intVecResult.print();

        //cout << "result scalar product is " << intVec1.scalar_product(intVec2) << endl;
        ////intVecResult.print();


        //// Умножение вектора a на константу
        //intVecResult = intVec1 * 2.0;
        //cout << "resul for product vector and scalar (a * 2.0) is ";
        //intVecResult.print();

        ////function
        //cout << "\nmetods for vector is \n";
        //intVec1.add(7);
        //intVec1.add(13);
        //cout << "resul a before add(7), add(13) is ";
        //intVec1.print();


        //cout << "\n\nEnd example section for int for vector\n";
        //cout << "--------------------------------------------------------------------------------\n\n";//80

    }
	////example use _matrix
	//void tMatrix(){


	//}


	////example use _function
	//void tFunction(){

	//}


    //void demoSplineAndPlot()
    //{
    //    // 1. Задаем начальные и конечные значения, а также количество узлов
    //    double x_start = 0.0;
    //    double x_end = 10.0;
    //    int num_nodes = 5;

    //    // 2. Определяем функцию для генерации значений
    //    auto func = [](double x) { return std::sin(x); };

    //    // 3. Создаем экземпляр кубического сплайна
    //    _spline<double> spline(x_start, x_end, num_nodes, func);

    //    // 4. Генерируем данные для сплайна
    //    std::vector<double> spline_x, spline_y;
    //    spline.generateSplineData(spline_x, spline_y);

    //    // 5. Получаем исходные узлы
    //    const std::vector<double>& original_x = spline.getX();
    //    const std::vector<double>& original_y = spline.getY();


    //    std::vector<double> exact_x, exact_y;
    //    int num_points_exact = 100;  // Количество точек для точной функции
    //    double step_exact = (x_end - x_start) / (num_points_exact - 1);
    //    for (int i = 0; i < num_points_exact; ++i)
    //    {
    //        double x = x_start + i * step_exact;
    //        exact_x.push_back(x);
    //        exact_y.push_back(func(x));  // Значения точной функции
    //    }
    //    // 6. Открываем Gnuplot
    //    openGnuplot();

    //    // 7. Строим график
    //    plotSplineWithPoints(original_x, original_y, spline_x, spline_y);
    //    
    //    
    //    std::cin.clear();
    //    std::cin.ignore(std::cin.rdbuf()->in_avail());
    //    std::cin.get();


    //    // 8. Закрываем Gnuplot
    //    //closeGnuplot();


    //    // Теперь добавим точный график функции
    //    fputs("set title 'Cubic Spline vs. Original Points and Exact Function'\n", gnuplotPipe);
    //    fputs("plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n", gnuplotPipe);
    //    fputs("     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline', \\\n", gnuplotPipe);

    //    // Отправляем данные для точной функции
    //    fputs("$exact << EOD\n", gnuplotPipe);
    //    for (size_t i = 0; i < exact_x.size(); ++i)
    //    {
    //        fprintf(gnuplotPipe, "%lf %lf\n", exact_x[i], exact_y[i]);
    //    }
    //    fputs("EOD\n", gnuplotPipe);

    //    // Добавляем график точной функции
    //    fputs("     $exact with lines linetype 1 linewidth 2 linecolor 'green' title 'Exact Function'\n", gnuplotPipe);
    //    fflush(gnuplotPipe);  // Обновляем буфер и отправляем данные в gnuplot

    //    std::cout << "График успешно построен.\n";


    //    // 8. Закрываем Gnuplot
    //    closeGnuplot();
    //}
    


    //void eSplineAndPlot()
    //{
    //    // 1. Задаем начальные и конечные значения, а также количество узлов
    //    double x_start = 0.0;
    //    double x_end = 10.0;
    //    int num_nodes = 5;

    //    // 2. Определяем функцию для генерации значений
    //    auto func = [](double x) { return std::sin(x); };

    //    // 3. Создаем экземпляр кубического сплайна
    //    _spline<double> spline(x_start, x_end, num_nodes, func);

    //    // 4. Генерируем данные для сплайна
    //    std::vector<double> spline_x, spline_y;
    //    spline.generateSplineData(spline_x, spline_y);

    //    // 5. Получаем исходные узлы
    //    const std::vector<double>& original_x = spline.getX();
    //    const std::vector<double>& original_y = spline.getY();

    //    // 6. Генерируем данные для точной функции
    //    std::vector<double> exact_x, exact_y;
    //    int num_points_exact = 100;  // Количество точек для точной функции
    //    double step_exact = (x_end - x_start) / (num_points_exact - 1);
    //    for (int i = 0; i < num_points_exact; ++i)
    //    {
    //        double x = x_start + i * step_exact;
    //        exact_x.push_back(x);
    //        exact_y.push_back(func(x));  // Значения точной функции
    //    }

    //    // 7. Открываем Gnuplot
    //    openGnuplot();

    //    // 8. Строим график с использованием новой функции
    //    plotSplineAndExactFunction(original_x, original_y, spline_x, spline_y, exact_x, exact_y);

    //    // 9. Закрываем Gnuplot
    //    wcloseGnuplot();



    //    // 1. Задаем начальные и конечные значения, а также количество узлов
    //    num_nodes = 10;

    //    // 2. Определяем функцию для генерации значений
    //    //auto func = [](double x) { return std::sin(x); };

    //    // 3. Создаем экземпляр кубического сплайна
    //    _spline<double> spline1(x_start, x_end, num_nodes, func);

    //    // 4. Генерируем данные для сплайна
    //    std::vector<double> spline_x1, spline_y1;
    //    spline1.generateSplineData(spline_x1, spline_y1);

    //    // 5. Получаем исходные узлы
    //    const std::vector<double>& original_x1 = spline1.getX();
    //    const std::vector<double>& original_y1 = spline1.getY();


    //    // 7. Открываем Gnuplot
    //    openGnuplot();

    //    // 8. Строим график с использованием новой функции
    //    plotSplineAndExactFunction(original_x1, original_y1, spline_x1, spline_y1, exact_x, exact_y);

    //    // 9. Закрываем Gnuplot
    //    wcloseGnuplot();
    //}



    void ePolynom()
    {
        //_polynom for int

        //создание целочисленных полиномов
        _polynom<int> poly1, poly2, poly3;
        //создаем случайный вектор
        poly1.generateRandom(4, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
        //задаем имя вектора
        poly1.setName(L"p1");
        //выводит вектор на экран
        poly1.print();

        poly2.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
        poly2.setName(L"p2");
        poly2.print();


        poly3.setName(L"p3");
        //сумма полиномов
        poly3 = poly1 + poly2;
        poly3.print();
        //разность полиномов
        poly3 = poly1 - poly2;
        poly3.print();
        //перемножение векторов
        poly3 = poly1 * poly2;
        poly3.print();


        //создание дробного вектора
        _polynom<double> poly11, poly12, poly13;
        poly11.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
        poly11.setName(L"p11");
        poly11.print();

        poly12.generateRandom(3, -10.0, 10.0);  // Генерируем случайный полином степени 3 с коэффициентами в диапазоне [-10, 10]
        poly12.setName(L"p12");
        //при сложении вполне вероятно что старшие степени сократяться, значит итоговый полином будет на одну степень меньше, продемонстрируем это
        poly12[poly12.degree()] = -poly11[poly11.degree()];
        poly12[poly12.degree() - 1] = -poly11[poly11.degree() - 1];
        poly12.print();

        poly13.setName(L"p3");
        poly13 = poly11 + poly12;
        poly13.print();
        poly13 = poly11 * poly12;
        poly13.print();

    }

}


#endif



