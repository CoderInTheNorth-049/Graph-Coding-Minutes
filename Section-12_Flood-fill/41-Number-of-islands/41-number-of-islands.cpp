#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

void dfs(int i,int j,int n,int m,vector<vector<char>> &grid){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
    grid[i][j]='0';
    for(int k=0;k<4;k++){
        dfs(i+dx[k],j+dy[k],n,m,grid);
    }
    
}
int numIslands( vector<vector<char>> grid)
{
    int ans=0;
    int n=grid.size(),m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]-'0'){
                ans+=1;
                dfs(i,j,n,m,grid);
            }
        }
    }
    return ans;
    
}