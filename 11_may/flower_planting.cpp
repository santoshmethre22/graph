#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>>mp;

        for(auto i:paths){
               int u=i[0];
         int v=i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }


        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
        
            int color=1;

            if(ans[i]==0){
                ans[i]=1;
            }

            for(auto j:mp[i]){

                if(ans[i]==ans[j]){
                    ans[i]++;
                }
            }
        }

          

          return ans;
        
    }
};

int main() {

    // Your code here

    return 0;
}