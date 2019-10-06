#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    for(int i=0;i<size;i++)
            cout << arr[i] << " ";
    cout << endl;
    return 0;
}
