# C_N_Backrracking
#include<bits/stdc++.h>
using namespace std;
//#define N 9;

bool issaferow(int grid[9][9], int row, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
        {
            return false;
        }
    }
    return true;
}

bool issafecol(int grid[9][9], int col, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num)
        {
            return false;
        }
    }
    return true;
}

bool issafegrid(int grid[9][9], int row , int col, int num)
{
    int rowfactor=row-(row%3);
    int colfactor=col-(col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+rowfactor][j+colfactor]==num)
            return false;
        }
    }
    return true;
}


bool issafe(int grid[9][9], int row, int col, int i)
{
    if(issaferow(grid,row,i) && issafecol(grid, col, i) && issafegrid(grid, row, col, i))
    {
        return true;
    }
    return false;
}

bool findemptyspaces(int grid[9][9],int &row,int &col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            {
            row=i;
            col=j;
            return true;
            }
        }
    }
    return false;
}


bool solvesudoku(int grid[9][9])
{
    int row,col;
    if(!findemptyspaces(grid,row,col))
    {
        return true;
    }
    
    for(int i=1;i<=9;i++)
    {
        if(issafe(grid,row,col,i))
        {
            grid[row][col]=i;
            if(solvesudoku(grid))
            {
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int grid[9][9];
    
    for(int i=0;i<9;i++)
    {
        
        for(int j=0;j<9;j++)
        {
            int n;
            cin>>n;
            grid[i][j]=n;
        }
    }
    
    solvesudoku(grid);
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

}
