#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }

        int total = sum + target;

        // If total is odd, no valid partition
        if (total % 2 != 0) {
            return 0;
        }

        int tar = total / 2;

        // If target becomes negative
        if (tar < 0) {
            return 0;
        }

        vector<int> dp(tar + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int s = tar; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[tar];
    }
};
