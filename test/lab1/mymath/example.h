#ifndef EXAMPLE
#define EXAMPLE
#include<iostream>
#include"vector.h"

using namespace std;

namespace test
{
	//example use _vector
	void tVector()
	{
        setlocale(LC_ALL, "Russian");

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




        //cout << "a is ";
        //a.print();

        //cout << "b is ";
        //b.print();

        //// Складываем векторы a и b
        //_vector<double> c = a + b;
        //cout << "c (a + b) is ";
        //c.print();

        //// Вычитаем векторы a и b
        //_vector<double> c1 = a - b;
        //cout << "c1 (a - b) is ";
        //c1.print();

        //// Поэлементное умножение векторов a и b
        //_vector<double> c2 = a * b;
        //cout << "c2 (a * b) is ";
        //c2.print();

        //// Скалярное произведение векторов a и b
        //double scalar_product_result = a.scalar_product(b);
        //cout << "Scalar product of a and b is " << scalar_product_result << "\n";

        //// Умножение вектора a на константу
        //_vector<double> c3 = a * 2.0;
        //cout << "c3 (a * 2.0) is ";
        //c3.print();

        //_vector<double> c4 = a * 2;
        //cout << "c4 (a * 2.0) is ";
        //c4.print();



	}


	////example use _matrix
	//void tMatrix(){


	//}


	////example use _function
	//void tFunction(){

	//}

}


#endif



