#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};

        int smallest = INT_MAX, middle = INT_MAX;
        int candidate_smallest = INT_MAX;

        for (int i = 0; i < n; i++) 
        {
            if (arr[i] <= candidate_smallest) {
                candidate_smallest = arr[i];
            }
            else if (arr[i] <= middle) {
                smallest = candidate_smallest;
                middle = arr[i];
            }
            else {
                return {smallest, middle, arr[i]};
            }
        }

        return {};
    }
};
