

        // implementation of circularly linked list...

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;
void insertAtBegin(int);
void insertAtLast(int);
void insertAtSpecified(int,int);
void deleteAtStart();
void deleteAtLast();
void deleteAtSpecified(int);
void print();
void findElement(int);
void printbackwardrecursion(Node* temp);
void printforwardrecursion(Node*);
void reverseRecursion(Node*);
void reverse()
{                                                          // WOOOHOOOOOOO....
    Node* current=head;
    Node* prev=NULL;
    Node* next;
    while(current->next!=head)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head->next=current;
    current->next=prev;
    head=current;

}
int main()
{
        head=NULL;
        int items,value;
        cout << "Enter the number of items: ";
        cin >> items;
        cout << "Enter the items in the list: " << endl;
        for(int i=0;i<items;i++){
            cout << "Enter " << i+1 << " item:";
            cin >> value;
            insertAtBegin(value);
        }
        print();
        cout << "Printing the list in reverse order: ";
        printbackwardrecursion(head);
        cout << endl;
        cout << "Printing the list in same order: ";
        printforwardrecursion(head);
        cout << endl;
        cout << "Reversing the list using recursion: ";
        reverseRecursion(head);
        print();
        /*
        int where;
        cout << "Enter the position where you want to insert the node: ";
        cin >> where;
        insertAtSpecified(where,0);
        print();
        /*cout << "Deleting the first item from the list: ";
        deleteAtStart();
        print();
        cout << "Deleting the last item from the list: ";
        deleteAtLast();
        print();
        cout << "Enter the position where you want to delete the element: ";
        cin >> where;
        deleteAtSpecified(where);
        print();*/
        cout << "Reversing the list: ";
        reverse();
        print();

        return 0;
}
void reverseRecursion(Node* temp)
{
    if(temp->next==head)
    {
        head=temp;
        return;
    }
    reverseRecursion(temp->next);
    Node* p=temp->next;
    p->next=temp;
    temp->next=head;

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
void findElement(int value)
{
    Node* temp=head;
    int i=0;
    bool found=false;
    while(temp->next!=head){
        if(temp->data==value){
            cout << "Element found at " << i+1 << " position " << endl;
            found=true;
            return;
        }
        else{
            temp=temp->next;
            i++;
        }
    }
    if(temp->data==value){
        cout << "Item found at "  << i+1 << " position " << endl;
        return;
    }
    if(found==false){
        cout << "Element not found" << endl;
        return;
    }
}
void deleteAtSpecified(int where)
{
    Node* current=new Node();

    Node* temp=head;
    if(where==1){
        while(temp->next!=head){
            temp=temp->next;
        }
        current=head;
        temp->next=current->next;
        delete current;
        head=temp->next;
    }
    else{
        for(int i=1;i<where-1;i++){
            temp=temp->next;
        }
        current=temp->next;
        temp->next=current->next;
        delete current;

    }
}
void deleteAtLast()
{
    Node* temp=head;
    //Node* current;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    delete temp->next;
    if(head!=NULL)
    temp->next=head;
    else
        return;

}
void deleteAtStart()
{
    Node* current=new Node();
    current=head;
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=current->next;
    head=temp->next;
    delete current;
}
void insertAtSpecified(int where,int data)
{
    Node* prev=head;
    Node* newNode=new Node();
    newNode->data=data;
    int size=1;
    while(prev->next!=head){
        size++;
        prev=prev->next;
    }
    if(where>size){
        cout << "Invalid position" << endl;
        return;
    }
    prev=head;
    if(where==1){
        while(prev->next!=head){
            prev=prev->next;
        }
        newNode->next=head;
        prev->next=newNode;
        head=newNode;
    }
    else{
        for(int i=1;i<where-1;i++){
            prev=prev->next;
        }
        newNode->next=prev->next;
        prev->next=newNode;
    }
}
void insertAtLast(int data)
{
    Node* temp=new Node();
    Node* newNode=new Node();
    newNode->data=data;
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
}
void print()
{
     cout << "Items in the list are: ";
    Node* temp=new Node();
    if(head==NULL)
        return;
    temp=head;
    while(temp->next!=head){
        cout << temp->data <<  " ";
        temp=temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}
void insertAtBegin(int data)
{
    Node* temp=new Node();
    temp->data=data;
    if(head==NULL){
        head=temp;
        temp->next=head;
        return;
    }
    else{
        Node* last=new Node();
        last=head;
        while(last->next!=head){
            last=last->next;
        }
        temp->next=head;
        last->next=temp;
        head=temp;

    }
}
