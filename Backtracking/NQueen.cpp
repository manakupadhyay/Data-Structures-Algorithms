#include <iostream>
#define N 4
using namespace std;
void printSolution(int b[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValid(int b[N][N],int row,int col){
    int i,j;
    for(i=0;i<col;i++)
        if(b[row][i])
            return false;
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
        if(b[i][j])
            return false;
    for(i=row,j=col; j>=0 && i<N ; i++ , j--)
        if(b[i][j])
            return false;

    return true;
}
bool solve(int b[N][N], int col){
    if(col>=N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(isValid(b,i,col))
        {
            b[i][col]=1;
            if(solve(b,col+1))
                return true;
            b[i][col]=0;
        }
    }
    return false;
}
bool solveQueen(){
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 },
                         }; 
    if(solve(board,0) == false)
    {
        cout << "Cannot be solved" << endl;
        return false;
    }
    printSolution(board);
      return true;
}
int main(){
    solveQueen();
    return 0;
}