#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {

        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
        
        // Build prefix sum matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i+1][j+1] = mat[i][j]+ prefix[i][j+1]+ prefix[i+1][j]- prefix[i][j];
            }
        }
        
        int count = 0;
        
        // Try all square sizes
        for (int size = 1; size <= min(n, m); size++) {
            for (int i = 0; i <= n - size; i++) {
                for (int j = 0; j <= m - size; j++) {
                    
                    int total = prefix[i+size][j+size]- prefix[i][j+size]- prefix[i+size][j]+ prefix[i][j];
                    
                    if (total == x) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
