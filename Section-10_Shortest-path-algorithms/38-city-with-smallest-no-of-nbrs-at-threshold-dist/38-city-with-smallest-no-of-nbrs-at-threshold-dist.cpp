#include<bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>> edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e7));
        vector<int> freq(n,1e7);
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto &it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        vector<int> cnt(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt[i]+=1;
            }
        }
        int mn=*min_element(cnt.begin(),cnt.end());
        int ans=-1;
        for(int i=0;i<n;i++) if(cnt[i]==mn) ans=i;
        return ans;
        
}