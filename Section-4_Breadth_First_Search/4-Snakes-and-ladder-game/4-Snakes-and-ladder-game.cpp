#include<bits/stdc++.h>
using namespace std;

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(37);
    for(auto &it:snakes){
        board[it.first]=it.second-it.first;
    }
    for(auto &it:ladders){
        board[it.first]=it.second-it.first;
    }
    vector<vector<int>> graph(37);
    for(int i=1;i<36;i++){
        
        for(int j=1;j<=6;j++){
            if(i+j+board[i+j]<=36) graph[i].push_back(i+j+board[i+j]);
        }
    }
    queue<int> q;
    vector<int> dist(37),vis(37);
    q.push(1);
    vis[1]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &it:graph[node]){
            if(!vis[it]){
                q.push(it);
                dist[it]=dist[node]+1;
                vis[it]=1;
            }
        }
    }
    return dist[36];
}
