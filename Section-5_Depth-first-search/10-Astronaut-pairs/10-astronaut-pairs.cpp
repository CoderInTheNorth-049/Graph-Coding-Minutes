#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<vector<int>> &gp,vector<bool> &vis){
    int helper=1;
    vis[node]=true;
    for(auto &it:gp[node]){
       if(!vis[it]) helper+=dfs(it,gp,vis);
    }
    return helper;

}
int count_pairs(int N, vector<pair<int,int> > ast){
    vector<vector<int>> gp(N);
    vector<bool> vis(N);
    for(auto &it:ast){
        gp[it.first].push_back(it.second);
        gp[it.second].push_back(it.first);
    }
    int ans=0,temp;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            temp=dfs(i,gp,vis);
            // temp=helper+1;
            ans+=(temp*(N-temp));
        }
    }
    return ans/2;
}