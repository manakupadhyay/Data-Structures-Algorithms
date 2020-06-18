#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string topostfix(string s)
{
    stack<char> stk;
    stk.push('N');
    string ns;
    for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            ns += s[i];

        else if (s[i] == '(')
            stk.push(s[i]);

        else if (s[i] == ')')
        {
            while (stk.top() != 'N' && stk.top() != '(')
            {
                char a = stk.top();
                stk.pop();
                ns += a;
            }
            if (stk.top() == '(')
                stk.pop();
        }
        else
        {
            while (stk.top() != 'N' && prec(stk.top()) >= prec(s[i]))
            {
                char a = stk.top();
                stk.pop();
                ns += a;
            }
            stk.push(s[i]);
        }
    }
    while (stk.top() != 'N')
    {
        char c = stk.top();
        stk.pop();
        ns += c;
    }
    return ns;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        string infix = topostfix(s);
        cout << infix << endl;
    }
    return 0;
}