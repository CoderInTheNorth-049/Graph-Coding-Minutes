#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> gp;
vector<bool> vis,stk;

bool dfs(int node){
    vis[node]=true;
    stk[node]=true;
    
    for(auto &it:gp[node]){
        if(stk[it]){
            return true;
        }
        else if(!vis[it]){
            bool poss=dfs(it);
            if(poss) return true;
        }
    }
    stk[node]=false;
    return false;
}

bool canFinish(vector<vector<int>> prerequisites,int n) {
    gp.clear();vis.clear();stk.clear();
    gp.resize(n);vis.resize(n);stk.resize(n);
    
    for(auto &it:prerequisites){
        gp[it[1]].push_back(it[0]);
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bool flag=dfs(i);
            if(flag) return false;
        }
    }
    return true;
        
}