
            // application of stack: reversing a linked list using stack...

#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insertAtBegin(int);
void print();
void Reverse();
Node* head;
int main()
{
    head=NULL;
    cout << "Enter the number of nodes in the list: ";
    int size,value;
    cin >> size;
    cout << "Enter the values: " << endl;
    for(int i=0;i<size;i++){
        cin >> value;
        insertAtBegin(value);
    }
    cout << "List is: ";
    print();
    Reverse();
    cout << "List after reversing is: ";
    print();
    return 0;
}
void Reverse()
{
    Node* temp= new Node();
    temp=head;
    stack <Node*> s;
    while(temp->next!=NULL){
        s.push(temp);
        temp=temp->next;
    }
    s.push(temp);
    head=temp;
    s.pop();
    while(!s.empty()){
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}
void print()
{
    Node *temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
void insertAtBegin(int data)
{
    Node* temp=new Node();
    temp->data=data;
    temp->next=head;
    head=temp;
}
