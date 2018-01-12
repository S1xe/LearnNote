```c++
#include<iostream>
using namespace std;
int globel=0;

// 在fun函数中,localstatic是静态局部变量,只初始化一次,数值累计,出函数不可见
//  local 是局部变量,每调用一次函数则初始化一次,出函数不可见
// globel 是全局变量,只初始化一次,全局可见(含函数内可见)
void fun()
{
    static int  localstatic=0;
    int local=0;
    globel++; 
    local++;
    localstatic++;
}

// 在pfun函数中,globel可见,而上面fun函数的变量常规使用不可见
void pfun()
{
   globel++; 
}
int main()
{
    fun();//globel=1 localstatic=1
    fun();//globel=2 localstatic=2
    pfun();//globel=3
    fun();//globel=4 localstatic=3
    return 0;
}
```