#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool valid(int a,int b,int r,int c)
{
    if(a>=0 && a>r && b>=0 && b>c)
    return true;
    return false;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
	    int size;
	    cin >> size;
	    int arr[size][size];
	    int srcx,srcy,desx,desy;
	    for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
                cin >> arr[i][j];
        }
	    for(int i=0;i<size;i++)
	    {
	        for(int j=0;j<size;j++)
	        {
	            if(arr[i][j]==1)
	            {
	                srcx=i;srcy=j;
	            }
	            else if(arr[i][j]==2)
	            {
	                desx=i;desy=j;
	            }
	        }
	    }
	    queue<pair<int,int> > q;
	    q.push(make_pair(srcx,srcy));
	    int flag=0;
	    while(!q.empty())
	    {
	        pair<int,int> temp=q.front();
	        int a=temp.first,b=temp.second;
	        q.pop();
	        if(valid(a-1,b,size,size) && (arr[a-1][b]==2||arr[a-1][b]==3))
	        {
	            if(valid(a-1,b,size,size) && arr[a-1][b]==2)
	            {
	                flag=1; break;
	            }
	            q.push(make_pair(a-1,b));
	        }
	        if(valid(a+1,b,size,size) && (arr[a+1][b]==2||arr[a+1][b]==3))
	        {
	            if(valid(a+1,b,size,size) &&arr[a+1][b]==2)
	            {
	                flag=1; break;
	            }
	            q.push(make_pair(a+1,b));
	        }
	        if(valid(a,b-1,size,size) && (arr[a][b-1]==2||arr[a][b-1]==3))
	        {
	            if(valid(a,b-1,size,size) &&arr[a][b-1]==2)
	            {
	                flag=1; break;
	            }
	            q.push(make_pair(a,b-1));
	        }
	        if(valid(a,b+1,size,size) && (arr[a][b+1]==2||arr[a][b+1]==3))
	        {
	            if(valid(a,b+1,size,size) &&arr[a][b+1]==2)
	            {
	                flag=1; break;
	            }
	            q.push(make_pair(a,b+1));
	        }
	        arr[a][b]=0;
	    }
	    if(flag==1)
	    cout << 1 << endl;
	    else
	    cout << 0 << endl;
	}
	return 0;
}
