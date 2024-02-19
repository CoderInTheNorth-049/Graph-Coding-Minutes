#include<bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) {
    n+=1;
    vector<int> conn(n);
    vector<vector<bool>> g(n,vector<bool>(n));
    
    for(auto &edge:edges){
        g[edge[0]][edge[1]]=true;
        g[edge[1]][edge[0]]=true;
        conn[edge[0]]+=1;
        conn[edge[1]]+=1;
    }
    int ans=1e9;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(g[i][j] && g[j][k] && g[k][i]){
                    ans=min(ans,conn[i]+conn[j]+conn[k]-6);
                }
            }
        }
    }
    if(ans==1e9) return -1;
    return ans;
}