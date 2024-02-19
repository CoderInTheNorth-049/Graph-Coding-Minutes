#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        dist[0]=0;
        for(auto &it:times){
            g[it[0]].push_back({it[2],it[1]});
        }
        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty()){
            auto curr=st.begin();
            int dst=curr->first;
            int node=curr->second;
            st.erase(curr);
            
            for(auto &it:g[node]){
                int nbr=it.second;
                int edge=it.first;
                if(dst+edge < dist[nbr]){
                    auto f=st.find({dist[nbr],nbr});
                    if(f!=st.end()) st.erase(f);
                    dist[nbr]=dst+edge;
                    st.insert({dist[nbr],nbr});
                }
            }
        }
        int ans=0;
        for(auto &it:dist) ans=max(ans,it);
        return ans==1e9 ? -1:ans;
}