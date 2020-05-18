#include <iostream>
#include <stack>
using namespace std;
stack <int> stk;
int calculate(int arr1[],int arr2[],int size1,int size2)
{
    int carry=0,ans=0,k=0;
    int big=size1<size2?size1:size2;
    for(int i=(size1-1),j=size2-1;k<big;k++,i--,j--)
    {
        ans+=arr1[i]+arr2[j];
        if(ans>=10)
        {
            carry=ans/10;
            ans=ans%10;
            stk.push(ans);
            ans=0;
            ans=ans+carry;

        }
        else
        {
            stk.push(ans);
            ans=0;
        }
    }
    if(size1>size2)
    {
        for(;k<size1;k++)
        {
            int value=arr1[k];
            stk.push(value);
        }
    }
    else
    {
        for(;k<size2;k++)
        {
            int value=arr2[k];
            stk.push(value);
        }
    }
    for(int i=0;i<k;i++)
    {
        cout << stk.top() << " ";
        stk.pop();
    }

}
void getNumbers(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i]=i+1;
    }

}
void showNumbers(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
int main()
{
    cout << "Enter the size of first array: ";
    int size1,size2;
    cin >> size1;
    int arr1[size1];
    getNumbers(arr1,size1);
    cout << "Enter the size of second array: ";
    cin >> size2;
    int arr2[size2];
    getNumbers(arr2,size2);
    cout << "First number is: ";
    showNumbers(arr1,size1);
    cout << "First number is: ";
    showNumbers(arr2,size2);

   calculate(arr1,arr2,size1,size2);

    return 0;
}
