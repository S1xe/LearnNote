#include <iostream>
void funT(int &A, int &B)
{
    std::cout << "int &A,int &B" << std::endl;
    std::cout << A + B << std::endl;
}
void funT(int &A, const int &B)
{
    std::cout << "int &A,const int &B" << std::endl;
    std::cout << A + B << std::endl;
}
void funT(const int &A, const int &B)
{
    std::cout << "const int &A,const int &B" << std::endl;
    std::cout << A + B << std::endl;
}
// void funT(int A,int B)
//{
//	std::cout << "int A,int B" << std::endl;
//	std::cout << A + B << std::endl;
//
//}

void test(const int &i) { printf("%p\n", &i); }
int main()
{
    //如果引用参数是const，则编译器将在下面两种情况下生成临时变量：
    // 1.实参的类型正确，但不是左值
    // 2.实参的类型不正确，但是可以转换为正确的类型
    /*int a = -10;
    int b = 0;
    funT(10, 2);
    funT(a, b);
    funT(10, a);
    funT(a,10);*/
    test(1);
    test(1);
    int a = 8;
    printf("%p\n", &a);
    test(a);
    return 0;
}