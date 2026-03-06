#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string &s, string &p) {

        if (p.length() > s.length())
            return "";

        int n = s.length(), m = p.length();
        int start = -1, end = -1;
        int len = INT_MAX, c1 = 0, c2 = 0, j = 0;

        vector<int> arrS(26, 0);
        vector<int> arrP(26, 0);

        for (int i = 0; i < m; i++) {
            arrP[p[i] - 'a']++;
            if (arrP[p[i] - 'a'] == 1)
                c1++;
        }

        for (int i = 0; i < n; i++) {

            arrS[s[i] - 'a']++;

            if (arrS[s[i] - 'a'] == arrP[s[i] - 'a'])
                c2++;

            if (c2 == c1) {

                while (arrS[s[j] - 'a'] > arrP[s[j] - 'a']) {
                    arrS[s[j] - 'a']--;
                    j++;
                }

                if (len > i - j + 1) {
                    start = j;
                    end = i;
                    len = i - j + 1;
                }
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, len);
    }
};
