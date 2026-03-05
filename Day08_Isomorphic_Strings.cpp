#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        char map_s1[128] = { 0 };
        char map_s2[128] = { 0 };
        
        if(s1.size() != s2.size())
            return false;
            
        int len = s1.size();
        
        for(int i = 0; i < len; i++)
        {
            if (map_s1[s1[i]] != map_s2[s2[i]])
                return false;
            
            map_s1[s1[i]] = i + 1;
            map_s2[s2[i]] = i + 1;
        }
        return true;
    }
};
