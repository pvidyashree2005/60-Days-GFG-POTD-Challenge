#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        queue<int> q;
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            // Remove flips whose effect is finished
            while(!q.empty() && i > q.front() + k - 1)
            {
                q.pop();
            }

            // Check current bit after flips
            if((arr[i] + q.size()) % 2 == 0)
            {
                if(i + k > n)
                    return -1;

                res++;
                q.push(i);
            }
        }

        return res;
    }
};
