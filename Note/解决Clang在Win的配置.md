#### 解决Clang在Win的配置

本人环境,Win10+VS2017+Clang

所用Clang包为 [LLVM-4.0.0-win64.exe](http://112.17.14.33/cache/releases.llvm.org/4.0.0/LLVM-4.0.0-win64.exe?ich_args2=405-10010909011362_02a2356f8389c696524c40543c33dd42_10001002_9c886d2bd7c1f9d09e3b518939a83798_f15d15ce3bbbbd65a27de10d525e5286)

安装之后使用clang -v显示如下

```sh
$ clang -v
clang version 4.0.0 (tags/RELEASE_400/final)
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\Program Files\LLVM\bin
```

如何能让clang在Win下可用,只要设置相应环境变量即可

1.  INCLUDE

```sh
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\include;
C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\ucrt;
```

2.  LIB

```sh
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\lib\x64;
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.15063.0\ucrt\x64;
C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x64;
```

3.  Path

```sh
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\bin\HostX64\x64;
```

##### 小结

就此clang也算是可以在Win下使用

#### 一个疑惑

但是有一个很疑惑的地方想和大家讨论下,若有知道的请联系我

我测试所用代码为t.cpp,内容如下

```c++
#include<iostream>

int main()
{
    std::cout<<"Hello World"<<std::endl;
    return 0;
}
```

编译并运行的结果如下

```sh
$ clang++ t.cpp -o t.exe
t-bc4546.o : warning LNK4217: 本地定义的符号 __std_terminate 在函数 "int `public: static unsigned __int64 __cdecl std::char_traits<char>::length(char const * const)'::`1'::dtor$2" (?dtor$2@?0??length@?$char_traits@D@std@@SA_KQEBD@Z@4HA) 中导入
t-bc4546.o : warning LNK4217: 本地定义的符号 _CxxThrowException 在函数 "public: void __cdecl std::ios_base::clear(int,bool)" (?clear@ios_base@std@@QEAAXH_N@Z) 中导入
$ ./t.exe
Hello World
```

虽然也是能够编译了,但是这warning略显蛋疼,若有知道如何解决的各位也请联系我