
    // implementation of stack using linked list...
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
Node* top=NULL;
void push(int item);
void pop();
int topp();
bool isEmpty();
void print();
int main()
{
    push(10); print();
    push(0); print();
    push(1); print();
    push(19); print();
    push(5); print();
    push(8); print();
    pop(); print();
    topp(); print();
    push(11); print();
    isEmpty();
    topp(); print();
    return 0;
}
void print()
{
    Node* temp=top;
    cout << "Stack: ";
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->link;
    }
    cout << endl;
}
void push(int item)
{
    Node* temp=new Node();
    temp->link=top;
    temp->data=item;
    top=temp;
}
void pop()
{
    if(top==NULL){
        cout << "Stack underflow" << endl;
        return ;
    }
    Node* temp=new Node();
    temp=top;
    top=temp->link;
    delete temp;
}
int topp()
{
    Node* temp=new Node();
    temp=top;
    //top=temp->link;
    return(temp->data);
}
bool isEmpty()
{
    if(top==NULL)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
}
