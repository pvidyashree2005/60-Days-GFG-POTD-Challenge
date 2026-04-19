#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPower(int x, int y) {
        // Special cases
        if (x == 1) return (y == 1);
        if (y == 1) return true;
        if (x == 0) return false;

        // Compute logarithm
        double k = log(y) / log(x);

        // Check if k is an integer (handle precision)
        return fabs(k - round(k)) < 1e-10;
    }
};
