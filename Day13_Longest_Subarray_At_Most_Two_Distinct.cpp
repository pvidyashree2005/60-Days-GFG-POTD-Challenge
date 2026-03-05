#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int i = 0, j = 0;
        int result = 0;
        
        while (j < n) {
            mp[arr[j]]++;
            
            // If more than 2 distinct elements, shrink window
            while (mp.size() > 2) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }
            
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};
