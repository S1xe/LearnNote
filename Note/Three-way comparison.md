### Three-way comparison

原文地址:[Three-way_comparison](http://en.cppreference.com/w/cpp/language/operator_comparison#Three-way_comparison)

阅读时间:约五分钟

---

>The three-way comparison operator expressions have the form

三元比较运算符有如下形式

`lhs<=>rhs`

>The expression returns an object such that

该表达式返回值如下:

- `(a <=> b) < 0` if `lhs < rhs`
- `(a <=> b) < 0` if `lhs < rhs`
- `(a <=> b) == 0` if `lhs and rhs are equal/equivalent`

> If one of the operands is of type bool and the other is not, the program is ill-formed.

若其中一个为bool类型,另一个不是,那么程序是ill-formed的.

---

>If both operands have arithmetic types, the usual arithmetic conversions are applied to the operands, and then

若两个均为算术类型,且通常的算术转换将被使用,并有如下限制:

- >If a narrowing conversion is required, other than from an integral type to a floating point type, the program is ill-formed.
 
    若发生窄化,除了整型转换到浮点型外,程序是ill-formed的.

- > Otherwise, if the operands have integral type, the operator yields a prvalue of type std::strong_ordering:

    否则,若操作数中含整数类型,该比较将产生一个`std::strong_ordering`类型的`prvalue`:

    - > std::strong_ordering::equal if both operands are arithmetically equal,

        std::strong_ordering::equal 若两操作数算术相等

    - > std::strong_ordering::less if the first operand is arithmetically less than the second

        std::strong_ordering::less  若前者算术小于后者

    - > std::strong_ordering::greater otherwise.

        std::strong_ordering::greater   若前者算术大于后者

- > Otherwise, the operands have floating-point type, and the operator yields a prvalue of type std::partial_ordering. The expression a <=> b yields

    否则,操作数中含浮点型,该比较将产生一个`std::partial_ordering`类型的`prvalue`.`a<=>b`该表达式比较结果如下:

    - > std::partial_ordering::less if a is less than b

        std::partial_ordering::less 若a小于b

    - > std::partial_ordering::greater if a is greater than b

        std::partial_ordering::greater  若a大于b

    - > std::partial_ordering::equivalent if a is equivalent to b (-0 <=> +0 is equivalent)
        
        std::partial_ordering::equivalent   若a与b相等(其中,`-0<=>+0` 是相等的)

    - > std::partial_ordering::unordered (NaN <=> anything is unordered)

        std::partial_ordering::unordered   NaN(Not a number)和任何比较都是无序的

---

> If both operands have the same enumeration type E, the operator yields the result of converting the operands to the underlying type of E and applying `<=>` to the converted operands.

若操作数具有相同的枚举类型E,则将会把操作数转换成E的基本类型后进行比较.

---

> If at least one of the operands is a pointer or pointer-to-member, array-to-pointer conversions, derived-to-base pointer conversions, function pointer conversions, and qualification conversions are applied as necessary to convert both operands to the same pointer type.

若至少一个操作数为指针(为如下其一的,`pointer`,`pointer-to-member`,`array-to-pointer conversion`,`derived-to-base pointer conversion`,`function pointer conversion`,`qualification conversion`),则会将两操作数转换成相同指针类型后进行比较.



> If the resulting pointer type is a function pointer, a pointer to member, or std::nullptr_t, p <=> q returns a prvalue of type std::strong_equality:  ( since C++20 )

若转换结果是`function pointer`,`pointer to member`,`std::nullptr_t`三者之一的,`p<=>q`将得到一个`std::strong_equality`类型的`prvalue`: ( since C++20 )

- > std::strong_equality::equal if p == q

    std::strong_equality::equal 若p与q相等

- > std::strong_equality::unequal if p != q

    std::strong_equality::unequal   若p与q不等

- > unspecified result if the equality comparison is unspecified for these pointer values

    若两指针的相等比较是未指定的,则结果是未指定的

> If the resulting pointer type is an object pointer type, p <=> q returns a prvalue of type strong_ordering:

若转换结果是`object pointer`,`p<=>q`将得到一个`std::strong_ordering`类型的`prvalue`:

- > std::strong_ordering::equal if p == q

    std::strong_ordering::equal 若p与q相等

- > std::strong_ordering::less if q > p

    std::strong_ordering::less 若p小于q

- > std::strong_ordering::greater if p > q.

    std::strong_ordering::greater 若p大于q

- > unspecified result if comparison is unspecified for these pointer values (such as when they do not point into the same object or array)

    若两指针的比较是未指定的,则结果是未指定的(例如，当它们不指向同一对象或数组时)

---

> In overload resolution against user-defined operators, for pointer or enumeration type T, the following function signature participates in overload resolution:

在针对用户定义操作符的重载决议中，对于指针或枚举类型T，如下声明的函数签名将参与重载解析：

`R operator<=>(T, T);`

> Where R is the ordering category type defined above.

其中R的类型为以上定义的排序类别类型

> For every T that is a pointer-to-member type or the type std::nullptr_t, the following function signature participates in overload resolution:

每一个T是一个`pointer-to-member`或`std:：nullptr_t`，如下声明的函数签名将参与重载决议：

`std::strong_equality operator<=>(T, T);`

### Note

> If both of the operands are arrays, three-way comparison is ill-formed except when comparing class members of array type

若两操作数为数组,三元比较是ill-formed,除非比较类的数组成员.


```c++
unsigned int i = 1;
auto r = -1 < i; // existing pitfall: returns ‘false’
auto r = -1 <=> i // Error: non-homogeneous
```

---

这是截止2017-12-14 9:28,[cppreference](http://en.cppreference.com/w/cpp/language/operator_comparison#Three-way_comparison)上的内容,不过貌似是未完全的,毕竟C++20还没有完全出来.

若有什么纰漏或者差错也请及时联系更改.
