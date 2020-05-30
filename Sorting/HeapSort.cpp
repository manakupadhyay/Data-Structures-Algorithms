#include <iostream>
using namespace std;
void heapify(int arr[],int index){
    // from top to bottom...(precolateDown)
    int left,right,min,temp;
    left = 2*index+1;
    right = 2*index+2;
    if(left!=-1 && (arr[index] > arr[left]))
        min = left;
    else
        min = index;
    if(right!=-1 && (arr[right] < arr[min]))
        min = right;

    if(min!=index){
        temp = arr[min];
        arr[min] = arr[index];
        arr[index] = temp;
        heapify(arr,min);
    }
}
int main()
{
    int arr[]={65,78,11,23,1,66,73,120};
    int size= sizeof(arr)/sizeof(arr[0]);
    cout << "Array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
   
        cout << "Array after sorting: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}