#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head;
void print();
void insertAtBegin(int);
void insertAtEnd(int);
void insertAtSpecified(int,int);
void deleteAtSpecified(int where);
void deleteAtBegin();
void deleteAtEnd();
void printbackwardrecursion(Node*);
void printforwardrecursion(Node*);
void reverse()
{
    Node* current=head;
    Node* next;
    while(current->next!=head)
    {
        next=current->next;
        current->next=current->prev;
        current->prev=next;
        current=next;
    }
    current->next=current->prev;
    current->prev=head;
   // head->prev=current;
    head=current;
}
int main()
{
    cout << "Enter the number of nodes in the list: ";
    int size,value,where;
    cin >> size;
    for(int i=0;i<size;i++)
    {
        cout << "Enter value: ";
        cin >> value;
       insertAtEnd(value);
    }
    print();
    cout << "Printing the list in reverse order: ";
    printbackwardrecursion(head);
    cout << endl;
    cout << "Printing the list in same order: ";
    printforwardrecursion(head);
    cout << endl;
       /*
    cout << "Enter the position where you want to insert the element" << endl;
    cin >> where;
    cout << "Enter the value: ";
    cin >> value;
    insertAtSpecified(where,value);
    print();
    */cout << "Enter the position where you want to delete the element: ";
    cin >> where;
    deleteAtSpecified(where);
    print();
    cout << "Reversing the list: ";
    reverse();
    print();
    return 0;

}
void printbackwardrecursion(Node* temp)
{
    if(temp->next==head)
    {
        cout << temp->data << " ";
        return;
    }
    printbackwardrecursion(temp->next);
    cout << temp->data << " ";

}
void printforwardrecursion(Node* temp)
{
    cout << temp->data << " ";
    if(temp->next==head)
    {
        return;
    }
    printforwardrecursion(temp->next);

}
void deleteAtSpecified(int where)
{
    Node* current=head;
    Node* forward=NULL;
    Node* backward=NULL;
    if(where==1)
    {
        forward=current->next;
        backward=current->prev;
        head=forward;
        backward->next=head;
        forward->prev=backward;
       // head=forward;
        delete current;
    }
    else
    {
        backward=head;
        for(int i=1;i<where-1;i++)
            backward=backward->next;
        current=backward->next;
        backward->next=current->next;
        forward=current->next;
        forward->prev=backward;

        delete current;
    }
}
void deleteAtBegin()
{
    Node* current=head;
    Node* temp;
    temp=current->prev;
    temp->next=current->next;
    Node* tem=current->next;
    tem->prev=temp;
    head=tem;
    delete current;
}
void insertAtSpecified(int where,int value)
{
    Node* newNode=new Node();
    newNode->data=value;
    Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    if(where==1)
    {
        newNode->next=head;
        newNode->prev=temp;
        temp->next=newNode;
        head=newNode;
    }
    else
    {
        temp=head;
        for(int i=1;i<where-1;i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }

}
void insertAtEnd(int value)
{
    Node* newNode = new Node();
    newNode->data=value;
    if(head==NULL)
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
    }
    else
    {
        Node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=head;

    }
}
void insertAtBegin(int value)
{
    Node* newNode =new Node();
    newNode->data=value;
    if(head==NULL)
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
    }
    else{
        newNode->next=head;
        Node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        head=newNode;
    }
}
void print()
{
    Node* temp=head;
    cout << "List is: ";
    while(temp->next!=head)
    {
        cout << temp->data <<  " ";
        temp=temp->next;
    }
    cout << temp->data;
    cout << endl;
}

