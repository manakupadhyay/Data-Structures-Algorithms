        /*
            VECTORS: Vectors are dynamic array. They are passed by value.
        */        

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
void print(vector<int> v)
{
    if(v.size() == 0)
    {
        cout << "Vector is empty" << endl;
        return;
    }
    vector<int> :: iterator itr;        // iterator - used to iterate over a vector
    for(itr = v.begin() ; itr!= v.end(); itr++) 
    {
        cout << *itr << " ";       
    }
    cout << endl;
}
int main()
{
    vector<int> v;      // creating a vector of type integer
    v.push_back(10);      // inserts element to the end
    v.push_back(20);
    v.push_back(15);
    print(v);
    // deletes element at the end of vector
    v.pop_back();               
    v.push_back(9);
    v.push_back(12);
    print(v);
    // returns size of vector
    cout << v.size() << endl;
    // return capacity of vector   
    cout << v.capacity() << endl;
    // checks whether the vector is empty or not
    cout << v.empty() << endl;
    // return first elemtnt
    cout << v.front() << endl;
    // return last element
    cout << v.back() << endl;
    // clears the vector
    v.clear();
    print(v);
    return 0;
}