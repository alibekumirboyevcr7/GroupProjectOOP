cmake_minimum_required(VERSION 3.29)
project(GroupProjectOOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(GroupProjectOOP main.cpp
        User.h
        User.cpp
        Admin.h
        Store.h
        Admin.cpp
        Store.cpp
        Product.h
        Product.cpp
        Cart.h
        Cart.cpp
        Payment.h
        Payment.cpp)
