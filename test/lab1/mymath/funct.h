#ifndef FUNCTION
#define FUNCTION

#include <iostream>
#include <functional>
#include <string>

class Function {
public:
    // ���������� ������ ��� �������� ������� � ������������ ����������� ����������
    /*template<typename... Args>
    Function(std::function<double(Args...)> func) : funcPtr(func) {}*/
    template<typename... Args>
    Function(function<double(Args...)> func) : funcPtr(func) {}

    // ����� ��� ������ ������� � ��������� �����������
    template<typename... Args>
    double operator()(Args... args) const
    {
        return funcPtr(args...);
    }

    // ����� ��� ������������� ������� � ���� ������ (��� �������)
    std::string toString() const
    {
        return "������������ ������� (������������ � ���� ���������)";
    }

private:
    template<typename... Args>
    std::function<double(Args)> funcPtr;  // ������ ������� � ����� �����������
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