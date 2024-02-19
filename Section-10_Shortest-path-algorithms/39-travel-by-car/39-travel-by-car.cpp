#include<bits/stdc++.h>
using namespace std;

vector<int> travelByCar(int n,int l, vector<vector<int>>edges ,vector<vector<int>> queries)
{
    vector<vector<int>> dist(n,vector<int>(n,1e7)),fuel(n,vector<int>(n,1e7));
    for(auto &it:edges){
        int x=it[0],y=it[1],d=it[2];
        x-=1,y-=1;
        dist[x][x]=0;
        dist[y][y]=0;
        dist[x][y]=d;
        dist[y][x]=d;
        fuel[x][x]=0;
        fuel[y][y]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) if(i!=j && dist[i][j]<=l) fuel[i][j]=1;
        
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                fuel[i][j]=min(fuel[i][j],fuel[i][k]+fuel[k][j]);
            }
        }
    }
    
    vector<int> ans(queries.size());
    for(int i=0;i<queries.size();i++){
        int ret=fuel[queries[i][0]-1][queries[i][1]-1];
        ret>=1e7?ans[i]=-1:ans[i]=ret-1;
    }
    return ans;
}