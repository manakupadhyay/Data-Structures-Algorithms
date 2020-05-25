        // implementation of heap(max) data structure in C++
#include<iostream>
using namespace std;

struct Heap{
    int count;
    int capacity;
    int *arr;
};
Heap* constructHeap(int capacity){
    Heap* newHeap = new Heap();
    newHeap->count = 0;
    newHeap->capacity = capacity;
    newHeap->arr = new int[capacity];
    cout << "Heap created!" << endl;
    return newHeap;
}
int getMax(Heap* h){
    if(h==NULL || h->count == 0)
        return -1;
    return h->arr[0];
}
int parent(Heap* h, int index){
    if(index <=0 || index > (h->count))
        return -1;
    return (index-1)/2;
}
int leftChild(Heap* h, int index){
    int left = 2*index+1;
    if(left >= h->count)
        return -1;
    return left;
}
int rightChild(Heap* h, int index){
    int right = 2*index+2;
    if(right >= h->count)
        return -1;
    return right;
}
void insert(Heap* h, int data){
    if(h->count == 0){
        h->count++;
        int i = h->count-1;
        h->arr[i]=data;
        return;
    }
    if(h->count >= h->capacity){
        cout << "Heap is full" << endl;
        return;
    }
    h->count++;
    int i = h->count-1;
    while(i > 0 && (data > h->arr[(i-1)/2])){
        h->arr[i] = h->arr[(i-1)/2];
        i = (i-1)/2;
        cout << "hey" << endl;
    }
    h->arr[i] = data;
}
void heapify(Heap* h,int index){
    // from top to bottom...(precolateDown)
    int left,right,max,temp;
    left = leftChild(h,index);
    right = rightChild(h,index);
    if(left!=-1 && (h->arr[index] < h->arr[left]))
        max = left;
    else
        max = index;
    if(right!=-1 && (h->arr[right] > h->arr[max]))
        max = right;

    if(max!=index){
        temp = h->arr[max];
        h->arr[max] = h->arr[index];
        h->arr[index] = temp;
        heapify(h,max);
    }
  
}
void print(Heap* h){
    if(h == NULL || h->count == 0){
        cout << "Heap is empty" << endl;
            return;
    }
    for(int i=0;i<(h->count);i++){
        cout << h->arr[i] << " ";
    }
    cout << endl;
}
int deleteElement(Heap* h){
    int data;
    if(h->count == 0)
        return -1;
    data = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    cout << "wor" << endl;
    heapify(h,0);
    return data;
}
void destroyHeap(Heap* h){
    if(h==NULL)
        return;
    delete h->arr;
    delete h;
    h = NULL;
}
int main(){
    cout << "Enter the capacity of heap: ";
    int cap;
    cin >> cap;
    Heap* heap = constructHeap(cap);
    int loop=1,data;
    do{
        cout << "1. Insert" << endl;
        cout << "2. Get Maximum element" << endl;
        cout << "3. Left Child" << endl;
        cout << "4. Right CHild" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Destroy Heap" << endl;
        cout << "7. Print" << endl;
        cout << "8. Parent" << endl;
        cin >> loop;
        switch(loop){
            case 1: cout << "Enter data: ";
                    cin >> data;
                    insert(heap,data);
                    break;
            case 2: cout << getMax(heap) << endl;
                    break;
            case 3: cout << "Enter index: ";
                    cin >> data;
                    data = leftChild(heap,data);
                    cout << "Left child is: " << heap->arr[data] << endl;
                    break;
            case 4: cout << "Enter index: ";
                    cin >> data;
                    data = rightChild(heap,data);
                    cout << "Right child is: " << heap->arr[data] << endl;
                    break;
            case 5: data = deleteElement(heap);
                    cout << data << endl;
                    break;
            case 6: destroyHeap(heap);
                    cout << "Heap destroyed" << endl;
                    return 0;
            case 7: print(heap);
                    break;
            case 8: cout << "Enter index: ";
                    cin >> data;
                    data = parent(heap,data);
                    cout << "Parent is: " << heap->arr[data] << endl;
            default: cout << "Invalid option" << endl;
        }
        cout << "Enter 1 for again 0 for exit: ";
        cin >> loop;
    }while(loop);
    return 0;
}