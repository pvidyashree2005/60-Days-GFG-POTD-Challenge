#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<long long> fact, invFact;

    // Fast exponentiation
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    // Precompute factorials and inverse factorials
    void init(int n) {
        fact.resize(2*n + 1);
        invFact.resize(2*n + 1);

        fact[0] = 1;
        for (int i = 1; i <= 2*n; i++)
            fact[i] = (fact[i-1] * i) % MOD;

        invFact[2*n] = power(fact[2*n], MOD - 2);
        for (int i = 2*n - 1; i >= 0; i--)
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }

    // nCr function
    long long nCr(int n, int r) {
        if (r > n || r < 0) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    // Catalan using formula
    long long catalan(int n) {
        return (nCr(2*n, n) * power(n+1, MOD-2)) % MOD;
    }

    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();

        init(n);

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        vector<int> result;

        for (int i = 0; i < n; i++) {
            int L = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
            int R = n - L - 1;

            long long ways = (catalan(L) * catalan(R)) % MOD;
            result.push_back((int)ways);
        }

        return result;
    }
};
