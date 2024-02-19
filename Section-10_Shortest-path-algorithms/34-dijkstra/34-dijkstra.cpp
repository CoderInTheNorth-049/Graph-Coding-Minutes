#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second

vector<vector<pii>> g;
vector<pii> dp;

vector<int> dijkstra(int dest){
    set<pii> s;
    s.insert({0,1});
    dp[1].ff=0;
    dp[1].ss=-1;
    
    while(!s.empty()){
        pii curr=*s.begin();
        s.erase(curr);
        for(auto &it:g[curr.ss]){
            
            if(curr.ff+it.ss<dp[it.ff].ff){
                s.erase({dp[it.ff].ff,it.ff});
                dp[it.ff].ff=curr.ff+it.ss;
                dp[it.ff].ss=curr.ss;
                s.insert({dp[it.ff].ff,it.ff});
            }
        }
    }
    vector<int> path;
    int p=dest;
    while(p!=-1){
        path.push_back(p);
        p=dp[p].ss;
    }
    reverse(path.begin(),path.end());
    return path;
    
}

vector<int> shortestPath(vector<vector<int>> roads,int n){
    g.clear();g.resize(n+1);
    dp.clear();dp.resize(n+1,{1e9,0});
    for(auto &it:roads){
        g[it[0]].push_back({it[1],it[2]});
        g[it[1]].push_back({it[0],it[2]});
    }
    return dijkstra(n); 
}