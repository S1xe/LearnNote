#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// lambda's rules
// 1.[capture] (params) mutable exception attribute -> ret{body}
// 2.[capture](params)->ret{body}
// 3.[capture](params) {body}
// 4.[capture]{body}

// lambda's capture
//[] 不截取任何变量
//[&} 截取外部作用域中所有变量，并作为引用在函数体中使用
//[=] 截取外部作用域中所有变量，并拷贝一份在函数体中使用
//[=, &foo]
//截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
//[bar] 截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
//[x, &y] x按值传递，y按引用传递
//[this] 截取当前类中的this指针。如果已经使用了&或者 = 就默认添加此选项。
template <typename T>
void display(const vector<T> &vec)
{
    auto func = [&](T i) { cout << i << " "; };
    for_each(vec.begin(), vec.end(), func);
    cout << endl;
}

int main()
{
    vector<int> c{1, 2, 3, 4, 5, 6, 7};
    vector<double> d{7.5, 7.9, 8.0, 8.1, 9.7};
    display(c);
    display(d);

    // auto func = [&](auto i) {cout << i << " ";};

    // C++11 lambda
    // for_each(c.begin(), c.end(), func);
    // cout << endl;
    // for_each(d.begin(), d.end(), func);
    // cout << endl;

    ////C++11 auto
    /*for (auto &i : c) {
        cout << i << " ";
    }
    cout << endl;*/

    ////copy
    // copy(c.begin(), c.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;

    /*int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }),
    c.end());
    copy(c.begin(), c.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    auto fun1 = [](int i) {return i + 4;};
    cout << fun1(5) << endl;
    function<int(int)> fun2 = [](int i) {return i + 4;};
    cout << fun2(5) << endl;*/

    /*string name;
    cin >> name;
    [&]()->void {cout << name << endl;}();*/

    // mutilate lambdas

    // x*2+3  -> 5*2+3=13
    /*int m = [](int x) { return 3 + [](int y) { return y * 2; }(x); }(5);
    cout << m << endl;*/

    // single lambda
    /*int a[10]{ 0 };

    srand(time(NULL));
    generate(a, a + 10, []() {return rand() % 100;});

    copy(a, a + 10, ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(a, a + 10, [&](int i) { cout << i << " ";});
    cout << endl;*/

    return 0;
}