#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> graycode(int n) {
        vector<string> ans;
        
        for(int i = 0; i < (1 << n); i++) {
            int gray = i ^ (i >> 1);
            
            string s = "";
            for(int j = n - 1; j >= 0; j--) {
                if(gray & (1 << j)) s += '1';
                else s += '0';
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};
