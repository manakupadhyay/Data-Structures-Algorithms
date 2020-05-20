
        /*
                                    --------------LINEAR SEARCH-------------------
                A linear search or sequential search is a method for finding an element within a list. It sequentially
                checks each element of the list until a match is found or the whole list has been searched
                TIME COMPLEXITY(worst and average case):O(N)
                Best case time complexity: O(1)
                SPACE COMPLEXITY : O(1)[iterative]
        */

#include <iostream>
using namespace std;
bool linearsearch(int arr[],int size,int ele);
int main()
{

    int arr[]{2,6,1,22,12,-5,4,-5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array is; ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Enter element: ";
    int ele;
    cin >> ele;
    bool b=linearsearch(arr,size,ele);
    b?cout << "Found" << endl : cout << "Not Found" << endl;
    return 0;
}
bool linearsearch(int arr[],int size, int ele)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==ele)
            return true;
    }
    return false;
}
