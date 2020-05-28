            // TIME COMPLEXITY: O(V*V)
            // TIME COMPLEXITY USING ADJECTY LIST: O(V+E)

#include <iostream>
#include <queue>
using namespace std;
#define V 4
bool isBipartite(int g[V][V], int start)
{
    int color[V] = {-1};        // color array
    color[start] = 1;           // assign color '1' to starting vertex
    queue<int> q;
    q.push(start);              // since we are using BFS approach, so queue is req.
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(g[u][u] == 1)        // if graph contains self loop, it is not bipartite
           return false;
        for(int i=0; i<V;i++)
        {
            if(g[u][i] && color[i] == -1)      // if u-i are adjecent vertices and no color is assigned to i yet
            {
                color[i] = color[u] - 1;        // assign a color to i
                q.push(i);                      // push it to queue
            }
            else if(g[u][i] && color[i] == color[u])        // if u-i are adjecent vertices and both have same color, then GRAPH IS NOT BIPARTITE
                return false;
        }
    }
    // if control reaches here, it means all vertices can be colored
    return true;
}
int main() 
{ 
    int G[][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
    isBipartite(G, 0) ? cout << "Yes" << endl : cout << "No" << endl; 
    return 0; 
} 

/*
    the above program is for connected graphs, for disconnected graphs call the isBipartite funtion for each 
    vertex
*/