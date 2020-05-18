
    /*
                Manak Upadhyay
                18/94006
              	B.Sc. Computer Science(Honors)
                Data Structures Assignment

        DESCRIPTION: The Celebrity Problem
        In a party of N people, only one person is known to everyone.
        Such a person may be present in the party, if yes, he/she doesn't know anyone in the party.
        We can only ask questions like does A know B?. Find the stranger (celebrity) in minimum
        number of questions.

        APPROACH:
        Following is my approach:

        1.Push all the celebrities into a stack.
        2.Pop off top two persons from the stack, discard one person based on return status of knows(A,B).
        3.Push the remained person onto stack.
        4.Repeat step 2 and 3 until only one person remains in the stack.
        5.Check the remained person in stack doesn't have connection with anyone else.
    */

#include <iostream>
#include <stack>                    // Stack taken from STL(Standard Template Library).
using namespace std;
const int N = 8;
bool MATRIX[N][N] = {{0, 0, 1, 0},  // data given as input matrix. We can modify it for different
                    {0, 0, 1, 0},   // data.
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
int findCelebrity(int n)
{
    stack<int> s;
    int C;
    for (int i = 0; i < n; i++)
        s.push(i);
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();
    while (s.size() > 1)
    {
        if (knows(A, B))
        {
            A = s.top();
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }
    C = s.top();
    s.pop();
    if (knows(C, B))
        C = B;

    if (knows(C, A))
        C = A;
    for (int i = 0; i < n; i++)
    {
        if ( (i != C) && (knows(C, i) || !knows(i, C)) )
            return -1;
    }
    return C;
}
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    if(id)
        cout << "No celebrity" << endl;
    else
        cout << "Celebrity ID: " << id << endl;
    return 0;
}
