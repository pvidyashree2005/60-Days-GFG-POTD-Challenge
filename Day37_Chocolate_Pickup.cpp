#include <iostream>
#include <vector>
#include <cstring>   // for memset
#include <climits>   // for INT_MIN
#include <algorithm> // for max

using namespace std;

class Solution {
public:
    int n, m;
    int dp[71][71][71];

    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        
        // Out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return INT_MIN;
        }

        // Base case
        if (i == n) {
            return 0;
        }

        // Memoization check
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int ans = 0;

        // Try all 9 moves
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                
                int val = 0;

                // If both robots on same cell
                if (j1 == j2) {
                    val = grid[i][j1];
                } else {
                    val = grid[i][j1] + grid[i][j2];
                }

                val += solve(i + 1, j1 + d1, j2 + d2, grid);
                ans = max(ans, val);
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m - 1, grid);
    }
};
