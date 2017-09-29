#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool JudgeLeft(char ch)
{
    if (ch == '(' || ch == '[' || ch == '{') return true;
    return false;
}

bool JudgeLR(char left, char right)
{
    if (left == '(' && right == ')') return true;
    if (left == '[' && right == ']') return true;
    if (left == '{' && right == '}') return true;
    return false;
}

int main()
{
    string str;
    cin >> str;
    stack<char> st;
    bool flag = true;
    const int lenth = str.size();

    if (lenth % 2) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < lenth; ++i) {
        if (JudgeLeft(str[i])) {
            // cout <<"st push : " <<str[i] << endl;
            st.push(str[i]);
        } else {
            // cout << st.top() << "\t" << str[i] <<"\t" <<JudgeLR(st.top(),
            // str[i]) << endl;
            if (JudgeLR(st.top(), str[i])) {
                st.pop();
            } else {
                flag = false;
                break;
            }
        }
    }
    if (flag == false || !st.empty())
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}