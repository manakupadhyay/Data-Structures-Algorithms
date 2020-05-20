#include <iostream>
#include <stack>
using namespace std;
bool checkExpression(string s);
bool getTop();
stack<int> stk;
int main()
{
    string s;
    cout << "Enter the expression: ";
    getline(cin,s);
    bool ans=checkExpression(s);
    if(ans)
        cout << "Expression is balanced " << endl;
    else
        cout << "Expression is not balanced " << endl;
    return 0;
}
bool getTop(char ch)
{
    char c=stk.top();
    if(c=='(' && ch==')')
        return true;
    else if(c=='{' && ch=='}')
        return true;
    else if(c=='[' && ch==']')
        return true;
    else
        return false;
}
bool checkExpression(string s)
{

   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
       {
            stk.push(s[i]);
       }
       else if(s[i]==')' || s[i]=='}' || s[i]==']')
       {
            if(!(stk.empty()) && getTop(s[i])  )
            {
                stk.pop();
            }
            else{
                return false;
            }
       }

   }
   bool isempty = stk.empty();
   return isempty;
}
