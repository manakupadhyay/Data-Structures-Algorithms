
        /*
            --------------------MERGE SORT--------------------------
            Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists
            until each sublist consists of a single element and merging those sublists in a manner that results into a
            sorted list.
            Time Complexity [ Big-O ]: O(n*log n) - best, average and worst case.
            Space Complexity: O(n)

            Stable in nature(sorting algorithm is stable if whenever there are two records R and S with the same key and
            with R appearing before S in the original list, R will appear before S in the sorted list.)

            Sorting in Place(means sorting without extra space requirement) : No
        */


#include <iostream>
using namespace std;
void merge(int arr[],int left[],int right[],int lsize,int rsize);
void mergesort(int arr[],int size);
int main()
{
    int arr[]={65,78,11,23,1,66,73,120};
    int size= sizeof(arr)/sizeof(arr[0]);
    cout << "Array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    mergesort(arr,size);
    cout << "Array after sorting: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
void merge(int arr[],int left[],int right[],int lsize,int rsize)
{
    int i,j,k;
    i=j=k=0;
    while(i<lsize && j<rsize)
    {
        if(left[i]>right[j])
        {
            arr[k]=right[j];
            j++;
        }
        else
        {
            arr[k]=left[i];
            i++;
        }
        k++;
    }
    while(i<lsize)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<rsize)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int size)
{
    if(size<2)
        return;
    int mid=size/2;
    int left[mid];
    int right[size-mid];
    int i=0;
    for(i=0;i<mid;i++)
        left[i]=arr[i];
    for(i=mid;i<size;i++)
        right[i-mid]=arr[i];
    mergesort(left,mid);
    mergesort(right,size-mid);
    merge(arr,left,right,mid,size-mid);
}
