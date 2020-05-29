        /*
        Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time.
        TIME COMPLEXITY: O(N^2) - Average and Worst Case
        SPACE COMPLEXITY: O(1)
        In Place? Yes
        Stable: Yes
        Best Case Complexity: O(N) - it occues when the list is already sorted.
        */

#include <iostream>
using namespace std;
int main()
{
    int size=7;
    int arr[]={8,0,-2,16,7,2,-7};
    int flag=0;
    for(int i=1;i<size;i++)
    {
        int hole=i;
        int value=arr[i];
        while(hole>0 && arr[hole-1]>value)
        {
            flag++;
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
    cout << "Comparisons are: " << flag << endl;
    cout << "Sorted array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    return 0;
}
