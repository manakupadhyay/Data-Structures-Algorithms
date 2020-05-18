/*#include <iostream>
#include <set>
using namespace std;

int main ()
{
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(40);
    s.insert(30);
    cout << s.size() << endl;
    s.clear();
     s.insert(30);
    s.insert(10);
    s.insert(40);
    s.insert(30);
    cout << s.size() << endl;
    s.insert(89);
    cout << s.size() << endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{

		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    set<int> s;
    s.clear();
    for(int i=0;i<k;i++)
    {
        s.clear();
        for(int j=i;j<k+i;j++)
        {
            s.insert(A[j]);
        }
        cout << s.size() << " ";
    }
}
