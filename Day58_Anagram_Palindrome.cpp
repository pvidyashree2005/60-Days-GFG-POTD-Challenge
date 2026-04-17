#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canFormPalindrome(string s) {
        int freq[26] = {0};

        // Step 1: Count frequency
        for(char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Count odd frequencies
        int oddCount = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0) {
                oddCount++;
            }
        }

        // Step 3: Check condition
        return oddCount <= 1;
    }
};
