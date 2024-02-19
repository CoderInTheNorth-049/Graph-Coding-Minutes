#include<bits/stdc++.h>
using namespace std;

bool dfs(int parent,int node,vector<vector<int>> &gp,vector<bool> &vis){
    vis[node]=true;
    for(auto it:gp[node]){
        if(!vis[it]){
            bool poss=false;
            poss = dfs(node,it,gp,vis);
            if(poss) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}

bool solve(int n, vector<vector<int> > edges) {
    vector<vector<int>> gp(n+1);
    vector<bool> vis(n+1);

    for(auto &it:edges){
        gp[it[0]].push_back(it[1]);
        gp[it[1]].push_back(it[0]);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool ans=dfs(0,i,gp,vis);
            if(ans) return true;
        }
    }
    return false;
    
    
}