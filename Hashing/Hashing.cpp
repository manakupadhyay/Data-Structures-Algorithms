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
	multimap<int,int> mp;
	int key,value,again;
	do{
		cout <<  "Enter key and value: ";
		cin >> key >> value;
		int hash=hashFunction(key);
		mp.insert(make_pair(hash,value));
		cout << "Enter 1 to enter more and 0 for exit: ";
		cin >> again;
	}while(again!=0);
	cout << "KEY" << "\t" << "VALUE" << endl;
	multimap<int,int> :: iterator itr;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		cout << itr->first <<"\t" << itr->second << endl;
	}
	return 0;
}