# C_N_Backrracking
#include<bits/stdc++.h>
using namespace std;

void printSolution(int** solutions,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solutions[i][j] << " ";
		}
	}
	cout<<endl;
}

void mazehelper(int maze[][20],int x,int y, int** solutions,int n)
{
    if(x == n-1 && y == n-1){
		solutions[x][y] =1;
		printSolution(solutions,n);
      	solutions[x][y] =0;
		return;
	}
    
    
      
//if(maze[x][y]==0 || solutions[x][y]==1 || x>=n || x<0 || y>=n || y<0)
    //return;
    

if( y>=n || y<0 || x>=n || x<0 || maze[x][y]==0 || solutions[x][y]==1 )
return;
    
    solutions[x][y]=1;
    mazehelper(maze,x-1,y,solutions,n);
    mazehelper(maze,x+1,y,solutions,n);
    mazehelper(maze,x,y-1,solutions,n);
    mazehelper(maze,x,y+1,solutions,n);
    solutions[x][y]=0;
    //return;
    
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  
  int** solutions= new int*[n];
  for(int i=0;i<n;i++)
  {
      solutions[i]=new int[n];
  }
  
  
  mazehelper(maze,0,0,solutions,n);
  
  /*int** a = new int*[rowCount];
for(int i = 0; i < rowCount; ++i)
    a[i] = new int[colCount];*/


}
