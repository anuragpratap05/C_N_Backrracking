#include<bits/stdc++.h>

int board[11][11];

bool ispossible(int n, int row, int col)
{
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
        return false;
    }
    
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
       if(board[i][j]==1)
        return false; 
    }
    
    for(int i=row-1, j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]==1)
        return false;
    }
    return true;
}

void nqueenhelper(int n, int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    for(int j=0;j<n;j++)
    {
        if(ispossible(n,row,j))
        {
            board[row][j]=1;
            nqueenhelper(n,row+1);
            board[row][j]=0;
        }
    }
    return;
}


void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    
    memset(board,0,11*11*sizeof(int));
    nqueenhelper(n,0);


}

