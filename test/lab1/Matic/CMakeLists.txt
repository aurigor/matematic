cmake_minimum_required(VERSION 3.23)

set(project "Matic")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        matic.cpp graphics.cpp)

set(${project}_HEADERS
        matic.h matrix.h vector.h funct.h lambda.h example.h spline.h graphics.h time.h inLagrange.h polynom.h)

set(${project}_ADDITIONALLY
        ad-spline.h const.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS}
        ${${project}_ADDITIONALLY})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})


#set(Header_Files "Header Files")
# Категория "Source Files"
source_group("Source Files" FILES ${${project}_SOURCES})

# Категория "Header Files"
source_group("Header Files" FILES ${${project}_HEADERS})

# Категория "Additional Files" для ad-spline.h
source_group("Additional Files" FILES ${${project}_ADDITIONALLY})



#source_group("Header Files\\Approximation of Functions" FILES spline.h)
#source_group("Header Files\\Structures" FILES matrix.h vector.h funct.h lambda.h)
#source_group("Header Files\\Example" FILES example.h)
#source_group("Header Files\\Graphics" FILES graphics.h)