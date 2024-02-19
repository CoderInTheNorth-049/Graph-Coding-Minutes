#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<int> parent;
public:
    Graph(){
        parent.resize(1e5+1,-1);
    }
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool add(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a==b) return true;
        else{
            parent[a]=b;
            return false;    
        }
    }
};

bool solve(vector<vector<int>> edges) {
    Graph g;
    for(auto &it:edges){
        bool ans=g.add(it[0],it[1]);
        if(ans) return false;
    }
    return true;
}