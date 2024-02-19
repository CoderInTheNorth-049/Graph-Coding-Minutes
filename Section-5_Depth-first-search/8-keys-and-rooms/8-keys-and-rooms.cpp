#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> &gp,vector<bool> &vis){
    vis[node]=true;
    for(auto &it:gp[node]){
        if(!vis[it]){
            dfs(it,gp,vis);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>> rooms) {
   int n=rooms.size();
   vector<bool> vis(n);
   dfs(0,rooms,vis);
   for(int i=0;i<n;i++) if(!vis[i]) return false;
   return true;
}