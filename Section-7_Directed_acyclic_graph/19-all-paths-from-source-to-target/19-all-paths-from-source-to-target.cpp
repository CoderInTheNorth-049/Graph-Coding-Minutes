#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int target,vector<int> &v,vector<vector<int>> &ans,vector<vector<int>> &g){
    v.push_back(node);
    if(node==target){
        ans.push_back(v);
    }
    for(auto &it:g[node]){
        dfs(it,target,v,ans,g);
    }
    v.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
     vector<vector<int>> ans;
     vector<int> vec;
     dfs(0,graph.size()-1,vec,ans,graph);
     return ans;
}