// File Name: StudyC++11/thread_once.cpp
// Author:
// Mail:
// Created Time: Wed 16 Nov 2016 02:10:30 PM CST
// How to compile: g++ thread_once.cpp -pthread -std=c++11 -o thread_once (the
// "-pthread" must be present)
#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;
void do_once()
{
    std::call_once(flag, []() { std::cout << "Called once" << std::endl; });
}

int main()
{
    std::thread t1(do_once);
    std::thread t2(do_once);
    std::thread t3(do_once);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
