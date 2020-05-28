    // PROBLEM CONSTRAINT: THE RAT CAN ONLY MOVE RIGHT AND DOWNWARD    
    /*
        Time Complexity: O(2^(n^2)).
        Space Complexity: O(n^2)- because ouput matrix is required
    */
#include <iostream>
using namespace std;
#define N 5
void printSolution(int solution[N][N])
{
    // PRINT SOLUTION MATRIX
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}
bool isPathSafe(int x,int y,int maze[N][N])
{
    if(x >=0 && x < N && y>=0 && y < N && maze[x][y] == 1)  // IF CORDINATES ARE VALID
        return true;
    return false;    
}
bool solve(int maze[N][N],int sol[N][N], int x,int y)
{
    if(x == N-1 && y == N-1 && maze[x][y] == 1) // DESTINATION IS REACHED
    {
        sol[x][y] = 1;
        return true;
    }
    if(isPathSafe(x,y,maze))
    {
        sol[x][y] = 1;      // IF PATH IS SAFE, MARK THE CURRENT CELL 
        if(solve(maze,sol,x+1,y))   // go to next row(go down)
            return true;
        if(solve(maze,sol,x,y+1))   // go to next column(go to right side)
            return true;
        sol[x][y] = 0;      // BACKTRACK, IF RAT CANNOT GO FURTHER(EITHER DOWN OR RIGHT)
    }
    return false;
}
void solveMaze(int maze[N][N])
{
    // SOLUTION MATRIX THAT WILL CONTAIN THE TRACES OF RAT IN REACHING THE DESTINATION
    int solutionMatrix[N][N] = {{ 0, 0, 0, 0, 0}, 
                                { 0, 0, 0, 0, 0}, 
                                { 0, 0, 0, 0, 0}, 
                                { 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};
    if(!solve(maze, solutionMatrix, 0,0)) 
    {
        cout << "No path exists" << endl;
        return;
    }
    printSolution(solutionMatrix);
}
int main()
{
    // MAZE
    int maze[N][N] = { {1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1},
                        {1, 0, 1, 0, 1},
                        {1, 0, 0, 0, 1},
                        {0, 1, 1, 1, 1} };
    solveMaze(maze);
    return 0;
}