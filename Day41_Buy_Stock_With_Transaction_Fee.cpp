#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        int buy = -1 * arr[0];
        int sell = 0;
        
        for(int i = 1; i < n; i++)
        {
            //Buy State
            int newBuy = max(buy, sell - arr[i]);

            //Sell State
            int newSell = max(sell, buy + arr[i] - k);

            buy = newBuy;
            sell = newSell;
        }

        return sell;
    }
};
