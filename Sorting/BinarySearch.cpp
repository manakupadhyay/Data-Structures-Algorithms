
        /*
        ---------------------------BINARY SEARCH--------------------------------
        Binary search begins by comparing the middle element of the list with the target element. If the target
        value matches the middle element, its position in the list is returned. If it does not match, the list
        is divided into two halves. The first half consists of the first element to middle element whereas the
        second half consists of the element next to the middle element to the last element.
        TIME COMPLEXITY(worst and average case): O(LOG N)
        Best case time complexity : O(1)
        SPACE COMPLEXITY : O(1) (iterative)

            */



#include <iostream>
using namespace std;
bool binarysearch(int arr[],int size,int ele);
int main()
{
    int arr[]{2,6,10,17,22,56,70,100};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array is; ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Enter element: ";
    int ele;
    cin >> ele;
    bool b=binarysearch(arr,size,ele);
    b?cout << "Found" << endl : cout << "Not Found" << endl;
    return 0;
}
bool binarysearch(int arr[],int size,int ele)
{

    int low=0,high=size-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==ele)
            return true;
        else if(arr[mid] < ele)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}
