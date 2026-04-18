#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {  
public:  
    int maxOnes(vector<int>& arr) {  
        int totalOnes = 0;
        
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }

        int maxGain = 0, currGain = 0;

        for (int x : arr) {
            int val = (x == 0) ? 1 : -1;

            currGain = max(val, currGain + val);
            maxGain = max(maxGain, currGain);
        }

        return totalOnes + maxGain;
    }  
};
