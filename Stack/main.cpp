
        // implementation of stack using array...
#include <iostream>
#define maxSize 10
using namespace std;

class Stack
{
    int arr[maxSize];
    int tos;
    public:
        Stack(){
            tos=-1;
        }
        void print();
        void input();
        void push(int );
        void pop();
        int top();
        int isEmpty();
        int search(int);
};
int Stack :: search(int ele)
{
    for(int i=0;i<=tos;i++)
    {
        if(arr[i]==ele){
            return i;
        }
    }
    return -1;
}
void Stack :: push(int item)
{
    if(tos==maxSize-1){
        cout << "Stack overflow" << endl;
        return;
    }
    else{
        arr[++tos]=item;
    }
}
void Stack :: pop()
{
    if(tos==-1){
        cout << "Stack underflow" << endl;
        return;
    }
    tos--;
}
int Stack :: top()
{
    return arr[tos--];
}
int Stack :: isEmpty()
{
    if(tos==-1)
    {
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty " << endl;
    }
}
void Stack :: print()
{
    cout << "Stack: ";
    for(int i=0;i<=tos;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack so;
    so.push(2);  so.print();
    so.push(4); so.print();
    so.push(1); so.print();
    so.push(10);    so.print();
    so.push(12);    so.print();
    so.pop();
    so.print();
    int z=so.search(12);
    if(z>=0)
        cout << "Element found at " << z+1 << "position " << endl;
    else
        cout << "element not found" << endl;
    int x=so.top();
    cout << x << " is removed " << endl; so.print();
    x=so.top();
    cout << x << " is removed" << endl; so.print();
    so.push(12); so.print();
    so.isEmpty();
     so.push(2);  so.print();
    so.push(4); so.print();
    so.push(1); so.print();
    so.push(10);    so.print();
    so.push(12);    so.print();
     so.push(10);    so.print();
    so.push(12);    so.print();
        so.push(12);    so.print();

    return 0;
}
