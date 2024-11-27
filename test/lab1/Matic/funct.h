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


// ����������� callable-������ � std::function
template<typename Ret, typename ... Args, typename F>
function<Ret(Args...)> toF(F func)
{
    function<Ret(Args...)> fun = func;
    return fun;  // ���������� ������ ���� std::function
}

// ������ ������� toF, �� ����� ����� �������, ���������� auto ��� ����������� ������������� ����
//template<typename Ret, typename F, typename ... Args>
//auto toF1(F func)
//{
//    function<Ret(Args...)> fun = func;
//    return fun;  // ���������� ������ ���� std::function
//}
// ����������� std::function � ������ _function
//template<typename Ret, typename ... Args>
//auto convertFunct(function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);  // ����������� � ������ _function
//    return fun;
//}
 
//template<typename Ret, typename ... Args>
//_function<Ret, Args...> convertFunct(std::function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);  // ������� ������ _function
//    return fun;
//}
//NOT WORK
// ����������� std::function � ������ _function
//template<typename Ret, typename ... Args, typename F>
//_function<Ret, Args...> convertFunct(F func)
//{
//    std::function<Ret(Args...)> fun = func;       // ����������� � std::function
//    return _function<Ret, Args...>(fun);          // ���� ������� ������ _function � ������ �������
//    //return _function<Ret, Args...>{fun};
//}
//template<typename Ret, typename ... Args, typename F>
//auto convertFunct(F func)
//{
//    std::function<Ret(Args...)> fun = func;
//    _function<Ret, Args...> f(func);  // ����������� � ������ _function
//    return f;
//}
//template<typename Ret, typename ... Args>
//auto convertFunct(function<Ret(Args...)> func)
//{
//    _function<Ret, Args...> fun(func);  // ����������� � ������ _function
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



//// ����� Function, �������������� ������������ ���������� ����������
//class Function {
//public:
//    // ��������� �����������, ����������� ����� callable �������
//    template<typename Func>
//    Function(Func func) : funcPtr([func](auto&&... args) -> double
//        {
//            return func(std::forward<decltype(args)>(args)...);
//        })
//    {
//    }
//
//    // ��������� �������� ������ ��� ������������� ���������� ����������
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // ����� ��� ������������� ������� � ���� ������
//    std::string toString() const
//    {
//        return "������������ �������";
//    }
//
//private:
//    // ������������� ��������� �� ������� � ������������� �����������
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
//// ����� Function, �������������� ������������ ���������� ����������
//class Function {
//public:
//    // ���������� ������ ��� �������� ������� � ������������ ����������� ����������
//    template<typename Func>
//    Function(Func func) : funcPtr([func](auto&&... args) -> double
//        {
//            return func(std::forward<decltype(args)>(args)...);
//        })
//    {
//    }
//
//    // ����� ��� ������ ������� � ��������� �����������
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // ����� ��� ������������� ������� � ���� ������
//    std::string toString() const
//    {
//        return "������������ �������";
//    }
//
//private:
//    std::function<double(double, double)> funcPtr;  // ������ ��������� �� �������
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
//    // ���������� ������ ��� �������� ������� � ������������ ����������� ����������
//    /*template<typename... Args>
//    Function(std::function<double(Args...)> func) : funcPtr(func) {}*/
//    template<typename... Args>
//    Function(function<double(Args...)> func) : funcPtr(func) {}
//
//    // ����� ��� ������ ������� � ��������� �����������
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // ����� ��� ������������� ������� � ���� ������ (��� �������)
//    std::string toString() const
//    {
//        return "������������ ������� (������������ � ���� ���������)";
//    }
//
//private:
//    template<typename... Args>
//    std::function<double(Args)> funcPtr;  // ������ ������� � ����� �����������
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
//    // ���������� ������ ��� �������� ������� � ���������� ����������� ����������
//    template<typename... Args>
//    Function(function<double(Args...)> func) : funcPtr(func) {}
//
//    // ����� ��� ������ ������� � ��������� �����������
//    template<typename... Args>
//    double operator()(Args... args) const
//    {
//        return funcPtr(args...);
//    }
//
//    // ����� ��� ������������� ������� � ���� ������ (��� �������)
//    string toString() const
//    {
//        return "������������ ������� (������������ � ���� ���������)";
//    }
//
//private:
//    function<double(double, double)> funcPtr;  // ������ �������
//};
//
//#endif