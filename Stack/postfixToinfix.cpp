#include <iostream>
#include <stack>
using namespace std;
int evualatePostfix(string);
int calculate(char ch,int,int);
stack <int> stk;
int main()
{
    cout << "Enter the postfix expression: ";
    string s;
    getline(cin,s);
    int ans=evualatePostfix(s);
    cout << "Answer is: "  <<  ans << endl;
    return 0;
}
int calculate(char ch,int op2,int op1)
{
    if(ch=='+') return op1+op2;
    else if(ch=='-') return op1-op2;
    else if(ch=='*') return op1*op2;
    else if(ch=='/') return op1/op2;
    else if(ch=='%') return op1%op2;
}
int evualatePostfix(string s)
{
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='%' || s[i]=='/')
        {
            int op2=stk.top(); stk.pop();
            int op1=stk.top();  stk.pop();
           ans=calculate(s[i],op2,op1);
            stk.push(ans);

        }
        else
        {
            stk.push(s[i]);
        }
    }
    return stk.top();
}
