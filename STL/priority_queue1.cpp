        /*
        PRIORITY QUEUE: The first element of the queue if always the largest and elements are in 
        non-increasing order
        */

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue <int> q;
    q.push(5);
    q.push(10);
    q.push(51);
    q.push(-7);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.size() << endl;
    cout << q.empty() << endl;
    return 0;
}
