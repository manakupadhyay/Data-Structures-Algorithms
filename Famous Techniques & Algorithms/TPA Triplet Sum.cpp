    /*
        Given an array of integers. Check whether it contains a triplet that sums up to zero. 
        
        Approach: Two Pointer Algo.  For every element check that there is a pair whose sum is equal 
        to the negative value of that element.
        
        Prerequistive:  Input array must be sorted.
        T.C: O(n*n)
        S.C: O(1)

    */
#include <iostream>
using namespace std;
bool twoPointer(int arr[], int size, int sum, int i)
{
    int j = size-1;
    while(i<=j)
    {
        int tempSum = arr[i]+arr[j];
        if(tempSum == sum)
            return true;
        if(tempSum > sum)
            j--;
        else
            i++;
    }
    return false;
}
bool tripletSum(int arr[], int size)
{
    for(int i = 0;i<size-2;i++)
    {
        if(twoPointer(arr,size,-arr[i],i+1))
            return true;
    }
    return false;
}
int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the sorted-array: ";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    cout << "Entered array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;

    tripletSum(arr,size)?cout << "Yes" : cout << "No" << endl;
    return 0;
}