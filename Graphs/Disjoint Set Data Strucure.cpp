
            // DISJOINT SET DATA STRUCTURE...

#include <iostream>
using namespace std;
int root(int arr[],int s,int a)
{
    while(arr[a]!=a)
    {
        a=arr[a];
    }
    return a;
}
void Union(int arr[],int s,int a,int b)
{
    int rootA=root(arr,s,a);
    int rootB=root(arr,s,b);
    arr[a]=b;
}
void display(int arr[],int s)
{
    for(int i=0;i<s;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool find(int arr[],int s,int a,int b)
{
    if(root(arr,s,a)==root(arr,s,b))
        return true;
    else
        return false;
}
int main()
{
    int arr[]={0,1,2,3,4,5,6,7,8};
    int opt;
    int size=sizeof(arr)/sizeof(arr[0]);
    do{
        cout << "1. Union" << endl;
        cout << "2. Find" << endl;
        cout << "3. Root" << endl;
        cin >> opt;
        switch(opt)
        {
            case 1: {
                    int a,b;
                    cin  >> a >> b;
                    Union(arr,size,a,b);
                    display(arr,size);
                    break;
            }
            case 2: {
                    int a,b;
                    cin >> a >> b;
                    cout << find(arr,size,a,b) << endl;

                    break;
            }
            case 3: {
                    int a;
                    cin >> a;
                    int ans=root(arr,size,a);
                    cout << ans << endl;
                    break;
            }

        }
        cout << "1 or 0";
        cin >> opt;
    }while(opt!=0);
    return 0;

}
