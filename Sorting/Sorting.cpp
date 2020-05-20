#include <iostream>
#include "Sorting.h"
using namespace std;
int main()
{
    Sort so;
    cout << "Enter the size of array: ";
    int size,again;
    cin >> size;
    int arr[size];
    cout << "Enter the array: ";
    for(int i=0;i<size;i++)
        cin >> arr[i];
    cout << "Choose an option: " << endl;
    do
    {
        cout << "1. Insertion Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 1: cout << "-----INSERTION SORT-----" << endl;
                    cout << "Time Complexity: O(n^2)" << endl;
                    cout << "Space complexity: O(1)" << endl;
                    so.insertionSort(arr,size);
                    break;
        }
    }while(again!=0);
    return 0;
}
