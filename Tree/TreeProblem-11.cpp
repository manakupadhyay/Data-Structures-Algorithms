
                // TREE PROBLEM -11
                // CHECK IF AN ARRAY REPRESENTS INORDER TRAVERSAL OF THE BINRAY SEARCH TREE OR NOT


#include <iostream>
using namespace std;
bool isInorder(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
            return false;
    }
    return true;
}
int main()
{
    int arr[] = { 19, 23, 30, 25, 11 };
    int n = sizeof(arr)/sizeof(arr[0]);

    if (isInorder(arr, n))
        cout << "Yesn";
    else
        cout << "Non";

  return 0;
}
