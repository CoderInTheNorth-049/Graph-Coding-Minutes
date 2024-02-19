#include<bits/stdc++.h>
using namespace std;

bool validBfs(int m, vector<int> seq , vector<vector<int>> edges)
{
    vector<vector<int>> g(m+1);
    for(auto &it:edges){
        g[it[0]].push_back(it[1]);
        g[it[1]].push_back(it[0]);
    }
    queue<int> q;
    vector<bool> vis(m+1);
    q.push(1);
    vis[1]=true;
    int itr=1;
    
    while(!q.empty()){
        //if(itr>seq.size()) return false;
        int node=q.front();
        q.pop();
        set<int> st;
        
            for(auto &it:g[node]){
                if(!vis[it]){
                    st.insert(it);
                    vis[it]=true;
                }
            }
        while(!st.empty()){
            if(st.find(seq[itr])!=st.end()){
                q.push(seq[itr]);
                auto it=st.find(seq[itr]);
                st.erase(it);
            }
            else return false;
            itr+=1;
        }
        
    }
    //if(itr>seq.size())return false;
    return true;
}