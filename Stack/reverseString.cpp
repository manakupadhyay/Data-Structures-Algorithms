
            // Applications of Stack: reversing a string using stack...
#include <iostream>
#include <stack>
using namespace std;
void Reverse(string,int);
int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin,s);
    Reverse(s,s.length());
}
void Reverse(string s,int len)
{
    stack <char> stk;
    for(int i=0;i<len;i++)
    {
        stk.push(s[i]);                 // push, pop and top are inbuilt functions of stack....
    }
    for(int i=0;i<len;i++)
    {
        s[i]=stk.top();
        stk.pop();
    }
    cout << s << endl;
}
