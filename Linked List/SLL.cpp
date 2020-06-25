#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* insert(Node* head,int value)
{
    Node* temp = new Node();
    temp->data=value;
    temp->next=head;
    if(head!=NULL)
        temp->next=head;
    head=temp;
    return head;
}
void print(Node* head)
{

    Node* temp= new Node();
    temp=head;
    cout << "list is: ";
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main()
{
        Node* head=new Node();
        head=NULL;
        int num,value;
        head= insert(head,10);
        head=insert(head,20);
        head=insert(head,30);
        print(head);
}
