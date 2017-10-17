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

截止至2017-10-17,wandbox-vscode的版本为2.2.1,

此前已提issue提交多文件的bug,作者已处理,暂未发布新版本

等新版本发布之后该文章再做更新

#### 实用命令

`Wandbox:Share` 

`Wandbox:Set Server`

`Wandbox:Rest Settings`

`Wandbox:Clear`


**未完待续**
    
