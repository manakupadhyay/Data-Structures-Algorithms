#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
	    int n1,n2,n3;
	    cin >> n1 >> n2 >> n3;
	    int arr1[n1],arr2[n2],arr3[n3];
	    map<int,int> mp;
	    for(int i=0;i<n1;i++)
	    {
	        cin >> arr1[i];
	        int j=arr1[i];
	        mp[j]=1;
	    }
	    for(int i=0;i<n2;i++)
	    {
	        cin >> arr2[i];
	        int j=arr2[i];
	        if(mp[j]==1)
	        {
	            mp[j]=2;
	        }
	    }
	    bool flag=false;
	    for(int i=0;i<n3;i++)
	    {
	        cin >> arr3[i];
	        int j=arr3[i];
	        if(mp[j]==2)
	        {
	            flag=true;
	            mp[j]=3;
	        }
	    }
	    map<int,int> :: iterator itr;
	    if(flag==true)
	    {
    	    for(itr=mp.begin();itr!=mp.end();itr++)
    	    {
    	        int temp=itr->second;
    	        if(temp==3)
    	        {
    	            cout << itr->first << " ";
    	        }
    	    }
	    }
	    else
	    {
	        cout << -1 << " ";
	    }
	    cout << endl;
	}
	return 0;
}
