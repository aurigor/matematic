//#ifndef TEST_H
//#define TEST_H
//#define TEST_API __declspec(dllexport)
//#else
//#define TEST_API __declspec(dllimport)
//#endif
//
//MATHLIBRARY_API  int add(int a, int b);
//int subtract(int a, int b);
//
//
//
//#endif



#ifndef TEST_H
#define TEST_H

// Проверяем, экспортируем мы библиотеку или импортируем
#ifdef BUILD_TEST_LIB
#define TEST_API __declspec(dllexport)  // Если собираем библиотеку, то экспортируем символы
#else
#define TEST_API __declspec(dllimport)  // Если подключаем библиотеку, то импортируем символы
#endif

// Декларация функций с правильным макросом
TEST_API int add(int a, int b);
TEST_API int subtract(int a, int b);

#endif // TEST_H

