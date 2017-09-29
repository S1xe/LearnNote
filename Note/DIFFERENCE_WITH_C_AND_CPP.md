#### 写在前面

Date:2016/12/08

Author:S1xe

Email:zbl914588599@gmail.com

#### 正文

1. C允许从void类型指针隐式转换成其他类型的指针,C++中为了安全考虑明令禁止了这种行为

   ```c
   //void*隐式转换为double*
   double *pDouble = malloc(nCount*sizeof(double));
   ```

   但在要在C++中正确允许,需要显式转换

   ```c++
   double *pDouble = (double*)malloc(nCount*sizeof(double));

   //用C++ style cast来完成转换
   double *pDouble = stacic_cast<double*>(malloc(nCount*sizeof(double)));
   ```

2. 一些可移植性问题,比如`new`和`class`在C++中是关键字,而在C中可以作为变量名

   若想在C++中使用大量现成的C程序库,必须把它放到`extern"C"{ /*code*/}`中

   因为C与C++具有不同的编译和链接方式.C编译器编译时不带函数的类型信息,只包含函数符号名字;而C++编译器为了实现函数重载,在编译时会带上函数的类型信息.

   假设某个函数的原型为`int Function(int a,float b)`

   C编译器把该函数编译成类似*_Function*的符号(一般被称为`mangled name`),C链接器只要找到这个符号,就可以链接成功,实现调用.

   而C++编译器会检查函数类型信息,上述函数原型会被编译成*_Function_int_float*这样的符号.在链接过程中,链接器会再由函数原型所在模块生成的目标文件中寻找*_Function_int_float*这样的符号.

   `extern"C"`的作用就是告诉C++链接器寻找调用函数的符号时,采用C的方式,让编译器寻找*_Function*而不是*_Function_int_float*

   ​

   要实现C++中调用C的代码,具体方式有以下几种

   (1)  修改C的代码头文件,当其中含有C++代码时,在声明中加入`extern"C"`

   ```c++
   /*C头文件 CDemo.h*/
   #ifndef C_SRC_DEMO_H
   #define C_SRC_DEMO_H
   extern"C" int Funcion(int x,int y);
   #endif

   /*C实现文件 CDemo.c*/
   #include"CDemo.h"
   int Function(int x,int y)
   {
      //processing code   
   }

   /*C++调用文件 main.cpp*/
   #include"CDemo.h"
   int main()
   {
      Function(2,3);
      return 0;
   }
   ```

   (2)  在C++代码中重新声明以下C函数,在重新声明时添加上`extern"C"`
   ```c++
   /*C头文件 CDemo.h*/
   #ifndef C_SRC_DEMO_H
   #define C_SRC_DEMO_H 
   extern int Funcion(int x,int y); 
   #endif
   /*C实现文件 CDemo.c*/

   #include"CDemo.h"
   int Function(int x,int y)
   {
     //processing code   
   }

   /*C++调用文件 main.cpp*/
   #include"CDemo.h"
   extern"C" int Funcion(int x,int y);
   int main()
   {
      Function(2,3);
      return 0;
   }
   ```
   (3)  在包含C头文件的时,添加上`extern"C"`
   ```c++
   /*C头文件 CDemo.h*/
   #ifndef C_SRC_DEMO_H
   #define C_SRC_DEMO_H 
   extern int Funcion(int x,int y); 
   #endif

   /*C实现文件 CDemo.c*/
   #include"CDemo.h"
   int Function(int x,int y)
   {
     //processing code   
   }

   /*C++调用文件 main.cpp*/
   extern"C"{
   #include"CDemo.h"
   } 
   int main()
   {
      Function(2,3);
      return 0;
   }
   ```


​   