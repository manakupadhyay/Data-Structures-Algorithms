    /*
        QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions 
        the given array around the picked pivot. The key process is partition. The array is partitioned 
        as all the elements to the left of the pivot and all the elements to the right of the pivot are greater 
        that it(considering sorting in ascending order).
        TIME COMPLEXITY: O(N*LOG N) - best and average case
        Worst Case: O(N*N) - occurs when the list is already sorted or almost sorted.
        SPACE COMPLEXITY: O(1)
        IN-PLACE? Yes.
        Stable Sort? No.
    */

#include <iostream>
using namespace std;
int partition(int arr[],int low, int high)
{
    int pivot,pIndex;
    pivot = arr[high];      // taking last element as the pivot.
    pIndex = low;
    for(int i=low; i < high; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[high]);
    return pIndex;
}
void quicksort(int arr[],int start,int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quicksort(arr, start, pIndex-1);
        quicksort(arr, pIndex+1, end);
    }
}
void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size=7;
    int arr[]={2,7,-1,4,14,0,-3};
    print(arr, size);
    quicksort(arr,0,size-1);
    print(arr,size);
    return 0;
}
