Win下使用JNA在Java中调用DLL

### **所用环境**
- Win10
- Eclipse
- VS2017
- JNA(jna-4.4.0.jar)

```
jna-4.4.0.jar

github:https://github.com/java-native-access/jna

百度云 :链接:https://pan.baidu.com/s/1dEA11RV 密码: yyrk

```
---

### **具体操作**

#### 生成DLL

1. 使用VS2017新建项目

2. 应用程序类型中勾选DLL，附加选项中勾选导出符号

3. 修改导出符号

以我的项目为例，项目名为TestDynamic

下面是VS2017自动生成代码
```C++
#ifdef TESTDYNAMIC_EXPORTS
#define TESTDYNAMIC_API __declspec(dllexport)
#else
#define TESTDYNAMIC_API __declspec(dllimport)
#endif
``` 

由于JNA只能调用C导出的，故需修改为以下代码
```c++
#ifdef TESTDYNAMIC_EXPORTS
#define TESTDYNAMIC_API extern "C" __declspec(dllexport)
#else
#define TESTDYNAMIC_API extern "C" __declspec(dllimport)
#endif
```

4. 编写所需导出代码

在TestDynamic.h中添加如下代码
```c++
#include<iostream>

TESTDYNAMIC_API void myprint();
TESTDYNAMIC_API int square(int n);
```
在TestDynamic.cpp中添加如下代码
```c++
TESTDYNAMIC_API void myprint()
{
	std::cout << "Hello DLL\n";
}
TESTDYNAMIC_API int square(int n) 
{
	return n*n;
}
```

5. 若为64位，则选择x64，然后生成TestDynamic.dll(dll名字一般与项目名一致)


#### 新建Java工程

6. 打开Eclipse新建工程TestDLL

7. 将生成的TestDynamic.dll和jna-4.4.0.jar放在TestDLL工程目录下，并将jna-4.4.0.jar Add to Build Path

8. 编写代码
```java
import com.sun.jna.Library;
import com.sun.jna.Native;

public class TestDLL {
	interface DllHelper extends Library{
        //dll名为TestDynamic.dll，填参数无需后缀
		DllHelper instance=(DllHelper)Native.loadLibrary("TestDynamic",DllHelper.class);
        //dll导出的函数
		public int square(int n);
		public void myprint(); 
	}
	public static void main(String[] args) {
		long ret=DllHelper.instance.square(20);
		System.out.println(ret);
		DllHelper.instance.myprint();

	}

}
```

9. 编译运行

结果如下

```
400
Hello DLL
```
### **总结**

JNA相对的局限性较大，只能调用C的导出，即若不加extern "C" 否则在Java调用DLL时将无法查找到函数