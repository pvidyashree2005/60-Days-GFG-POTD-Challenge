#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestSwap(string &s) {
        int last[10] = {0};
        int n = s.size();

        // Store last occurrence of each digit
        for(int i = 0; i < n; i++) 
        {
            last[s[i] - '0'] = i;
        }

        // Try to swap with a larger digit on the right
        for(int i = 0; i < n; i++) 
        {
            for(int d = 9; d > s[i] - '0'; d--) 
            {
                if(last[d] > i) 
                {
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }

        return s;
    }
};