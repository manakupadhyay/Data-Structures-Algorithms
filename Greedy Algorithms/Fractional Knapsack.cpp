        /*
            Given weights and values of n items, we need to put these items in a knapsack of 
            capacity W to get the maximum total value in the knapsack.
            In Fractional Knapsack, we can break items for maximizing the total value of knapsack.

            TIME COMPLEXITY: O(N * LOG N) - sorting takes O(N * LOG N) and login take O(N). So,
                                total = O(N*LOG N) + O(N) = O(N*LOG N)
            SPACE COMPLEXITY: O(1)
        */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool sortByRatio(pair<int,int> &a, pair<int,int> &b)
{   
    return ( (a.first/a.second) > (b.first/b.second) );
}
int main()
{
    vector<pair<int, int> >v;
    int items, knapsack;
    // number of items in knapsack
    cout << "Enter the number of items; ";
    cin >> items;
    // weight/size of knapsack
    cout << "Enter the size of Knapsack: ";
    cin >> knapsack;
    for(int i=0;i<items;i++)
    {
        cout << "Enter " << i+1 << " item's value and weight: ";
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    cout << "Item" << "\t" << "Value" << "\t" << "Weight" << endl;
    for(int i=0;i<v.size();i++)
    {
        cout << i+1 << "\t" << v[i].first << "\t" << v[i].second << endl;
    }

    // sort the input on the basis of profit/value - in descending order
    sort(v.begin(), v.end(), sortByRatio);

    // show the sorted input
    cout << "Item" << "\t" << "Value" << "\t" << "Weight" << endl;
    for(int i=0;i<v.size();i++)
    {
        cout << i+1 << "\t" << v[i].first << "\t" << v[i].second << endl;
    }

    // CODE LOGIC

    // it will contain total profit/value in the end
    double totalValue = 0;
    int i=0;
    while(true)
    {
        if(v[i].second > knapsack)
        {
            totalValue += ( (v[i].first) * ( (double) knapsack / v[i].second) );
            knapsack = 0;
            break;
        }
        else
        {
            totalValue += v[i].first;
            knapsack -= v[i].second;
        }
        i++;
    }
    cout << "Total value of the Knapsack is: " << totalValue << endl;
    return 0;
}