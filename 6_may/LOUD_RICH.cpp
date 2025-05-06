#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>


using namespace std;

class Solution {
    public:
        int n;
    
        void topo(vector<vector<int>>& adj, vector<int>& topo_sort) {
            vector<int> indegree(n, 0);
            for(int i = 0; i < n; i++) {
                for(auto j : adj[i]) {
                    indegree[j]++;
                }
            }
    
            queue<int> q;
            for(int i = 0; i < n; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            while(!q.empty()) {
                int node = q.front(); q.pop();
                topo_sort.push_back(node);
                for(auto i : adj[node]) {
                    indegree[i]--;
                    if(indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
    
        vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
            n = quiet.size();
            vector<vector<int>> adj(n);
    
            // Build reversed graph: u -> v means u is richer than v
            for(auto& i : richer) {
                int u = i[0];
                int v = i[1];
                adj[u].push_back(v);
            }
    
            vector<int> topo_sort;
            topo(adj, topo_sort);
    
            vector<int> ans(n);
            for(int i = 0; i < n; i++) {
                ans[i] = i; // assume person i is quietest for now
            }
    
            for(int u : topo_sort) {
                for(int v : adj[u]) {
                    if(quiet[ans[u]] < quiet[ans[v]]) {
                        ans[v] = ans[u];
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