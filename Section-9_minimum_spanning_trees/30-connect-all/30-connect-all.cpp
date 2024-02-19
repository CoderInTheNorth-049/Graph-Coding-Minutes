#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> rank,parent;
    int n;
public:
    DSU(int n){
        this->n=n;
        rank.resize(n,1);
        parent.resize(n,-1);
    }
    int find(int i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool add(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a!=b){
            if(rank[a]>rank[b]){
                parent[b]=a;
                rank[a]+=rank[b];
            }
            else{
                parent[a]=b;
                rank[b]+=rank[a];
            }
            return true;
        }
        return false;
    }
    int MST(vector<pair<int,pair<int,int>>> &dist){
        int ans=0;
        for(auto &it:dist){
            int wt=it.first;
            int x=it.second.first;
            int y=it.second.second;
            
            bool ret=add(x,y);
            if(ret) ans+=wt;
        }
        return ans;
    }
    
};


int minCostConnectPoints(vector<vector<int>> points) {
    int n=points.size();
    vector<pair<int,pair<int,int>>> dist;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            dist.push_back({temp,{i,j}});
        }
    }
    sort(dist.begin(),dist.end());
    DSU d(n);
    return d.MST(dist);
        
}