#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<int> parent;
public:
    Graph(){
        parent.resize(1e3+1,-1);
    }
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool add(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a==b) return true;
        parent[a]=b;
        return false;
    }
};

vector<int> findUselessConnection(vector<vector<int>> edges) {
    Graph g;
    vector<int> ans(2);
    for(auto &it:edges){
        bool ret=g.add(it[0],it[1]);
        if(ret) ans[0]=it[0],ans[1]=it[1];
    }
    return ans;
        
}