    /*
        SETS: Sets are conatineres that stores unique elements. The elements in the set are
        always stored. They are implemented as Binary Search Trees.
        Sets are passed by value.
    */

#include <iostream>
#include <set>
using namespace std;
void print(set<int> s)
{
    if(s.size() == 0)
    {
        cout << "Set is empty" << endl;
        return;
    }
    set<int> :: iterator itr;
    for(itr = s.begin(); itr!=s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}
int main ()
{
    set<int> s;     // cerates a set
    // inserting elements
    s.insert(30); s.insert(10); s.insert(40); s.insert(30); s.insert(10);
    // retutrn size of the set
    cout << s.size() << endl;
    s.insert(89);
    print(s);
    cout << s.size() << endl;
    // checks wheather the set is empty or not
    cout << s.empty() << endl;
    // erases the specified element
    s.erase(30);
    print(s);
    // counts elements with the passed value
    cout << s.count(10) << endl;
    // clears the set
    s.clear();
    return 0;
}
