#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int hashFunction(int key)
{
	return key%11;
}
int main()
{
	multimap<int,string> mp;       // collection of key,value pairs sorted by keys...
	int key,again;
	string str;
	do{
		cout <<  "Enter key and value: ";
		cin >> key;
		cin.ignore();
		getline(cin,str);
		int hash=hashFunction(key);
		mp.insert(make_pair(hash,str));
		cout << "Enter 1 to enter more and 0 for exit: ";
		cin >> again;
	}while(again!=0);
	cout << "KEY" << "\t" << "VALUE" << endl;
	multimap<int,string> :: iterator itr;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		cout << itr->first <<"\t" << itr->second << endl;
	}
	cout << "Enter the key you want to search: ";
	cin >>  key;
	int hash=hashFunction(key);
	itr=mp.find(key);
	//if(itr!=NULL)
	cout << itr->first << " and " << itr->second << endl;
	//else
    cout << "Not found" << endl;
	return 0;
}
