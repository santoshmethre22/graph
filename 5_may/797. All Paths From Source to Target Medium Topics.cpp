#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:

      //  void dfs()
        vector<vector<int>>ans;
        void dfs(vector<vector<int>>& adj, int node, int target, vector<bool>& vis, vector<int>& sub_graph) {
            vis[node] = true;
            sub_graph.push_back(node);
    
            if (node == target) {
                ans.push_back(sub_graph);
            } else {
                for (auto v : adj[node]) {
                    if (!vis[v]) {
                        dfs(adj, v, target, vis, sub_graph);
                    }
                }
            }
    
            // Backtrack
            sub_graph.pop_back();
            vis[node] = false;
        }
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<int>sub_graph;
            vector<bool>vis(n,false);
            dfs(graph,0,n-1,vis,sub_graph);

            return ans;
        }
    };


int main(){

    return 0;
}