        /*
            SLIDING WINDOW TECHNIQUE: It is an algo which uses the property that the sum of the current
            window(Sc) can be found out using the sum of the last window(Sl) knowing the items that 
            just slided out and the item that moved in as a0 and ai respectively.
                    Then, Sc = Sl - a0 + ai   
            TIME COMPLEXITY: O(N)
            SPACE COMPLEIXTY: O(1)
        */
       
#include <iostream>
using namespace std;
int main()
{
    int size, windowSum = 0, windowSize;

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
        windowSum += arr[i];

    cout << windowSum << " ";
    int j;
    for(int i=1;i<=size-windowSize;i++) // i is the start point of window
    {
        j = i + windowSize -1;      // j is the end point of window
        windowSum = windowSum - arr[i-1] + arr[j];
        cout << windowSum << " ";
    }
    cout << endl;

    return 0;
}