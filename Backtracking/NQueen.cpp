#include <iostream>
#define N 4     // size of matrix
using namespace std;
void printSolution(int b[N][N]){
    // print the solution, if exists
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValid(int b[N][N],int row,int col){
    // this function check whether queen can be safely placed at [row][col]
    int i,j;
    for(i=0;i<col;i++)      // same row, different columns(starting from left)
        if(b[row][i])
            return false;
    for(i=row,j=col;i>=0 && j>=0;i--,j--)       // upper left diagonal
        if(b[i][j])
            return false;
    for(i=row,j=col; j>=0 && i<N ; i++ , j--)       // lower left diagonal
        if(b[i][j])
            return false;

    return true;   // return true, if no above condition is satisfied, it means queen can be placed at [row][column]
}
bool solve(int b[N][N], int col){
    
    if(col>=N)      // if all queens have been placed, return true
        return true;
    for(int i=0;i<N;i++)        // check for all rows for a particular column
    {
        if(isValid(b,i,col))    
        {
            b[i][col]=1;        // if queen can be placed in (row,column), mark that cell as 1.
            if(solve(b,col+1))  // check for next column
                return true;    
            b[i][col]=0;        // if queen cannot be placed in next column, BACKTRACK
        }
    }
    return false;       // if queen cannot be placed in any of the rows, return false
}
void solveQueen(){
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 },
                         }; 
    if(!solve(board,0))
    {
        cout << "Cannot be solved" << endl;
        return;
    }
    printSolution(board);
}
int main(){
    solveQueen();
    return 0;
}