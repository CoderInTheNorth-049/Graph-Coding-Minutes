#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int n,int m,vector<vector<int>> &mat){
    for(int x=0;x<m;x++){
        if(mat[i][x]){
            mat[i][x]=0;
            dfs(i,x,n,m,mat);
        }
    }
    for(int x=0;x<n;x++){
        if(mat[x][j]){
            mat[x][j]=0;
            dfs(x,j,n,m,mat);
        }
    }
    
}

int solve(vector<vector<int>> matrix) {
    
    int ans=0;
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]){
                matrix[i][j]=0;
                ans+=1;
                dfs(i,j,n,m,matrix);
                break;
            }
        }
    }
    return ans;

}