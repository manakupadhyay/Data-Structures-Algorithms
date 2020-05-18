#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int vertex;         // number of vertex
    list<int> *adj;       // list(doubly linked list) of arrays...
public:
    void bfs(int );
    void dfs(int);
    Graph(int num)
    {
        vertex=num;
        adj=new list<int>[num];
        cout << "Vertices are: ";
        for(int i=0;i<num;i++)
            cout << i << " ";
        cout << endl;
    }
    void addEdge(int i,int j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    void display();
};
void Graph :: display()
{
    cout << "Entered graph is: " << endl;
    for(int i=0;i<vertex;i++)
    {
        cout << i << "-->";
        list <int>:: iterator itr;
        for(itr=adj[i].begin();itr!=adj[i].end();itr++)
        {
            cout << *itr << "->";
        }
        cout << "NULL" << endl;
    }
}
void Graph :: dfs(int start)            // DEPTH FIRST SEARCH...
{
    bool visited[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    stack<int> s;
    s.push(start);
    cout << start << " ";
    visited[start]=true;
    while(!s.empty())
    {
        int temp=s.top(),flag=0;
        list<int> :: iterator itr;
        for(itr=adj[temp].begin();itr!=adj[temp].end();itr++)
        {
            if(visited[*itr]==false)
            {
                s.push(*itr);
                cout << *itr << " ";
                visited[*itr]=true;
                flag=1;
                break;
            }
        }
        if(flag==0)
            s.pop();
    }
}
void Graph :: bfs(int start)        // BREADTH FIRST SEARCH...
{
    bool visited[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int temp=q.front();
        cout << temp << " ";
        list<int> :: iterator itr;
        for(itr=adj[temp].begin();itr!=adj[temp].end();itr++)
        {
            if(!visited[*itr])
            {
                visited[*itr]=true;
                q.push(*itr);
            }
        }
         q.pop();
    }
}
int main()
{
    cout << "Enter the number of vertices: ";
    int num,again;
    cin >> num;
    Graph go(num);
    cout << "Enter edges" << endl;
    do{
        cout << "Enter initial vertex: ";
        int i,j;
        cin >> i;
        cout << "Enter terminal vertex: ";
        cin >> j;
        go.addEdge(i,j);
        cout << "Enter 1 for more 0 for exit: ";
        cin >> again;
    }while(again==1);
    go.display();
    cout << "BFS of graphs is: ";
    cout << "Enter the starting vertex: ";
    int startVertex;
    cin >> startVertex;
    go.bfs(startVertex);
    cout << endl;
    cout << "DFS of the graph is: " << endl;
    go.dfs(startVertex);
    return 0;
}
