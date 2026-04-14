#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string removeSpaces(string& s) {
        int j = 0;  // write pointer

        for(int i = 0; i < s.length(); i++) 
        {
            if(s[i] != ' '){
                s[j] = s[i];
                j++;
            }
        }

        //resize the string to remove extra characters
        s.resize(j);
        return s;
    }
};
