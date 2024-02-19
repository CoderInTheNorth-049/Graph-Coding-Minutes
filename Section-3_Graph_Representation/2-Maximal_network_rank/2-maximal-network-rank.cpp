#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    vector<set<int>> g(n);
    for(auto &road:roads){
        g[road[0]].insert(road[1]);
        g[road[1]].insert(road[0]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(g[i].find(j)!=g[i].end()){
                ans=max(ans,(int)g[i].size()+(int)g[j].size()-1);
            }
            else ans=max(ans,(int)g[i].size()+(int)g[j].size());
        }
    }
    return ans;
}