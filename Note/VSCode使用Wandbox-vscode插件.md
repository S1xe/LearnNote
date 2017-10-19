下面举例均以C++为例,其他语言不再赘述

#### 简单介绍

[https://wandbox.org/](https://wandbox.org/) 是一个提供在线编译的网站,针对C/C++来说,提供了许多编译器版本供选择,也可以在该网站上测试一些新特性

wandbox-vscode [官方地址](https://github.com/wraith13/wandbox-vscode/),则是利用了[https://wandbox.org/](https://wandbox.org/) 提供的接口将本地文件上传[https://wandbox.org/](https://wandbox.org/) ,并编译运行

总的来说,适用于一些需要编译器多版本测试或者不想安装本地编译器的使用者

#### 安装步骤

- 安装VSCode,[官方地址](https://code.visualstudio.com/)

- 搜索插件`wandbox-vscode`

    如下图所示

    ![wandbox-vscode](https://raw.githubusercontent.com/S1xe/LearnNote/master/Data/img/wandbox_install.png)

#### 使用步骤

- 先编写一段代码，名为`main.cpp`

```c++
#include <iostream>
using namespace std;
int main() {
    cout << "Hello World,20171017" << endl;
    return 0;
}
```

- 设置所需编译器及其选项

    如下图所示
        
    ![wandbox_set_compiler](https://raw.githubusercontent.com/S1xe/LearnNote/master/Data/img/wandbox_set_compiler_.png)
   
    -   设置所需编译器

        `F1` -> `Wandbox:Set Compiler` -> 设置自己需要的

    -   设置所需编译选项

        `F1` -> `Wandbox:Set Options` -> 设置自己需要的

-  提交编译

    `F1` -> `Wandbox:Run`

完整操作见下图

![wandbox_set_compiler](https://raw.githubusercontent.com/S1xe/LearnNote/master/Data/img/wandbox_set_compiler.gif)

#### 设置输入文件

从上述操作中，不难看出这个插件还是比较方便使用的，但是有些时候需要我们输入数据，不要着急往下看

- 修改上述代码，添加需要输入部分

```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "Hello World,20171017" << endl;
    cout << "The n is " << n << endl;
    return 0;
}
```

- 设置输入文件

    `F1` -> `Wandbox:Set Options` -> `Select a file as input` -> `new untitled document`

    在新开的`Untitled-1`页面中输入想要的数值，比如1000

    > 注意:这个页面是不能被关闭的噢~

- 提交编译

    `F1` -> `Wandbox:Run`

完整过程如下图所示

![wandbox_set_input](https://raw.githubusercontent.com/S1xe/LearnNote/master/Data/img/wandbox_set_input.gif)

#### 有关多文件编译

- 编写头文件代码

`Hello.hpp`代码如下

```c++
#ifndef HELLO_HPP
#define HELLO_HPP

int fun() {
    return 0;
}

#endif
```

- 编写主函数文件代码

`main.cpp`代码如下

```c++
#include <iostream>
#include "Hello.hpp"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    cout << fun() << endl;
    return 0;
}
```

- 设置提交多文件

    `F1` - `Wandbox:Set Options` - `Select a add file` - 选中`Hello.hpp` 

- 提交编译

    `F1` -> `Wandbox:Run`

完整过程如下图所示

![wandbox_set_input](https://raw.githubusercontent.com/S1xe/LearnNote/master/Data/img/wandbox_set_mutli_input.gif)


#### 实用命令

`Wandbox:Share` 

`Wandbox:Set Server`

`Wandbox:Rest Settings`

`Wandbox:Clear`


#### 写在最后

由于一些`wandbox.org`的缘故,即编译选项相对单一(只执行一条g++编译命令),不能比较完全实现类似于本地编译多文件的功能(如,Makefile处理多文件编译),但是也可以通过一些另类的include方法实现多文件编译.

综上,虽然有些小限制,但是这个网站和插件还是相对方便于使用者
    
如有问题,请及时反馈~~
