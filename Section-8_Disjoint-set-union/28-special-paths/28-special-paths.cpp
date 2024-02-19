#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<int> parent,rank;
    int n;
public:
    Graph(int n){
        this->n=n;
        parent.resize(n+1,-1);
        rank.resize(n+1,1);
    }
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool add(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a==b) return true;
        if(rank[a]<rank[b]){
            parent[a]=b;
        }
        else parent[b]=a;
        return false;
    }
};

int specialPath(int n, vector<int> a, vector<vector<int>> edges,int start, int end)
{
    int ans=1e9;
    int l=0,r=1e9;
    
    auto f=[&](int mid){
        Graph g(n);
        for(auto &it:edges){
            int dist=abs(a[it[0]-1]-a[it[1]-1]);
            if(dist<=mid)
            {
                bool ret=g.add(it[0]-1,it[1]-1);
            }
        }
        bool ret=g.add(start-1,end-1);
        return ret;
    };
    
    while(l<=r){
        int mid=l+(r-l)/2;
        if(f(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}