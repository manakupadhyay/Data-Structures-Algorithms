    /*
        MAP: Each value has an assoicated key value. No two values can have the same key value.
        Used for Hasing.
    */

#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int main()
{
    map<int,int> mp; // (key, value)

    mp.insert(make_pair(10,1));
    mp.insert(make_pair(20,2)); mp.insert(make_pair(30,3)); mp.insert(make_pair(40,4));mp.insert(make_pair(50,5));
    
    mp[2]=10;   // another way to insert - m[key] = value
    
    // iterator to map
    map<int,int> :: iterator itr;
    
    // find(key) - returns an iterator to the position where 'key' is present
    itr=mp.find(10);
    if(itr!=mp.end())
        cout << itr->second << endl;
    else
        cout << "shit" << endl;
    
    // looping over map
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    return 0;
}
