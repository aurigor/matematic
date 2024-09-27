#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <functional>
#include <string>



template<typename Ret, typename ... Args>
Ret tFunct(Args ...arg)
{
    return (arg + ...);
}

function<double(double)> tfunct1;
function<double(double,double)> tfunct2;

//template<typename Args>
//function<double(Args)> testTempaltefunct1;
//template<typename ret,typename Args>
//class Fun {
//public:
//    /*Function(function<ret(Args...)> func) : testTempaltefunct1(func) {}*/
//    Function(function<ret(Args...)> func) {
//        testTempaltefunct1 = func;
//    }
//
//private:
//    function<ret(Args)> testTempaltefunct1;
//};
template<typename ret, typename... Args>
class _function {
public:
    /*Function(function<ret(Args...)> func) : testTempaltefunct1(func) {}*/
    /*_function(function<ret(Args...)> func)
    {
        testTempaltefunct1 = func;
    }*/
    explicit _function(std::function<ret(Args...)> func)
        : testTempaltefunct1(func)
    {
    }
    _function() : testTempaltefunct1(nullptr) {}
    /*_function()
    {
        testTempaltefunct1 = nullptr;
    }*/
    void set(function<ret(Args...)> func)
    {
        testTempaltefunct1 = func;
    }

    ret operator()(Args... args) const
    {
        return testTempaltefunct1(args...);
    }

private:
    function<ret(Args...)> testTempaltefunct1;
};



//// Класс Function, поддерживающий произвольное количество аргументов
//class Function {
//public:
//    // Шаблонный конструктор, принимающий любую callable функцию
//    template<typename Func>
//    Function(Func func) : funcPtr([func](auto&&... args) -> double
//        {
//            return func(std::forward<decltype(args)>(args)...);
//        })
//    {
//    }
//
//    // Шаблонный оператор вызова для произвольного количества аргументов
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // Метод для представления функции в виде строки
//    std::string toString() const
//    {
//        return "Произвольная функция";
//    }
//
//private:
//    // Универсальный указатель на функцию с произвольными аргументами
//    std::function<double(double, double)> funcPtr;
//};

#endif




//#ifndef FUNCTION
//#define FUNCTION
//
//#include <iostream>
//#include <functional>
//#include <string>
//
//// Класс Function, поддерживающий произвольное количество аргументов
//class Function {
//public:
//    // Используем шаблон для хранения функции с произвольным количеством аргументов
//    template<typename Func>
//    Function(Func func) : funcPtr([func](auto&&... args) -> double
//        {
//            return func(std::forward<decltype(args)>(args)...);
//        })
//    {
//    }
//
//    // Метод для вызова функции с заданными аргументами
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // Метод для представления функции в виде строки
//    std::string toString() const
//    {
//        return "Произвольная функция";
//    }
//
//private:
//    std::function<double(double, double)> funcPtr;  // Хранит указатель на функцию
//};
//
//#endif




//#ifndef FUNCTION
//#define FUNCTION
//
//#include <iostream>
//#include <functional>
//#include <string>
//
//class Function {
//public:
//    // Используем шаблон для хранения функции с произвольным количеством аргументов
//    /*template<typename... Args>
//    Function(std::function<double(Args...)> func) : funcPtr(func) {}*/
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
//    std::string toString() const
//    {
//        return "Произвольная функция (представлена в виде указателя)";
//    }
//
//private:
//    template<typename... Args>
//    std::function<double(Args)> funcPtr;  // Хранит функцию с двумя аргументами
//};
//
//#endif


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