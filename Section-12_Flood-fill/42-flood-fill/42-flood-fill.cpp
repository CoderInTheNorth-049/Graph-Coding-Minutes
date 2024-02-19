#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,int col,int x){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=x) return;
    grid[i][j]=col;
    for(int k=0;k<4;k++) dfs(i+dx[k],j+dy[k],n,m,grid,col,x);
}
vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor){
   int x=image[sr][sc];
   int n=image.size(),m=image[0].size();
   dfs(sr,sc,n,m,image,newColor,x);
   return image;
}