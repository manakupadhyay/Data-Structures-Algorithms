#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <iterator>
using namespace std;
int main()
{
    multiset<int> ms;
    ms.insert(10);
    ms.insert(21);
    ms.insert(10);ms.insert(51);ms.insert(14);ms.insert(122);
    multiset<int> :: iterator i;
    for( i=ms.begin();i!=ms.end();i++)
    {
        cout << *i<< endl;
    }
    i=ms.find(21);
    cout << *i << endl;
    cout << ms.empty() << endl;
    cout << "Erased 10: ";
    ms.erase(10);
    cout << "Printing: ";
    for( i=ms.begin();i!=ms.end();i++)
    {
        cout << *i<< endl;
    }
    cout << "INserting 20 :";
    ms.insert(20);
    cout << "Erasing from start to 51: ";
    ms.erase(ms.begin(),ms.find(51));
    cout << "Printing: ";
    for( i=ms.begin();i!=ms.end();i++)
    {
        cout << *i<< endl;
    }
    multiset<int> ms2{1,2,3,4,5,67,9};
    ms2.swap(ms);
    return 0;
}
