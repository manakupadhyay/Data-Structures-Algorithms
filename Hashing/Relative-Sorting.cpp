#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
	    int s1,s2;
	    cin >> s1 >> s2;
	    int arr1[s1];
	    int arr2[s2];
	    map<int,int> mp;
	    for(int i=0;i<s1;i++)
	    {
	        int j;
	        cin >> j;
	        arr1[i]=j;
	        if(mp.find(j)!=mp.end())
	        {
	            int temp=mp[j];
	            mp[j]=temp+1;
	        }
	        else
	        {
	            mp[j]=1;
	        }
	    }
	    for(int j=0;j<s2;j++)
	        cin >> arr2[j];
	    int ans[s1];
	    int k=0;
	    for(int i=0;i<s2;i++)
	    {
	        int j=arr2[i];
	        if(mp.find(j)!=mp.end())
	        {
	            int temp=mp[j];
	            while(temp>0)
	            {
	                ans[k++]=arr2[i];
	                temp--;
	            }
	            mp.erase(j);
	        }
	    }
	    map<int,int> :: iterator itr;
	    for(itr=mp.begin();itr!=mp.end();itr++)
	    {
	        if(itr->second==1)
	        ans[k++]=itr->first;
	        else
            {
                int temp=itr->second;
                while(temp>0)
                {
                    ans[k++]=itr->first;
                    temp--;
                }
            }
	    }
	    for(int i=0;i<k;i++)
	    cout << ans[i] << " ";
	    cout << endl;
	}
	return 0;
}
