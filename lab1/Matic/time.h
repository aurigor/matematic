#ifndef _TIME_H
#define _TIME_H

#include <iostream>
#include <chrono>

// Функция для измерения времени выполнения функции с аргументами
template<typename Func, typename... Args>
double _Time(Func&& fun, Args&&... args)
{
    auto start = std::chrono::high_resolution_clock::now();
    fun(std::forward<Args>(args)...);  // Передаем аргументы в функцию
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();  // Возвращаем время в секундах
}

// Функция для вычисления среднего времени выполнения функции с аргументами
template<typename Func, typename... Args>
double _sredTime(Func&& fun, int iterations, Args&&... args)
{
    double totalTime = 0.0;
    for (int i = 0; i < iterations; ++i)
    {
        totalTime += time(std::forward<Func>(fun), std::forward<Args>(args)...);  // Передаем аргументы
    }
    return totalTime / iterations;  // Возвращаем среднее время
}

#endif
