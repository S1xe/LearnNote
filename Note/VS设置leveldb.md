## VS设置leveldb ##

配置之前,编译leveldb需要先编译64bit的boost,以及编译出64bit的leveldb,这些不再赘述

本文侧重于,如何在VS上设置好leveldb

本文会涉及到的几个路径

```
leveldb的include为D:\zbl\GitHub\leveldb\include

leveldb的lib为D:\zbl\GitHub\leveldb\build

boost的lib为G:\boost_1_64_0\stage\lib
```

1. 新建工程,并设置为Release X64,必须为64位的Release

2. 设置好leveldb的include和lib,以及boost的lib

    设置include的路径  

    `项目属性` - `VC++目录` - `包含目录` 

    添加D:\zbl\GitHub\leveldb\include;

    设置lib的路径    
    `项目属性` - `VC++目录` - `库目录` 
    添加 D:\zbl\GitHub\leveldb\build;G:\boost_1_64_0\stage\lib;

    设置会用到的leveldb.lib `项目属性` - `链接器` - `输入` - `附加依赖项` 添加leveldb.lib

3. 修改运行库设置

    `项目属性` - `C/C++` - `代码生成` - `运行库`  改为`多线程 (/MT)`

4. 编写代码

    ```c++
    #include <leveldb/db.h>
    #include <string>
    #include <iostream>

    int main()
    {
        leveldb::DB* db;
        leveldb::Options options;
        options.create_if_missing = true;
        const std::string path = "test";
        leveldb::Status status = leveldb::DB::Open(options, path, &db);
        assert(status.ok());
        const std::string key = "test";
        std::string val="Hi,level!";
        leveldb::Status st = db->Put(leveldb::WriteOptions(), key, val);
        val.clear();
        st = db->Get(leveldb::ReadOptions(), key, &val);
        std::cout << key << ": " << val << std::endl;
        return 0;
    }
    ```

5. 总结

- 一定要以64位编译boost和leveldb

- VS项目也同样得是64位的Release

- 修改运行库设置为多线程

祝使用愉快~
