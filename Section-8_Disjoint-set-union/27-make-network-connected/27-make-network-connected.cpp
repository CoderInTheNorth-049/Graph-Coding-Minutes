#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<int> parent,rank;
    int n;
public:
    Graph(int n){
        this->n=n;
        parent.resize(n,-1);
        rank.resize(n,1);
    }
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool Union(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a!=b){
            if(rank[a]>rank[b]){
                parent[b]=a;
                rank[b]+=rank[a];
            }
            else{
                parent[a]=b;
                rank[a]+=rank[b];
            }
            return false;
        }
        return true;
    }
    int sets(){
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(parent[i]==-1);
        }
        return ans;
    }
};

int makeConnected(int n, vector<vector<int>> connections) {
    Graph g(n);
    int cycle=0;
    for(auto &it:connections){
        bool ret = g.Union(it[0],it[1]);
        if(ret) cycle+=1;
    }
    int st = g.sets();
    return st-1<=cycle?st-1:-1;
    
}