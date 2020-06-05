        /*
            Given an array of jobs where every job has a deadline and associated profit if the job 
            is finished before the deadline. It is also given that every job takes single unit of time, 
            so the minimum possible deadline for any job is 1. How to maximize total profit if only one 
            job can be scheduled at a time.

            TIME COMPLEXITY: O(N ^ 2)
            
        */




#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
bool sortByProfit(pair<pair<char,int>,int> &a , pair<pair<char,int>,int> &b)
{
    return a.second > b.second;
}
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    cout << "Enter no. of jobs: ";
    int jobs;
    cin >> jobs;
    vector<pair<pair<char,int>,int>> v; // < < char, deadline >, profit>
    for(int i=0;i<jobs;i++)
    {
        cout << "Enter " << i+1 << " job name, deadline and profit respectively" << endl;
        char name; int d,p;
        cin >> name;
        cin >> d;
        cin >> p;
        v.push_back(make_pair(make_pair(name,d),p));
    }
    cout << "Job" << "\t" << "Deadline" << "\t" << "Profit" << endl;
    for(int i=0;i<v.size();i++)
    {
        cout << v[i].first.first << "\t" << v[i].first.second << "\t\t" << v[i].second << endl;
    }

    // sort the jobs on the basis of profit - in descending order
    sort(v.begin(), v.end() , sortByProfit);

    // input after sorting
    cout << "Job" << "\t" << "Deadline" << "\t" << "Profit" << endl;
    for(int i=0;i<v.size();i++)
    {
        cout << v[i].first.first << "\t" << v[i].first.second << "\t\t" << v[i].second << endl;
    }

    // CODE LOGIC
    
    // max profit made by sequencing jobs
    int maxProfit = 0 ;

    // it keep the track of slots - whether they are occupied or not
    bool slot[jobs] = {false};
    
    // it assigns the job in the slot
    int result[jobs];

    // iterating through each job
    for(int i=0;i<jobs;i++)
    {
        // find the right slot for the job - slot which is max and is unoccupied
        for(int j = min(v[i].first.second, jobs)-1; j>=0; j--)
        {
            if(slot[j] == false)
            {
                maxProfit += v[i].second;
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    // output
    cout << "Jobs: ";
    for(int i=0;i<jobs;i++)
    {
        if(slot[i])
        {
            cout << v[result[i]].first.first << " ";
        }
    }
    cout << endl;
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}