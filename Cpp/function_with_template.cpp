#include <functional>
#include <iostream>

// Code Part 1
// void testfun(const std::function<void()> &f)
//{
//	f();
//}
//
// void fun1()
//{
//	std::cout << "Hello\n";
//}
// void fun2()
//{
//	std::cout << " World!\n";
//}

// Code Part 2
// std::function
template <typename T>
void testfun(std::function<T()> &f)
{
    f();
}

// function pointer
template <typename T>
void testfun(T (*f)())
{
    f();
}

template <typename T>
void testfun(T (*f)(T))
{
    f(3);
}

// function to test
void fun1()
{
    std::cout << "Hello World!\n";
}

int fun2()
{
    std::cout << 1 << std::endl;
    return 1;
}
int fun3(int x)
{
    std::cout << x << std::endl;
    return x;
}
int main()
{
    // Code Part 2
    auto f(fun1);
    testfun(f);
    auto f2(fun2);
    testfun(f2);

    // Code Part 2
    /*std::function<void()> f = fun1;
    testfun(f);
    f = fun2;
    testfun(f);*/

    // Code Part 1
    // normal std::function with void()
    /*std::function<void()> myfun = fun1;
    testfun(myfun);
    myfun = fun2;
    testfun(myfun);*/

    return 0;
}