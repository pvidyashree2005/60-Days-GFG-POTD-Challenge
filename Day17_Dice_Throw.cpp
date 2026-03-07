#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int noOfWays(int m, int n, int x) {
        
        vector<int> dp(x + 1, 0);
        dp[0] = 1;   // base case

        for(int dice = 1; dice <= n; dice++) 
        {
            vector<int> temp(x + 1, 0);

            for(int sum = 1; sum <= x; sum++) 
            {
                for(int face = 1; face <= m; face++) 
                {
                    if(sum - face >= 0) 
                    {
                        temp[sum] += dp[sum - face];
                    }
                }
            }

            dp = temp;
        }

        return dp[x];
    }
};
