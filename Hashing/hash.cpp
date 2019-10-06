#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int hashFunction(int key)
{
    return key%7;
}
int main()
{
    map<int,string> m;
    int roll,again;
    string name;
    cout << "Enter the information" << endl;
    do
    {
        cout << "Enter the roll number of the student: ";
        cin >> roll;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin,name);
        int index=hashFunction(roll);
        m.insert(make_pair(index,name));
        cout << "Enter 1 for more 0 for exit: ";
        cin >> again;
    }while(again==1);
    cout << "Hash Table is: " << endl;
    map<int,string> :: iterator itr;
    cout << "KEY" << "\t" << "VALUE" << endl;
    for(itr=m.begin();itr!=m.end();itr++)
        cout << itr->first << "\t" << itr->second << endl;
    cout << "Enter the roll number you want to search: ";
    cin >> roll;
    int i=hashFunction(roll);
    itr=m.find(i);
    cout << itr->first << " " << itr->second << endl;
    return 0;
}
