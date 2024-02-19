#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int j,int n,int m,vector<vector<int>> &grid,int ans){
    if(i<0 || j<0 || i>=n || j>=m) return 0;
    if(!grid[i][j]) return 0;
    grid[i][j]=0;
    return 1+dfs(i+1,j,n,m,grid,0)+dfs(i,j+1,n,m,grid,0)+dfs(i-1,j,n,m,grid,0)+dfs(i,j-1,n,m,grid,0);
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    int ans=0;
    int n=grid.size(),m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]){
                ans=max(ans,dfs(i,j,n,m,grid,0));
            }
        }
    }
    return ans;
    
}