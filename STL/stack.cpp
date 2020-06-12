#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    // create a stack of integers
    stack<int> s;       
    // push elements to the top of stack
    s.push(10); s.push(19); s.push(91); s.push(29); s.push(3);
    print(s);
    // pop
    s.pop();
    // return the top element
    cout << s.top() << endl;
    // returns the size of stack
    cout << s.size() << endl;
    return 0;
}