#include <iostream>
#include <queue>
#include <iterator>
using namespace std;
void show(priority_queue<int> q)
{
    while(!q.empty())
    {
        int ele=q.top();
        cout << ele << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    priority_queue<int> q;
    q.push(2*(-1));
    q.push(4*(-1));
    q.push(10*(-1));
    q.push(8*(-1));
    q.push(1*(-1));
    //priority_queue <int> :: iterator itr;
    show(q);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    priority_queue<pair<int,int> > qq;
    qq.push(make_pair(2,10));
    qq.push(make_pair(6,12));
    qq.push(make_pair(10,12));
    qq.push(make_pair(1,7));
    while(!qq.empty())
    {
        pair<int,int> temp=qq.top();
        cout << temp.first << " " << temp.second << endl;
        qq.pop();
    }
    priority_queue <int, vector<int>, greater<int> > g ;
}
