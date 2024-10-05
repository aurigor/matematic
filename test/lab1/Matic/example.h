#ifndef EXAMPLE
#define EXAMPLE
#include<iostream>
#include"vector.h"
#include"graphics.h"
#include"spline.h"

using namespace std;

namespace test
{
	//example use _vector
	void tVector()
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


        // ��������� ������� a �� ���������
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


	////example use _matrix
	//void tMatrix(){


	//}


	////example use _function
	//void tFunction(){

	//}


    //void demoSplineAndPlot()
    //{
    //    // 1. ������ ��������� � �������� ��������, � ����� ���������� �����
    //    double x_start = 0.0;
    //    double x_end = 10.0;
    //    int num_nodes = 5;

    //    // 2. ���������� ������� ��� ��������� ��������
    //    auto func = [](double x) { return std::sin(x); };

    //    // 3. ������� ��������� ����������� �������
    //    _spline<double> spline(x_start, x_end, num_nodes, func);

    //    // 4. ���������� ������ ��� �������
    //    std::vector<double> spline_x, spline_y;
    //    spline.generateSplineData(spline_x, spline_y);

    //    // 5. �������� �������� ����
    //    const std::vector<double>& original_x = spline.getX();
    //    const std::vector<double>& original_y = spline.getY();


    //    std::vector<double> exact_x, exact_y;
    //    int num_points_exact = 100;  // ���������� ����� ��� ������ �������
    //    double step_exact = (x_end - x_start) / (num_points_exact - 1);
    //    for (int i = 0; i < num_points_exact; ++i)
    //    {
    //        double x = x_start + i * step_exact;
    //        exact_x.push_back(x);
    //        exact_y.push_back(func(x));  // �������� ������ �������
    //    }
    //    // 6. ��������� Gnuplot
    //    openGnuplot();

    //    // 7. ������ ������
    //    plotSplineWithPoints(original_x, original_y, spline_x, spline_y);
    //    
    //    
    //    std::cin.clear();
    //    std::cin.ignore(std::cin.rdbuf()->in_avail());
    //    std::cin.get();


    //    // 8. ��������� Gnuplot
    //    //closeGnuplot();


    //    // ������ ������� ������ ������ �������
    //    fputs("set title 'Cubic Spline vs. Original Points and Exact Function'\n", gnuplotPipe);
    //    fputs("plot $data with points pointtype 7 pointsize 1.5 linecolor 'red' title 'Original Points', \\\n", gnuplotPipe);
    //    fputs("     $spline with lines linetype 1 linewidth 2 linecolor 'blue' title 'Cubic Spline', \\\n", gnuplotPipe);

    //    // ���������� ������ ��� ������ �������
    //    fputs("$exact << EOD\n", gnuplotPipe);
    //    for (size_t i = 0; i < exact_x.size(); ++i)
    //    {
    //        fprintf(gnuplotPipe, "%lf %lf\n", exact_x[i], exact_y[i]);
    //    }
    //    fputs("EOD\n", gnuplotPipe);

    //    // ��������� ������ ������ �������
    //    fputs("     $exact with lines linetype 1 linewidth 2 linecolor 'green' title 'Exact Function'\n", gnuplotPipe);
    //    fflush(gnuplotPipe);  // ��������� ����� � ���������� ������ � gnuplot

    //    std::cout << "������ ������� ��������.\n";


    //    // 8. ��������� Gnuplot
    //    closeGnuplot();
    //}
    void demoSplineAndPlot()
    {
        // 1. ������ ��������� � �������� ��������, � ����� ���������� �����
        double x_start = 0.0;
        double x_end = 10.0;
        int num_nodes = 5;

        // 2. ���������� ������� ��� ��������� ��������
        auto func = [](double x) { return std::sin(x); };

        // 3. ������� ��������� ����������� �������
        _spline<double> spline(x_start, x_end, num_nodes, func);

        // 4. ���������� ������ ��� �������
        std::vector<double> spline_x, spline_y;
        spline.generateSplineData(spline_x, spline_y);

        // 5. �������� �������� ����
        const std::vector<double>& original_x = spline.getX();
        const std::vector<double>& original_y = spline.getY();

        // 6. ���������� ������ ��� ������ �������
        std::vector<double> exact_x, exact_y;
        int num_points_exact = 100;  // ���������� ����� ��� ������ �������
        double step_exact = (x_end - x_start) / (num_points_exact - 1);
        for (int i = 0; i < num_points_exact; ++i)
        {
            double x = x_start + i * step_exact;
            exact_x.push_back(x);
            exact_y.push_back(func(x));  // �������� ������ �������
        }

        // 7. ��������� Gnuplot
        openGnuplot();

        // 8. ������ ������ � �������������� ����� �������
        plotSplineAndExactFunction(original_x, original_y, spline_x, spline_y, exact_x, exact_y);

        // 9. ��������� Gnuplot
        wcloseGnuplot();



        // 1. ������ ��������� � �������� ��������, � ����� ���������� �����
        num_nodes = 10;

        // 2. ���������� ������� ��� ��������� ��������
        //auto func = [](double x) { return std::sin(x); };

        // 3. ������� ��������� ����������� �������
        _spline<double> spline1(x_start, x_end, num_nodes, func);

        // 4. ���������� ������ ��� �������
        std::vector<double> spline_x1, spline_y1;
        spline1.generateSplineData(spline_x1, spline_y1);

        // 5. �������� �������� ����
        const std::vector<double>& original_x1 = spline1.getX();
        const std::vector<double>& original_y1 = spline1.getY();


        // 7. ��������� Gnuplot
        openGnuplot();

        // 8. ������ ������ � �������������� ����� �������
        plotSplineAndExactFunction(original_x1, original_y1, spline_x1, spline_y1, exact_x, exact_y);

        // 9. ��������� Gnuplot
        wcloseGnuplot();
    }

}


#endif



