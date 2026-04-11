#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;

        int answer = 0;
        int count = 1;

        for (int i = 1; i < n; i++) 
        {
            if (arr[i] > arr[i - 1]) {
                count++;
            } 
            else {
                //Process previous segment by applying formula
                answer += (count * (count - 1)) / 2;
                count = 1;
            }
        }

        //Last segment
        answer += (count * (count - 1)) / 2;
        return answer;
    }
};
