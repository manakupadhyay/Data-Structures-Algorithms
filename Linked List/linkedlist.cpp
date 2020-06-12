
                // singly linked list...

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head;
// Node* partition(Node* head, int x){
//      if(head==NULL || head->next==NULL)
//             return head;
//         Node* newHead = new Node();
//         Node* h = newHead;
//         Node* list2 = new Node();
//         Node* hlist2 = list2;
//         Node* temp = head;
//         while(temp){
//             if(temp->data < x){
//                 newHead->next = temp;
//                 newHead=newHead->next;
//             }else{
//                 list2->next=temp;
//                 list2=list2->next;
//             }
//             temp=temp->next;
//         }
//         list2->next=NULL;
//         newHead->next=hlist2->next;
//         return h->next;
// }
void Insert(int data);
void Print();
void InsertAtEnd(int );
void insertBetween(int data,int pos);
void deleteElement(int);
void Reverse();
void PrintBackwardRecursion(Node*);
void PrintForwardRecursion(Node*);
int searchElement(int data);
void deleteAtEnd();
void reverseRecursion(Node* );
void split(Node* root)
{
    Node* temp=root;
    int size=0;
    while(temp->next!=NULL)
    {
        size++;
        temp=temp->next;
    }
    size++;
    cout <<"Size is: " << size << endl;
    Node* temp2;
    temp=head;
    Node* head1=temp;
    if(size%2==0)
    {
        int i=1;
        while(i<=(size/2))
        {
            temp=temp->next;
            i++;
        }
        temp2=temp->next;
        temp->next=NULL;
    }
    else
    {
        int i=1;
        while(i<=size/2)
        {
            temp=temp->next;
            i++;
        }
        temp=temp->next;
        temp2=temp->next;
        temp->next=NULL;
    }
    cout <<"First list is: ";
    Node* t1=head1;
    while(t1->next!=NULL)
    {
        cout << t1->data <<" ";
        t1=t1->next;
    }
    cout << t1->data << endl;
    Node* t2=temp2;
    cout << "Second list is: ";
    while(t2->next!=NULL)
    {
        cout << t2->data << " ";
        t2=t2->next;
    }
    cout << t2->data << endl;

}
void reverse()
{
    Node* temp=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(temp->next!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    temp->next=prev;
    head=temp;
}
Node *removeDuplicates(Node *root)
{
    Node* temp=root;
    Node* prev=root;
    for(temp;temp->next!=NULL;)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;
            temp=prev;
            continue;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    return root;
}
void reverseRecursion(Node* temp)
{
    if(temp->next==NULL)
    {
        head=temp;
        return;
    }
    reverseRecursion(temp->next);
    Node* prev=temp->next;
    prev->next=temp;
    temp->next=NULL;
}
int main()
{
    head=NULL;
    int num,value;
    cout << "Enter the number of elements you want to insert? ";
    cin >> num;
    for(int i=0;i<num;i++){
        cout << "Enter value: ";
        cin >> value;
        Insert(value);
    }
    Print();
    // head = partition(head,3);
    Print();
    //head = rotate(head,2);
    //Print();
    /*cout << "Printing the list in reverse order: ";
        PrintBackwardRecursion(head);
        cout << "Reversing the list: ";
        reverseRecursion(head);
        Print();
        cout << endl;
    /*cout << "After inserting elements list is: ";
    Print();
     cout << "Enter the position where you want to insert the element: ";
    int pos;
    cin >> pos;
    cout << "Enter element: ";
    cin >> value;
    insertBetween(value,pos);
    cout << "New List is: ";
    Print();
    cout << "Deleting last element: " << endl;
    deleteAtEnd();
    Print();
    cout << "Reversing the list: " << endl;
    reverse();
    Print();
    */
    //split(head);
    //head=removeDuplicates(head);
    //Print();
    return 0;
}
void deleteAtEnd()
{
    Node* temp=head;
    Node* temp1;
    while(temp->next!=NULL){
        temp1=temp;
        temp=temp->next;
    }
     temp1->next=NULL;
    delete temp1;
}
void InsertAtEnd(int data)
{
    Node* temp= head;
    Node* newNode = new Node();
    newNode->data=data;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->next==NULL){
            temp->next=newNode;
            newNode->next=NULL;
            break;
        }
    }
}
int searchElement(int data)
{
    Node* temp=head;
    bool found=false;
    int pos=0;
    if(head==NULL)
        return 0;
     while(temp!=NULL){
        if(temp->data==data){
            found=true;
            cout << "Element found at postion " << pos +1 << endl;
            return pos;
        }
        else{
            temp=temp->next;
            pos++;
        }
     }
     if(!found){
        cout << "Element not fount in the list" << endl;
        
     }
     return 0;
}
void PrintForwardRecursion(Node* temp)
{
    if(temp==NULL)
        return;
    cout << temp->data << " ";
    PrintForwardRecursion(temp->next);
}
void PrintBackwardRecursion(Node* temp)
{
    if(temp==NULL)
        return;
    PrintBackwardRecursion(temp->next);
    cout << temp->data << " ";
}
void Reverse()
{
    Node* next;
    Node* prev;
    Node* current;
    prev=NULL;
    current=head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void deleteElement(int pos)
{
    Node* prevNode = new Node();
    prevNode=head;
    if(pos==1){             // special case to delete the first element...
        head=prevNode->next;
        delete prevNode;
        return;
    }
    for(int i=1;i<pos-1;i++){
        prevNode=prevNode->next;
    }
    Node* currentNode = prevNode->next;
    prevNode->next=currentNode->next;
    delete currentNode;

}
void insertBetween(int data,int pos)
{
    Node* prevNode=head;
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    if(pos==1){             // special case to insert a node at the beginning
        newNode->next=head;
        head=newNode;
        return;
    }
    for(int i=1;i<pos-1;i++){
        prevNode=prevNode->next;
    }
    newNode->next=prevNode->next;
    prevNode->next=newNode;
}
void Print()
{
    Node* temp=head;
    cout << "list is: ";
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
void Insert(int d)
{
    Node* temp=new Node();
    temp->data=d;
    temp->next=head;
    if(head!=NULL){
        temp->next=head;
    }
    head=temp;
}

