@Author:S1xe
@Email:914588599@qq.com
@Time:2017/7/14 14:58


下面举例均以C++为例,其他语言不再赘述

1. 安装VSCode,[官方地址](https://code.visualstudio.com/)

2. 配置好你的编译器路径,确保可以

    如何验证,在命令行输入,若有相关信息输出则说明已配置成功

    ```sh
    g++ -v
    ```

3. 安装VSCode的插件Code Runner

4. 修改Code Runner的一些设置以方便能够在命令行中使用

    ```json
     "code-runner.runInTerminal": true,
     "code-runner.ignoreSelection": true,
    ```

5. 修改Code Runner对编译的设置,以C++为例

     修改code-runner.executorMap选项,由于比较冗长,在此处仅截取针对c++部分

    ```json
    "code-runner.executorMap": {     
        ...    
            "cpp": "g++ $fileName  -o $fileNameWithoutExt.exe && ./$fileNameWithoutExt.exe"
        ...
        },
    ```

6. 编写代码并使用Code Runner

    - 编写完代码,右键-Run Code 或者按Ctrl+Alt+N

7. 改进

    在第5项中,我们很容易看出这样的话仅针对于单个文件,不具备一定强度的普适性,比如你使用了多个文件,那就要回过头修改Code Runner的配置,显而易见这种方法比较繁琐;并且多个文件编译的话,写在一行也是极难控制的.

    如何改进呢?

    我采用的方法是使用Makefile,而在Code Runner的配置中,只要使用make就可以编译,比起总要修改Code Runner的配置总要来的好,当然缺点也是有的,就是你要指定要运行的文件名,这一点的话对于我本人来说一般也都是固定用main.exe,倒也无妨;以及你得学会Makefile的使用方法,花一两个小时学习下或者使用我下面提供的万能模板倒也可以

8. 其他

    - [万能Makefile模板](http://www.cnblogs.com/prettyshuang/p/5552328.html)

    注:使用makefile之前,需安装好make

    ```sh
    #source file
    #源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
    SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
    OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
    
    #target you can change test to what you want
    #目标文件名，输入任意你想要的执行文件名
    TARGET  := main
    
    #compile and lib parameter
    #编译参数
    CC      := g++
    LIBS    :=
    LDFLAGS :=
    DEFINES :=
    INCLUDE := -I.
    CFLAGS  := -g -Wall -std=c++11 -O3 $(DEFINES) $(INCLUDE)
    CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
    
    
    #i think you should do anything here
    #下面的基本上不需要做任何改动了
    .PHONY : everything objs clean veryclean rebuild
    
    everything : $(TARGET)
    
    all : $(TARGET)
    
    objs : $(OBJS)
    
    rebuild: veryclean everything
                    
    clean :
        rm -fr *.so
        rm -fr *.o
        
    veryclean : clean
        rm -fr $(TARGET)
    
    $(TARGET) : $(OBJS)
        $(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
    ```

    - Code Runner的配置

    ```json
    "code-runner.executorMap": {
        ...
        "cpp": "make && ./main.exe",
        ...
    }
    ```

祝使用愉快~