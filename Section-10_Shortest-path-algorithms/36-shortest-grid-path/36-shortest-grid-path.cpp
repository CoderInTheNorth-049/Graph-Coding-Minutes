#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int x,y,dist;

    node(int x,int y,int dist){
        this->x=x;
        this->y=y;
        this->dist=dist;
    }
};

class cmp{
  public:
  bool operator()(node a,node b){
      return a.dist<=b.dist;
  }
};

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e7));
    int i=0,j=0;
    dist[0][0]=grid[0][0];
    set<node,cmp> st;
    int dx[]={0,0,1,-1};
    int dy[]={-1,1,0,0};
    st.insert(node(i,j,dist[0][0]));
    while(!st.empty()){
        auto it=st.begin();
        int cx=it->x;
        int cy=it->y;
        int cdist=it->dist;
        st.erase(it);
        
        for(int k=0;k<4;k++){
            int nx=cx+dx[k];
            int ny=cy+dy[k];
            
            if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny] > cdist+grid[nx][ny]){
                node temp({nx,ny,dist[nx][ny]});
                if(st.find(temp)!=st.end()){
                    st.erase(st.find(temp));
                }
                int ndist=cdist+grid[nx][ny];
                dist[nx][ny]=ndist;
                st.insert(node(nx,ny,ndist));
                
            }
        }
    }
    return dist[n-1][m-1];
}