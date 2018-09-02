#include<bits/stdc++.h>
using namespace std;

//max chess board in this ques using backtrack algo can be 10*10 so we will create a global array of chessboard and use it in all ques
int board[11][11];
int i=0;

/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
*/

//create isPossible function to check wheter its possible to place queen at given position 
bool isPossible(int n,int row,int col ){
    //column
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            //vertically not possible
            return false;
        }
    }
    //row
    for(int j=col-1;j>=0;j--){
        if(board[row][j]==1){
            return false;
        }
    }
    //left daigonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i-- , j--){
	if(board[i][j]==1){
      return false;
    }
  }
    //right daigonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i-- , j++){
	if(board[i][j]==1){
      return false;
    }
  }
  //if all conditions are satsified return true
  return true;
}




int nQueenHelper(int n,int row){
    if(row==n){
        i++;
        return 0;
    }
    //if we are here this means base condition is still not achieved
    for(int col=0;col<n;col++){
        if(isPossible(n,row,col)){
            //if the position is possible mark it one
            board[row][col]=1;
            //approach towards smaller problem a.k.a next row
            nQueenHelper(n,row+1);
            //now we have solved the smaller problem and come back
            //if we had found the soln in given configuration we have to reset this cell to find other solutions
            //if we couldnt find any solution then also we have to reset this cell and try on next column
            board[row][col]=0;

        }
    }
    return i;
}




void placeNqueens(int n){
    memset(board,0,sizeof(board));
    //0 here signifies the starting row no.
    cout<<nQueenHelper(n,0);
}


int main(){
    int n;
    cin>>n;
    placeNqueens(n);
    return 0;
}