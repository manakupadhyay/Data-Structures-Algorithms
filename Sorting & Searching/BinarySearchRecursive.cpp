
        /*
            ---------------RECURSIVE BINARY SEARCH---------------------

            TIME COMPLEXITY : O(LOG N)
            SPACE COMPLEXITY : O(N)(memory stack)

        */


#include <iostream>
using namespace std;
bool binarysearch(int arr[],int size,int low,int high,int ele);
int main()
{
    int arr[]{-9,-3,0,12,15,18,22,24};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array is; ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Enter element: ";
    int ele;
    cin >> ele;
    bool b=binarysearch(arr,size,0,size-1,ele);
    b?cout << "Found" << endl : cout << "Not Found" << endl;
    return 0;
}
bool binarysearch(int arr[],int size,int l,int h,int ele)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==ele)
            return true;
        else if(arr[mid] < ele)
        {
            l=mid+1;
            binarysearch(arr,size,l,h,ele);
        }
        else
        {
            h=mid-1;
            binarysearch(arr,size,l,h,ele);
        }
    }
    else
        return false;
}
