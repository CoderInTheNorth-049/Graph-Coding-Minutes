#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> vis,dist;
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
bool ans;

void dfs(int i,int j,int n, int m,int len,int pre,char c,vector<vector<char>> &grid){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=c) return;
    
    if(vis[i][j]){
        if(abs(pre-dist[i][j])>=3){
            ans=true;
        }
        return;
    }
    vis[i][j]=1;
    dist[i][j]=len;
    
    for(int k=0;k<4;k++){
        dfs(i+dx[k],j+dy[k],n,m,len+1,dist[i][j],c,grid);
    }
}

bool containsCycle(vector<vector<char>> grid) {
    int n=grid.size(),m=grid[0].size();
    vis.clear();dist.clear();
    vis.resize(n,vector<int>(m));
    dist.resize(n,vector<int>(m));
    ans=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j,n,m,1,0,grid[i][j],grid);
            }
        }
    }
    return ans;
}