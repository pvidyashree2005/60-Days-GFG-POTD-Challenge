#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();

        // Step 1: Create all edges
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = abs(houses[i][0] - houses[j][0]) +
                           abs(houses[i][1] - houses[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }

        // Step 2: Sort edges
        sort(edges.begin(), edges.end());

        // Step 3: Initialize DSU
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 4: Kruskal's Algorithm
        int minCost = 0;
        int edgesUsed = 0;

        for (auto &edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (find(u) != find(v)) {
                unionSet(u, v);
                minCost += cost;
                edgesUsed++;

                if (edgesUsed == n - 1) break;
            }
        }

        return minCost;
    }
};
