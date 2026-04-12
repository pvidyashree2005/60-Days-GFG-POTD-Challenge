#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitz(vector<vector<int>>& mat) {
        
        int n = mat.size();        // No. of rows
        int m = mat[0].size();    // No. of columns

        for(int i = 0; i < n - 1; i++) 
        { 
            for(int j = 0; j < m - 1; j++) 
            {
                if(mat[i][j] != mat[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
