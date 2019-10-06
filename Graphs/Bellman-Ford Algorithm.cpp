#include <iostream>
#define V 9
#define E 29
using namespace std;
void bellman(int graph[][V],int src)
{
    int u=src;
    int dis[V]={INT_MAX};
    dis[u]=0;
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            if(graph[u][j] && dis[u]+graph[u][j] < dis[j])
            {
                dis[j]=dis[u]+graph[u][j];
            }
        }
    }
    cout << "Vertex distance from source(0) : " << endl;
    for(int i=0;i<V;i++)
    {
        cout << i << "\t" << dis[i] << endl;
    }

}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        cout << "Hello" << endl;

    bellman(graph,0);

    return 0;
}
