#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS function to detect cycle
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis)) {
                    return true; // cycle found
                }
            }
            else if (pathVis[neighbor]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        // Check for cycle in all components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return false; // cycle exists
                }
            }
        }

        return true; // no cycle → can finish
    }
};
