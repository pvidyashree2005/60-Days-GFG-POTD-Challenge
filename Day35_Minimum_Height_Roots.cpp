#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {

        if (V == 1) {
            return {0};
        }

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        // Build graph
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        // Push all leaf nodes
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remaining = V;

        // Remove leaves level by level
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
