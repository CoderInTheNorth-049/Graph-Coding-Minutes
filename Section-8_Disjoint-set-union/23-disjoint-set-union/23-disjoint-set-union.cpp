#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    int V;
    vector<int> parent; 
    public:
    Graph(){
        parent.resize(1e5+1,-1);
    }
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i] = find(parent[i]);
    }
    bool add(int x,int y,int id){
        int a=find(x);
        int b=find(y);
        if(a!=b){
            if(id==1) parent[a]=b;
            return false;
        }
        return true;
    }
};

vector<bool> DSU(vector<vector<int>>query)
{
    Graph g;
    vector<bool> ans;
    for(auto &it:query){
        bool ret=g.add(it[1],it[2],it[0]);
        if(it[0]==2) ans.push_back(ret);
    }
    return ans;
}