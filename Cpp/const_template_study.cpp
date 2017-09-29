#include <iostream>

template <typename T1, typename T2>
void fun(const T1 &A, const T2 &B)
{
    std::cout << "const T1&A,const T2&B" << std::endl;
    std::cout << A << "\t" << B << std::endl;
}
template <typename T1, typename T2>
void fun(T1 &A, const T2 &B)
{
    std::cout << "T1&A,const T2&B" << std::endl;
    std::cout << A << "\t" << B << std::endl;
}
template <typename T1, typename T2>
void fun(T1 &A, T2 &B)
{
    std::cout << "T1&A, T2&B" << std::endl;
    std::cout << A << "\t" << B << std::endl;
}
template <typename T1, typename T2>
void fun(const T1 &A, T2 &B)
{
    std::cout << "const T1&A, T2&B" << std::endl;
    std::cout << A << "\t" << B << std::endl;
}

int main()
{
    int a = 8;

    fun(1, 2);
    fun(a, 3);

    return 0;
}
