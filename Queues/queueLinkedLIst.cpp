
// Implementation of Queue using Linked List...


#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* front;
Node* rear;
void enQueue(int);
int deQueue();
int top();
void print();
bool isEmpty();
int main()
{
    front=rear=NULL;
    enQueue(2); print();
    enQueue(12); print();
    enQueue(8); print();
    cout << "Topping: " << top() << endl;
    enQueue(6); print();
    enQueue(9); print();
    bool emp=isEmpty();
    cout << "Is QUEUE empty? " << emp << endl;
    deQueue(); print();
    cout << "Topping: " << top() << endl;
    enQueue(7); print();
    deQueue(); print();
    cout << "Topping: " << top() << endl;
      emp=isEmpty();
    cout << "Is QUEUE empty? " << emp << endl;
     deQueue(); print();
      deQueue(); print();
       deQueue(); print();
        emp=isEmpty();
    cout << "Is QUEUE empty? " << emp << endl;
    deQueue();
     emp=isEmpty();
    cout << "Is QUEUE empty? " << emp << endl;
    return 0;
}
bool isEmpty()
{
    if(front==NULL && rear==NULL)
        return true;
    else
        return false;
}
int top()
{
    if(front==NULL && rear==NULL)
    {
        return -1;
    }
    else{
        Node* temp=front;
        return temp->data;
    }
}
int deQueue()
{
    Node* temp=front;
    if(front==NULL && rear==NULL)
        return -1;
    else if(front==temp && rear==temp){
        front=rear=NULL;
        //return temp->data;
    }
    else{
        front=front->next;

    }
    delete temp;
}
void enQueue(int ele)
{
    Node* newNode=new Node();
    newNode->data=ele;
    newNode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}
void print()
{
    Node* temp=front;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

