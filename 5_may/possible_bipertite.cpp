#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
    public:
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            vector<vector<int>> adj(n + 1); // Nodes are 1-indexed in the problem
            for (auto& pair : dislikes) {
                int u = pair[0], v = pair[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<int> color(n + 1, -1);
    
            for (int i = 1; i <= n; ++i) {
                if (color[i] == -1) {
                    queue<int> q;
                    color[i] = 0;
                    q.push(i);
    
                    while (!q.empty()) {
                        int node = q.front(); q.pop();
    
                        for (int neighbor : adj[node]) {
                            if (color[neighbor] == -1) {
                                color[neighbor] = 1 - color[node];
                                q.push(neighbor);
                            } else if (color[neighbor] == color[node]) {
                                return false;
                            }
                        }
                    }
                }
            }
    
            return true;
        }
    };
    
int main() {

    // Your code here

    return 0;
}