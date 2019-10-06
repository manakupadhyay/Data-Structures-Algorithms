  #include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head;
void insertAtBegin(int);
void insertAtEnd(int data);
void insertAtSpecified(int,int);
void print();
void printforwardrecursion(Node*);
void printbackwardrecursion(Node*);
void reversePrint();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtSpecified(int);
void findElement(int );
void reverseList();
void reverseRecursion(Node*);
void reverse()                      // MADE THIS AGAIN JUST FOR PRACTICE...
{
    Node* current=head;
    Node* next;
    while(current->next!=NULL)
    {
        next=current->next;
        current->next=current->prev;
        current->prev=next;
        current=current->prev;
    }
    current->next=current->prev;
    current->prev=NULL;
    head=current;
}
int main()
{
    head=NULL;
    cout << "Program begins" << endl;
    cout << "Enter the number of nodes in the list: ";
    int size,value;
    cin >> size;
    for(int i=0;i<size;i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(value);
    }
    print();
    cout << "Printing the list in same order: ";
    printforwardrecursion(head);
    cout << endl;
    cout << "Printing the list in reverse order: ";
    printbackwardrecursion(head);
    cout << "Reversing the list using recursion: ";
    reverseRecursion(head);
    print();

    cout << "Enter the element you want to insert at end: ";
    int data;
    cin >> data;
    insertAtEnd(data);
    print();
    /*
    cout << "Printing the list in reverse order: ";
    reversePrint();
    cout << "Reversing the list: ";
    reverse();
    print();
    cout << "Enter the position where you want to delete the element: ";
    int where;
    cin >> where;
    deleteAtSpecified(where);
    print();*/
    return 0;

}
void reverseRecursion(Node* temp)
{
    if(temp->next==NULL)
    {
        head=temp;
        return;
    }
    reverseRecursion(temp->next);
    Node* p=temp->next;
    p->prev=p->next;
    p->next=temp;
    temp->next=temp->prev;
    //temp->prev=p;
}
void reverseList()
{
    Node *current,*forwardd;
    current=head;
    while(current->next!=NULL){
        forwardd=current->next;
        current->next=current->prev;
        current->prev=forwardd;
        current=current->prev;
    }
    current->next= current->prev;
   current->prev=NULL;
    head=current;
}
void insertAtSpecified(int position,int data)
{
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(position==1){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    Node* last=head;
    for(int i=1;i<position-1;i++){
        last=last->next;
    }
    Node* forwardd=last->next;
    last->next=newNode;
    newNode->prev=last;
    newNode->next=forwardd;
    forwardd->prev=newNode;
}
void deleteAtEnd()
{
    Node* current=head;
    if(head==NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node* last;
    while(current->next!=NULL){
        last=current;
        current=current->next;
    }
    last->next=NULL;
    delete current;

}
void deleteAtBegin()
{
    Node* current=head;
    if(head==NULL){
        cout << "Empty list" << endl;
        return;
    }
    Node* nextt = current;
    head=current->next;
    nextt->prev=NULL;
    delete current;

}
void findElement(int ele)
{
    Node* temp=head;
    int pos=0;
    bool found=false;
    while(temp!=NULL){
        if(temp->data==ele){
            cout << "element found at position " << pos+1 << endl;
            found=true;
            return;
        }else{
            temp=temp->next;
            pos++;
        }
    }
    if(!found)
        cout << "element not found" << endl;
    return;
}
void deleteAtSpecified(int where)
{
    Node* prev=head;
    if(where==1){           // for first node...
        head=prev->next;
        delete prev;
        return;
    }
    for(int i=1;i<(where-1);i++){
        prev=prev->next;
    }
    if(prev->next->next==NULL){         // for last node...
        Node* current = prev->next;
        prev->next=NULL;
        delete current;
    }else{                          // for all the nodes instead of first and last...
        Node* current = prev->next;
        prev->next=current->next;
        Node* nextt=current->next;
        nextt->prev=prev;
        delete current;
    }

}
void reversePrint()
{
    Node* temp=new Node();
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp->prev!=NULL){
        cout << temp->data << " ";
        temp=temp->prev;
    }
    cout << temp->data;
    cout << endl;

}
void insertAtEnd(int data)
{
    Node* newNode=new Node();
    newNode->data=data;
    Node* temp=head;
    if(head==NULL)
    {
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=NULL;

}
void printbackwardrecursion(Node* temp)
{
    if(temp==NULL){
        return;
    }
    printbackwardrecursion(temp->next);
    cout << temp->data <<  " ";


}
void printforwardrecursion(Node* temp)
{
    if(temp==NULL)
        return;
    cout << temp->data << " ";
    printforwardrecursion(temp->next);

}
void print()
{
    Node* temp = head;
    while(temp->next!=NULL){
        cout << temp->data << " ";

        temp=temp->next;
    }
    cout << temp->data;
    cout << endl;
}
void insertAtBegin(int data)
{
    Node* temp=new Node();
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    head->prev=temp->next;
    temp->next=head;
    head=temp;


}
