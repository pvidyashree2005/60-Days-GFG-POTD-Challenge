#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        
        int n = arr.size();
        int max_val = 0;

        // Find maximum element in array
        for(int i = 0; i < n; i++){
            if(arr[i] > max_val)
                max_val = arr[i];
        }

        // Create frequency array
        vector<bool> present(max_val + 1, false);

        // Mark elements present
        for(int i = 0; i < n; i++){
            present[arr[i]] = true;
        }

        // Check all possible pairs (a, b)
        for(int a = 1; a <= max_val; a++){

            if(!present[a]) continue;

            for(int b = a; b <= max_val; b++){

                if(!present[b]) continue;

                int c = sqrt(a*a + b*b);

                if(c <= max_val && c*c == (a*a + b*b) && present[c])
                    return true;
            }
        }

        return false;
    }
};

