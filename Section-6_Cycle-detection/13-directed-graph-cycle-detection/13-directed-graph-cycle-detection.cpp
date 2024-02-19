#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gp;
vector<bool> vis,restk;

bool dfs(int node){
    vis[node]=true;
    restk[node]=true;
    
    for(auto &it:gp[node]){
        if(!vis[it]){
            bool poss=dfs(it);
            if(poss) return true;
        }
        else if(restk[it]) return true;
    }
    restk[node]=false;
    return false;
}

bool solve(int n, vector<vector<int>>edges) {
    gp.clear();vis.clear();restk.clear();
    gp.resize(n+1);vis.resize(n+1);restk.resize(n+1);
    
    for(auto &it:edges){
        gp[it[0]].push_back(it[1]);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool poss=dfs(i);
            if(poss) return true;
        }
    }
    return false;
    
}