#include<bits/stdc++.h>
using namespace std;

map<int,int> col_cnt;
vector<vector<bool>> vis;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,int col){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != 1 || vis[i][j]) return;
    vis[i][j]=true;
    grid[i][j]=col;
    col_cnt[col]++;
    for(int a=0;a<4;a++){
        dfs(i+dx[a],j+dy[a],n,m,grid,col);
    }
}

bool check(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}

int largestIsland(vector<vector<int>> grid) {
    int n=grid.size(),m=grid[0].size();
    
    vis.clear();col_cnt.clear();
    vis.resize(n,vector<bool>(m,false));
    
    int col=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                col+=1;
                dfs(i,j,n,m,grid,col);
            }
        }
    }
    
    int ans=0;
    for(auto &it:col_cnt) ans=max(ans,it.second);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                int x,y;
                set<int> st;
                for(int a=0;a<4;a++){
                    x=i+dx[a];
                    y=j+dy[a];
                    if(check(x,y,n,m)){
                        st.insert(grid[x][y]);
                    }
                }
                int sum=1;
                for(auto &it:st) sum+=col_cnt[it];
                ans=max(ans,sum);
            }
        }
    }
    return ans;   
}
