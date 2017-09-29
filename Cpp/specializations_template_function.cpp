#include <iostream>

template <typename T>
void show(const T &A, const T &B)
{
    std::cout << A << "\t" << B << std::endl;
}

template <>
void show<int>(const int &A, const int &B)
{
    std::cout << A + B << std::endl;
}

int main()
{
    // specializations of template function
    show("Hello", "World");
    show(1, 3);

    return 0;
}