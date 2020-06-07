    /*
        TWO POINTER TECHNIQUE: One pointer starts from the beginning while the other pointer starts from 
        the end. They move toward each other until they both meet.

        Given a sorted array A (sorted in ascending order), having N integers, find if there exists any 
        pair of elements (A[i], A[j]) such that their sum is equal to X.

        TIME COMPLEXITY: O(N)
        SPACE COMPLEXITY : O(1)

    */

#include <iostream>
using namespace std;
int main()
{
    int size, k;

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

    // k is sum we need to find
    cout << "Enter the sum: ";
    cin >> k;

    // CODE LOGIC

    
    for(int i=0,j=size-1;i<=j;) // i points to starting position, j to last position
    {
        int tempSum = arr[i] + arr[j];
        if(tempSum == k)        // if current sum is equal to given sum, break;
        {
            cout << arr[i] << " " << arr[j] << endl;
            break;
        }
        if(tempSum > k) // if current sum is greater than k, decrement j
            j--;
        else
            i++;    // else increment i
    }
    return 0;
}