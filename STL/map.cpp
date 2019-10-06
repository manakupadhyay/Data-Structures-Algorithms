#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int main()
{
    map<int,int> mp;
    mp.insert(make_pair(10,1));
    mp.insert(make_pair(20,2)); mp.insert(make_pair(30,3)); mp.insert(make_pair(40,4));mp.insert(make_pair(50,5));
    mp[2]=10;   // another way to insert...

    map<int,int> :: iterator itr;
    itr=mp.find(2);
    if(itr!=mp.end())
    {
        int temp=itr->second;
        cout << temp;
        cout << "hey" << endl;
    }
    else
        cout << "shit" << endl;
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    map<pair<int,int>,int> m;
    m.insert(make_pair(make_pair(0,1),3));
    map<pair<int,int>,int> :: iterator i;
    for(i=m.begin();i!=m.end();i++)
   // cout   << i->first << " " << i->second << endl;
    return 0;
}
