#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<long long> rank,parent;
    long long n;
public:
    DSU(long long n){
        this->n=n;
        rank.resize(n,1);
        parent.resize(n,-1);
    }
    long long find(long long i){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i]);
    }
    bool add(long long x,long long y){
        long long a=find(x);
        long long b=find(y);
        if(a!=b){
            if(rank[a]>rank[b]){
                parent[b]=a;
                rank[a]+=rank[b];
            }
            else {
                parent[a]=b;
                rank[b]+=rank[a];
            }
            return false;
        }
        return true;
    }
    
};

long long buildRoads(vector<vector<long long>>Coordinates){
    int n=Coordinates.size();
    vector<pair<long long,pair<long long,long long>>> v;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long dist=min(abs(Coordinates[i][0]- Coordinates[j][0]), abs(Coordinates[i][1]- Coordinates[j][1]));
            v.push_back({dist,{i,j}});
        }
    }
    sort(v.begin(),v.end());
    DSU d(v.size());
    long long ans=0;
    for(auto &it:v){
        bool ret=d.add(it.second.first,it.second.second);
        if(!ret) ans+=it.first;
    }
    return ans;
    
}