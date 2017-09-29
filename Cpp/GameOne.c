/*
Problem:
有两个正整数，两人进行游戏，轮流选择任意一个数并将它减半或连续减半，
奇数减半可以舍去0.5取整，并规定1不能再减半。最后不能减半的人输掉。
现在给出两个正整数，若轮到你先玩，双方都表现得足够优秀，问你是胜者还是败者。

Input：n1, n2
Output：YES（胜），NO（败）

Example1:
Input1:5 8
Output1:YES
Example2:
Input2:30 17
Output2:NO

*/

#include <stdio.h>

int bitJudge(int m)
{
    for (int i = 0;; i++) {
        if (m >> i == 0) return i;
    }
}
int main()
{
    char s;
    int n = 0;
    while ((s = getchar()) != EOF) {
        if (s == '\n') n++;
    }
    fprintf(stdout, "%d\n", n);

    return 0;
}