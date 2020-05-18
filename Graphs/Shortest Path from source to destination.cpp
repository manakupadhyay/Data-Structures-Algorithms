#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool valid(int a,int b,int c,int d)
{
    if(a>=0 && b < d && b>=0 && a<c  )
    return true;
    return false;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
	    int r,c;
	    cin >> r >> c;
	    int m[r][c];
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin >> m[i][j];
	        }
	    }
	    int desx,desy;
	    cin >> desx >> desy;
	    if (m[desx][desy]==0 || m[0][0]==0) {   cout<<"-1\n";   continue;  }
	    queue<pair<int,int> > q;
	    int ans=-1;
	    q.push(make_pair(0,0));            // starting with (0,0)
	    map<pair<int,int>,int> mp;
	    mp.insert(make_pair(make_pair(0,0),0));    // mp[make_pair(0,0)]=0;
	    while(!q.empty())
	    {
	        pair<int,int> temp;
	        temp=q.front();
	        q.pop();
	        int a=temp.first,b=temp.second;
	        if(a==desx && b==desy)
	        {
	            ans=mp[temp];
	            break;
	        }
	        if(valid(a-1,b,r,c) && m[a-1][b]==1)
	        {
	            mp[make_pair(a-1,b)]=mp[temp]+1;
	            q.push(make_pair(a-1,b));
	        }
	        if((valid(a+1,b,r,c)) && m[a+1][b]==1)
	        {
	            mp[make_pair(a+1,b)]=mp[temp]+1;
	            q.push(make_pair(a+1,b));
	        }
	        if(valid(a,b-1,r,c) && m[a][b-1]==1)
	        {
	            mp[make_pair(a,b-1)]=mp[temp]+1;
	            q.push(make_pair(a,b-1));
	        }
	        if(valid(a,b+1,r,c) && m[a][b+1]==1)
	        {
	            mp[make_pair(a,b+1)]=mp[temp]+1;
	            q.push(make_pair(a,b+1));
	        }
	        m[a][b]=0;      // we are marking every visited array...

	    }
	    cout << ans << endl;

	}
	return 0;
}
