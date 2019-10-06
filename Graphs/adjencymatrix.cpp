#include <iostream>
using namespace std;
class Graph
{
    int vertex;     // number of vertex
    bool **adj;         // a 2D array using pointers...
public:
    Graph(int num)
    {
        vertex=num;
        adj=new bool*[num];     // assign number of rows
        for(int i=0;i<num;i++)
        {
            adj[i]=new bool[num];       // assign number of columns
            for(int j=0;j<num;j++)
                adj[i][j]=false;
        }
        cout << "Vertices are :";
        for(int i=0;i<vertex;i++)
            cout << i << " ";
        cout << endl;
    }
    void output()
    {
        for(int i=0;i<vertex;i++)
        {
            for(int j=0;j<vertex;j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void addEdge(int i,int j)
    {
        adj[i][j]=true;
        adj[j][i]=true;
    }
    void removeEdge(int i,int j)
    {
        adj[i][j]=false;
        adj[j][i]=false;
    }
    bool isPath(int i,int j)
    {
        return adj[i][j];
    }
    ~Graph()
    {
        for(int i=0;i<vertex;i++)
            delete[] adj[i];        // delete every column
        delete[] adj;               // delete row
    }
};
int main()
{
    cout << "Enter the number of vertices: ";
    int num,again;
    cin >> num;
    Graph go(num);
    do
    {
        int i,j;
        cout << "Enter the initial vertex: ";
        cin >> i;
        cout << "Enter the terminal vertex :";
        cin >> j;
        go.addEdge(i,j);
        cout << "Want to enter more edges? 1 for yes and 0 for no :";
        cin >> again;

    }while(again==1);
    cout << "Entered graph is :" << endl;
    go.output();
    cout << "Checking path: " << endl;
    int i,j;
    cout << "Enter the initial vertex: ";
    cin >> i;
    cout << "Enter the terminal vertex :";
    cin >> j;
    bool b=go.isPath(i,j);
    cout << b << endl;
    return 0;
}
