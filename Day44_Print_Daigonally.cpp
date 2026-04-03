#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        
        // Create diagonals (i + j ranges from 0 to 2*n-2)
        vector<vector<int>> diag(2*n - 1);
        
        // Fill diagonals
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                diag[i + j].push_back(mat[i][j]);
            }
        }
        
        // Store final answer
        vector<int> ans;
        for(auto &d : diag) {
            for(auto &val : d) {
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};
