#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool dfs(int i,int j,vector<vector<int>> &grid,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    if(grid[i][j]) return true;
    grid[i][j]=1;
    bool ans=true;
    for(int k=0;k<4;k++){
        ans&=dfs(i+dx[k],j+dy[k],grid,n,m);
    }
    return ans;
}
int closedIsland(vector<vector<int>> grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(!grid[i][j]){
                bool ret=dfs(i,j,grid,n,m);
                if(ret) ans+=1;
                }
            }
        }
        return ans;
}