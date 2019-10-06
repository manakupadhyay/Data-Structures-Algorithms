#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool isvalid(int i,int j,int r,int c)
{
    if(i>=0 && i<r && j>=0 && j<c )
    return true;
    return false;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
	    int row,column;
	    cin >> row >> column;
	    int arr[row][column]={{0}};
	    int srcx,srcy,desx,desy;
	    cin >> srcx >> srcy >> desx >> desy;
	    srcx--;srcy--;desx--;desy--;
	    queue<pair<int,int> > q;
	    q.push(make_pair(srcx,srcy));
	    map<pair<int,int> ,int> mp;
	    int ans=0;
	    bool found=false;
	    mp.insert(make_pair(make_pair(srcx,srcy),0));
	    while(!q.empty())
	    {
	        pair<int,int> temp=q.front();
	        int a=temp.first,b=temp.second;
	        q.pop();
	        if(a==desx&&b==desy)
	        {
	            found=true;
	            ans=mp[temp];
	            break;
	        }
	        if(isvalid(a-2,b-1,row,column) &&  arr[a-2][b-1]!=1 )
	        {
	            mp[make_pair(a-2,b-1)]=mp[temp]+1;
	            q.push(make_pair(a-2,b-1));
	            arr[a-2][b-1]=1;
	        }
	        if(isvalid(a-2,b+1,row,column) &&  arr[a-2][b+1]!=1)
	        {
	            mp[make_pair(a-2,b+1)]=mp[temp]+1;
	            q.push(make_pair(a-2,b+1));
	            arr[a-2][b+1]=1;
	        }
	        if(isvalid(a+2,b-1,row,column) && arr[a+2][b-1]!=1)
	        {
	            mp[make_pair(a+2,b-1)]=mp[temp]+1;
	            q.push(make_pair(a+2,b-1));
	            arr[a+2][b-1]=1;
	        }
	        if(isvalid(a+2,b+1,row,column)&& arr[a+2][b+1]!=1)
	        {
	            mp[make_pair(a+2,b+1)]=mp[temp]+1;
	            q.push(make_pair(a+2,b+1));
	            arr[a+2][b+1]=1;
	        }
	        if(isvalid(a-1,b-2,row,column) && arr[a-1][b-2]!=1)
	        {
	            mp[make_pair(a-1,b-2)]=mp[temp]+1;
	            q.push(make_pair(a-1,b-2));
	            arr[a-1][b-2]=1;
	        }
	        if(isvalid(a-1,b+2,row,column)&& arr[a-1][b+2]!=1)
	        {
	            mp[make_pair(a-1,b+2)]=mp[temp]+1;
	            q.push(make_pair(a-1,b+2));
	            arr[a-1][b+2]=1;
	        }
	        if(isvalid(a+1,b-2,row,column)&& arr[a+1][b-2]!=1)
	        {
	            mp[make_pair(a+1,b-2)]=mp[temp]+1;
	            q.push(make_pair(a+1,b-2));
	            arr[a+1][b-2]=1;
	        }
	        if(isvalid(a+1,b+2,row,column)&& arr[a+1][b+2]!=1)
	        {
	            mp[make_pair(a+1,b+2)]=mp[temp]+1;
	            q.push(make_pair(a+1,b+2));
	            arr[a+1][b+2]=1;
	        }

	    }
	    if(found)
	    cout << ans << endl;
	    else
	    cout << -1 << endl;
	}
	return 0;
}
