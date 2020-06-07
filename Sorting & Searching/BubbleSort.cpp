
/*
    BUBBLE SORT: IT IS A SORTING TECHNIQUE IN WHICH WE COMPARE TWO ADJECENT ELEMENTS AND IF THE
    NOT SORTED THEN WE SWAP THE POSITION OF THOSE TWO ELEMENTS. SO AFTER EACH COMPLETE ITERATION
    THE GREATEST(CONSIDERINGN THAT WE WANT TO SORT THE ARRAY IN ASCENDING ORDER) ELEMENT BUBBLES
    TO THE END OF THE UNSORTED ARRAY EVERTIME.
    WORST CASE TIME COMPLEXITY: O(n^2)
    AVERAGE CASE TIME COMPLEXITY: O(n^2)
    BEST CASE TIME COMPLEXITY: O(n)--when the list is already sorted...
    SPACE COMPLEXITY: O(1)
    ADVANTAGE: very simple...

*/


#include <iostream>
using namespace std;
int main()
{
    int size=7;
    int arr[]={26,84,36,14,16,86,11};
    int flag=0;
    bool f=false;
    for(int i=0;i<size;i++)
    {
        f=false;
        for(int j=0;j<size-1-i;j++)
        {
            flag++;
            if(arr[j]>arr[j+1])
            {
                f=true;
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        if(!f)
            break;
    }
    cout << "Comparisons are: " << flag << endl;
    cout << "Sorted array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
