# matematic
 
##установка
Зайти в папку lab1.
вызвать в ней командную строку

в командной строке написать команду: mkdir build
потом: cd build
потом: cmake ..

после чего будет создан sln проект.

для сборки нужен cmake не ниже версии 3.23

при запуске проекта в visual studio, будет запущенно несколько проектов одновременно, поэтому при попытке компиляции будет выходить ошибка, так как среда не знает какой проект запускать, для запуска надо выбрать проект lab1

критические ошибки
в проекте на данный момент присутсвует несогласованность выводов cout и wcout, при использовании вывода cout, среда будет вызывать ошибку