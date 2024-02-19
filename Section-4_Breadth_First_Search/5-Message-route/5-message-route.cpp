#include<bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>>edges)
{
    vector<vector<int>> gp(n+1);
    for(int i=0;i<edges.size();i++){
        gp[edges[i][0]].push_back(edges[i][1]);
        gp[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> dist(n+1,-1),vis(n+1);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    dist[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &it:gp[node]){
            if(!vis[it]){
                q.push(it);
                dist[it]=dist[node]+1;
                vis[it]=1;
            }
        }
    }
    return dist[n];
}