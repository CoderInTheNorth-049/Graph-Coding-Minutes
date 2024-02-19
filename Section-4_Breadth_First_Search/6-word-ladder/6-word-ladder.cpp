#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    set<string> s;
    for(auto &itr:wordList) s.insert(itr);
    int ans=0;
    queue<string> q;
    q.push(beginWord);
    while(!q.empty()){
        ans+=1;
        vector<string> v;
        int n=q.size();
        for(int i=0;i<n;i++){
            string curr=q.front();
            
            if(curr==endWord) return ans;
            
            for(int j=0;j<curr.size();j++){
                char ch=curr[j];
                for(int k=0;k<26;k++){
                    curr[j]='a'+k;
                    if(s.find(curr)!=s.end()){
                        v.push_back(curr);
                        s.erase(curr);
                    }
                }
                curr[j]=ch;
            }
            q.pop();
        }
        for(auto &it:v) q.push(it);
        
    }
    return 0;
}