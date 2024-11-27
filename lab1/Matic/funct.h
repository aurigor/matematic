#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <functional>
#include <string>


//template<typename Ret, typename ... Args>
//_function<Ret, Args...> convertFunct(function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);
//    return fun;
//    //return func;
//}


// Преобразует callable-объект в std::function
template<typename Ret, typename ... Args, typename F>
function<Ret(Args...)> toF(F func)
{
    function<Ret(Args...)> fun = func;
    return fun;  // Возвращаем объект типа std::function
}

// Аналог функции toF, но более общий вариант, использует auto для определения возвращаемого типа
//template<typename Ret, typename F, typename ... Args>
//auto toF1(F func)
//{
//    function<Ret(Args...)> fun = func;
//    return fun;  // Возвращаем объект типа std::function
//}
// Преобразует std::function в объект _function
//template<typename Ret, typename ... Args>
//auto convertFunct(function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);  // Преобразуем в объект _function
//    return fun;
//}
 
//template<typename Ret, typename ... Args>
//_function<Ret, Args...> convertFunct(std::function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);  // Создаем объект _function
//    return fun;
//}
//NOT WORK
// Преобразует std::function в объект _function
//template<typename Ret, typename ... Args, typename F>
//_function<Ret, Args...> convertFunct(F func)
//{
//    std::function<Ret(Args...)> fun = func;       // Преобразуем к std::function
//    return _function<Ret, Args...>(fun);          // Явно создаем объект _function с типами шаблона
//    //return _function<Ret, Args...>{fun};
//}
//template<typename Ret, typename ... Args, typename F>
//auto convertFunct(F func)
//{
//    std::function<Ret(Args...)> fun = func;
//    _function<Ret, Args...> f(func);  // Преобразуем в объект _function
//    return f;
//}
//template<typename Ret, typename ... Args>
//auto convertFunct(function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);  // Преобразуем в объект _function
//    return fun;
//}

//template<typename Ret, typename ... Args, typename F>
//function<Ret(Args...)> toF(F func)
//{
//    function<Ret(Args...)> fun = func;
//    return func;
//    //return func;
//}
//
//template<typename Ret, typename F, typename ... Args,  >
//auto toF1(F func)
//{
//    function<Ret(Args...)> fun = func;
//    return func;
//    //return func;
//}
//
//template<typename Ret, typename ... Args>
//auto convertFunct(function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);
//    return fun;
//    //return func;
//}

//template<typename Ret, typename ... Args>
//Ret tFunct(Args ...arg)
//{
//    return (arg + ...);
//}
//
//function<double(double)> tfunct1;
//function<double(double,double)> tfunct2;
//
//template<typename Ret, typename... Args>
//Ret fzero(Args... args)
//{
//    return Ret(0);
//}

template<typename ... Args>
auto fzero = [](Args ...args) { return 0.0; };

//template<typename Ret, typename ... Args>
//auto fzero = [](Args ...args) { return Ret(0); };

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






template<typename Ret, typename ... Args>
_function<Ret, Args...> convertFunct(std::function<Ret(Args...)> func)
{
    _function<Ret, Args...> fun(func);
    return fun;
}

template<typename Ret, typename ... Args, typename F>
auto convertFunct(F func) -> _function<Ret, Args...>
{
    std::function<Ret(Args...)> wrappedFunc = func;
    return _function<Ret, Args...>(wrappedFunc);
}

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