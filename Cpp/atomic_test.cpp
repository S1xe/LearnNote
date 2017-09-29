// File Name: atomic_test.cpp
// Author:
// Mail:
// Created Time: Wed 16 Nov 2016 01:57:30 PM CST
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

// use the std::lock_guard and std::mutex
struct Counter {
    int value;
    std::mutex mutex;
    void increment()
    {
        std::lock_guard<std::mutex> lock(mutex);
        ++value;
    }
    void decrement()
    {
        std::lock_guard<std::mutex> lock(mutex);
        --value;
    }
    int get()
    {
        return value;
    }
};

// use the std::atomic simplify the code
struct AtomicCounter {
    std::atomic<int> value;
    void increment()
    {
        ++value;
    }
    void decrement()
    {
        --value;
    }
    int get()
    {
        return value.load();
    }
};

int main()
{
    return 0;
}
