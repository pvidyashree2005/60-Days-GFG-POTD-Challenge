#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        
        vector<int> freq(26, 0);   // fixed size array
        int unique = 0, maxlen = -1;

        for(int i = 0, j = 0; j < s.size(); j++){
            freq[s[j] - 'a']++;

            if(freq[s[j] - 'a'] == 1)
                unique++;

            while(unique > k){
                freq[s[i] - 'a']--;

                if(freq[s[i] - 'a'] == 0)
                    unique--;

                i++;
            }

            if(unique == k)
                maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};
