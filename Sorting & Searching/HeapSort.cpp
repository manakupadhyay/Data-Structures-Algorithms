#include <iostream>
using namespace std;
// maxHeap
void heapify(int arr[],int index, int size)
{
    // from top to bottom...(precolateDown)
    int left,right,min,temp;
    left = 2*index+1;
    right = 2*index+2;
    if(left< size && (arr[index] < arr[left]))
        min = left;
    else
        min = index;
    if(right<size && (arr[right] > arr[min]))
        min = right;

    if(min!=index){
        temp = arr[min];
        arr[min] = arr[index];
        arr[index] = temp;
        heapify(arr,min,size);
    }
}
int main()
{
    int arr[]={7,4,9,0,1,3,11,2};
    int size= sizeof(arr)/sizeof(arr[0]);
    cout << "Array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
   
    // build heap from the input array in the bottom-up order
    for(int i = size/2-1; i>=0; i--)
        heapify(arr,i,size);
    
    // extract elements one by one
    for(int i = size-1;i>0;i--)
    {
        // swap the first element with the last
        swap(arr[0],arr[i]);

        // heapify the reduced array
        heapify(arr,0,i);
    }
    
    cout << "Array after sorting: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;


    return 0;
}
