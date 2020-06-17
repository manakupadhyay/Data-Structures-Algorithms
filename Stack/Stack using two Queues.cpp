#include <iostream>
#include <queue>
using namespace std;
queue<int> q1,q2;
void push(int ele)
{
    q1.push(ele);
}
int pop()
{
    if(q1.empty())
        return -1;
    while(q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int ans = q1.front();
    q1.pop();
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return ans;
}
int main()
{
    
    int choice = 1;
    int option;
    while(choice!=0)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cin >> option;
        switch(option)
        {
            case 1: cout << "Enter element: ";
            cin >> option;
            push(option);
            break;
            case 2: option = pop();
            if(option==-1)
                cout << "Stack is Empty" << endl;
            else
                cout << option << endl;
            break;

        }
        cout << "Enter 1 for again 0 for exit: ";
        cin >> choice;
    }
    return 0;
}