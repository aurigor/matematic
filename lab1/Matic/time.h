#ifndef _TIME_H
#define _TIME_H

#include <iostream>
#include <chrono>

// ������� ��� ��������� ������� ���������� ������� � �����������
template<typename Func, typename... Args>
double _Time(Func&& fun, Args&&... args)
{
    auto start = std::chrono::high_resolution_clock::now();
    fun(std::forward<Args>(args)...);  // �������� ��������� � �������
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();  // ���������� ����� � ��������
}

// ������� ��� ���������� �������� ������� ���������� ������� � �����������
template<typename Func, typename... Args>
double _sredTime(Func&& fun, int iterations, Args&&... args)
{
    double totalTime = 0.0;
    for (int i = 0; i < iterations; ++i)
    {
        totalTime += time(std::forward<Func>(fun), std::forward<Args>(args)...);  // �������� ���������
    }
    return totalTime / iterations;  // ���������� ������� �����
}

#endif
