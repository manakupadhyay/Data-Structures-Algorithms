#include<iostream>
using namespace std;
int main()
{
    int size=7;
    int arr[]={26,84,36,14,16,86,11};
    int minIndex=0;
    int outerloop=0,innerloop=0,flag=0;
    for(int i=0;i<size-1;i++)
    {
        outerloop++;
        minIndex=i;
        for(int j=i+1;j<size;j++)
        {
            innerloop++;
            if(arr[minIndex]>arr[j])
            {
                flag++;
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
   cout << "Outer loop: " << outerloop;
   cout << "\n" << "Inner loop: " << innerloop;
   cout << "\n" << "Total comparisons: " << flag;
    cout << "\nSorted array is: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
