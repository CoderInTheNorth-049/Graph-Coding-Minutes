#include<bits/stdc++.h>
using namespace std;

class prim{
    int n;
    
public:
    prim(int n){
        this->n=n+1;
    }
    int algo(vector<vector<pair<int,int>>> &g){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n+1);
        
        int ans=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(vis[curr.second]) continue;
            ans+=curr.first;
            vis[curr.second]=1;
            for(auto &it:g[curr.second]){
                if(!vis[it.first]){
                    pq.push({it.second,it.first});
                }
                
            }
        }
        return ans;
    }
    
};

class Graph{
    vector<vector<pair<int,int>>> g;
    int n;
public:
    Graph(int n){
        this->n=n;
        g.resize(n+1);
    }
    vector<vector<pair<int,int>>> addEdge(vector<vector<int>> &edges){
        for(auto &it:edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        return g;
    }
};

int MST(int n, vector<vector<int>> edges){
    Graph g(n);
    vector<vector<pair<int,int>>> gp=g.addEdge(edges);
    prim p(n);
    int ans=p.algo(gp);
    return ans;
    
}