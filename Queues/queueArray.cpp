#include <iostream>
#define max_size 10
using namespace std;
class Queue
{
    int arr[max_size];
    int front,end;
public:
    Queue()
    {
        front=0;
        end=-1;
    }
    void enQueue(int);          // push();
    int deQueue();              // pop();
    int top();
    bool isEmpty();
    bool isFull();
    void print();
};
void Queue :: enQueue(int ele)
{
    if(isFull()){
         cout << "Queue is full" << endl;
         return;
    }

    else
    arr[++end]=ele;
}
int Queue :: deQueue()
{
    if(isEmpty())
    {
         cout << "Queue is empty"<< endl;

    }

    else
    return arr[front++];

}
int Queue :: top()
{
    return arr[front];
}
bool Queue :: isEmpty()
{
    if(end<0)
    {

        return true;
    }
    else{

        return false;
    }
}
bool Queue :: isFull()
{
    if(end==max_size-1){

        return true;
    }
    else{

        return false;
    }
}
void Queue :: print()
{
    for(int i=front;i<=end;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
   Queue qo;
   qo.enQueue(2); qo.print();
   qo.enQueue(4); qo.print(); qo.enQueue(15);qo.print();
   qo.enQueue(10);qo.print();
   qo.enQueue(11); qo.print();
   cout << qo.deQueue() << endl;
   qo.print();
   cout << qo.top() << endl;;
  qo.print();
  qo.deQueue();
  qo.print();
   qo.isEmpty();
   qo.enQueue(30);
   qo.print();

    return 0;
}
