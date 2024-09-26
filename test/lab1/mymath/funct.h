#ifndef FUNCTION
#define FUNCTION

#include <iostream>
#include <functional>
#include <string>

class Function {
public:
    // Используем шаблон для хранения функции с произвольным количеством аргументов
    /*template<typename... Args>
    Function(std::function<double(Args...)> func) : funcPtr(func) {}*/
    template<typename... Args>
    Function(function<double(Args...)> func) : funcPtr(func) {}

    // Метод для вызова функции с заданными аргументами
    template<typename... Args>
    double operator()(Args... args) const
    {
        return funcPtr(args...);
    }

    // Метод для представления функции в виде строки (для примера)
    std::string toString() const
    {
        return "Произвольная функция (представлена в виде указателя)";
    }

private:
    template<typename... Args>
    std::function<double(Args)> funcPtr;  // Хранит функцию с двумя аргументами
};

#endif


//#ifndef FUNCTION
//#define FUNCTION
//#include <iostream>
//#include <functional>
//#include <vector>
//#include <stdexcept>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//
////template<typename T, typename arg>
////struct funct {
////    T function()
////};
//
////template<typename T>
//class Function {
//public:
//    // Используем шаблон для хранения функции с переменным количеством аргументов
//    template<typename... Args>
//    Function(function<double(Args...)> func) : funcPtr(func) {}
//
//    // Метод для вызова функции с заданными аргументами
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // Метод для представления функции в виде строки (для примера)
//    string toString() const
//    {
//        return "Произвольная функция (представлена в виде указателя)";
//    }
//
//private:
//    function<double(double, double)> funcPtr;  // Хранит функцию
//};
//
//#endif