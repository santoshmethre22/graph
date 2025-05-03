
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    
    void dfs(int node ,vector<vector<int>>&rooms,vector<bool>&vis){
        
                vis[node]=true;
    
                for(auto i:rooms[node]){
                    if(!vis[i]){
                        dfs(i,rooms,vis);
                    }
                }
    
        }
    
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n=rooms.size();
            vector<bool>vis(n,false);
            dfs(0,rooms,vis);
    
            for(int i=0;i<n;i++){
                if(!vis[i]) return false;
            }
            
            
            return true;
            
        }
    };
    int main() {
    
        // Your code here
    
        return 0;
    }