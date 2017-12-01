#include <iostream>
#include <tuple>
using namespace std;

/*
*	代码出处:《深入应用C++11：代码优化与工程级应用》 —— 祁宇著
*	第三章
*		3.3.9，
*	所用代码:代码清章3-18，3-25
*
*	S1xe
*	Time:2016/10/31 0:30
*
*
*/

namespace details {
// tuple参数的索引序列
template <int...>
struct IndexTuple
{
};
template <int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...>
{
};
template <int... indexes>
struct MakeIndexes<0, indexes...>
{
    typedef IndexTuple<indexes...> type;
};
template <std::size_t N, typename T1, typename T2>
using pair_type =
    std::pair<typename std::tuple_element<N, T1>::type, typename std::tuple_element<N, T2>::type>;
template <std::size_t N, typename T1, typename T2>
pair_type<N, T1, T2> pair(const T1 &tup1, const T2 &tup2)
{
    return std::make_pair(std::get<N>(tup1), std::get<N>(tup2));
}
template <int... Indexes, typename T1, typename T2>
auto pairs_helper(IndexTuple<Indexes...>, const T1 &tup1, const T2 &tup2)
    -> decltype(std::make_tuple(pair<Indexes>(tup1, tup2)...))
{
    return std::make_tuple(pair<Indexes>(tup1, tup2)...);
}
} // namespace details end
template <typename Tuple1, typename Tuple2>
auto Zip(Tuple1 tup1, Tuple2 tup2) -> decltype(details::pairs_helper(
    typename details::MakeIndexes<std::tuple_size<Tuple1>::value>::type(), tup1, tup2))
{
    static_assert(std::tuple_size<Tuple1>::value == std::tuple_size<Tuple2>::value,
                  "tuples should be the same size.");
    return details::pairs_helper(
        typename details::MakeIndexes<std::tuple_size<Tuple1>::value>::type(), tup1, tup2);
}

// TuplePrint用于打印tuple,但不可用于嵌套的tuple
template <class Tuple, std::size_t N>
struct TuplePrinter
{
    static void print(const Tuple &t)
    {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};
template <class Tuple>
struct TuplePrinter<Tuple, 1>
{
    static void print(const Tuple &t) { std::cout << std::get<0>(t); }
};
template <class... Args>
void PrintTuple(const std::tuple<Args...> &t)
{
    std::cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")\n";
}

// TupleZip用于测试Zip函数
void TupleZip()
{
    auto tp1 = std::make_tuple<int, short, double, char>(1, 2, 2.5, 'a');
    auto tp2 = std::make_tuple<double, short, double, char>(1.5, 2, 2.5, 'z');
    auto mypairs = Zip(tp1, tp2);

    //注:无法用PrintTuple打印mypairs

    cout << "Successfully" << endl;
}

// TestPrint用于测试PrintTuple函数
void TestPrint()
{
    // auto tp = std::make_tuple<int, short, double, char>(1, 2, 2.5, 'a');
    auto tp = std::make_tuple(1, 2, 3, 'a');
    PrintTuple(tp);
    // 输出：(1,2,3,’a’)
}

int main()
{
    TupleZip();
    return 0;
}