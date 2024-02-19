#include<bits/stdc++.h>
using namespace std;
int col;
    int initialCol;
    vector<pair<int,int>> ans;

    void helper(vector<vector<int>> &arr, int r, int c){
        int n = arr.size();
        int m = arr[0].size();
        if(r<0 || c<0 || r>=n || c>=m || arr[r][c]!=initialCol) return;

        arr[r][c] = -col;  // to distinguish btw colors
        helper(arr,r,c+1);
        helper(arr,r,c-1);
        helper(arr,r+1,c);
        helper(arr,r-1,c);

        // Backtracking

        // checking if it was boundary color or not

        if(!(r==0 || c==0 || r==n-1 || c==m-1 || arr[r+1][c]!=-col || arr[r-1][c]!=-col || arr[r][c-1]!=-col || arr[r][c+1]!=-col)){
            ans.push_back({r,c});  // internal color
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>> arr, int r, int c, int color) {
        col = color;
        initialCol = arr[r][c];
        int n = arr.size();
        int m = arr[0].size();
        if(col==initialCol) return arr;
        helper(arr,r,c);
        for(auto p : ans){
            int i = p.first;
            int j = p.second;
            arr[i][j] = initialCol;   // retaining the color of internal node
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]<0) arr[i][j] = col;  // boundary color
            }
        }

        return arr;
    }