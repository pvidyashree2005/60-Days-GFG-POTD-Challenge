#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        
        int n = arr1.size();
        int m = arr2.size();
        
        vector<int> ans;
        
        int start = 0, end = m - 1;
        int element1 = INT_MIN;
        int element2 = INT_MIN;
        int closestDiff = INT_MAX;
        
        while(start < n && end >= 0) {
            
            int sum = arr1[start] + arr2[end];
            int absDiff = abs(sum - x);
            
            if(absDiff < closestDiff) {
                closestDiff = absDiff;
                element1 = arr1[start];
                element2 = arr2[end];
            }
            
            if(sum > x) {
                end--;
            }
            else {
                start++;
            }
        }
        
        ans.push_back(element1);
        ans.push_back(element2);
        
        return ans;
    }
};
