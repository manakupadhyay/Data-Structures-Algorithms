        /*
            Given an array of integers of size ‘n’.Our aim is to calculate the maximum sum of ‘k’ 
            consecutive elements in the array

            Approach: Sliding Window Technique
            T.C: O(n)
            S.C: O(1)

        */

#include <iostream>
using namespace std;
int main()
{
    int size, maxSum = 0, windowSize;

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

    // window-size
    cout << "Enter the size of window: ";
    cin >> windowSize; 

    // find the sum of the first window
    for(int i=0;i<windowSize;i++)
        maxSum += arr[i];

    int j, windowSum = maxSum;
    for(int i=1;i<=size-windowSize;i++) // i is the start point of window
    {
        j = i + windowSize -1;      // j is the end point of window
        windowSum = windowSum - arr[i-1] + arr[j];
        maxSum = max(maxSum, windowSum);
    }
    cout << "Maximum sum is: " << maxSum << endl;
    cout << endl;

    return 0;
}