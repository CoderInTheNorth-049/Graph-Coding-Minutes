#include<bits/stdc++.h>
using namespace std;
vector<int> vis;

//dfs gives if its even length or not
bool dfs(int parent,int node,int color,vector<vector<int>> &graph){
    vis[node]=color;
    for(auto &it:graph[node]){
        if(vis[it]==0){
            bool poss=dfs(node,it,3-color,graph);
            if(!poss) return false;
        }
        else if(it!=parent && color==vis[it]) return false;
    }
    return true;
}
bool solve(vector<vector<int>> graph)
{
    vis.clear();
    vis.resize(graph.size());
    for(int i=0;i<graph.size();i++){
        if(vis[i]==0) {
            bool poss=dfs(-1,i,1,graph);
            if(!poss) return true;
        }
    }
    return false;
}