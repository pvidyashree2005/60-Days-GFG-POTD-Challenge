#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Binary Tree Node
/*struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
public:

    void solve(Node* root, long long currSum, int k, int &count,
               unordered_map<long long,int> &mp) {

        if(root == NULL) return;

        currSum += root->data;

        if(mp.find(currSum - k) != mp.end()) {
            count += mp[currSum - k];
        }

        mp[currSum]++;

        solve(root->left, currSum, k, count, mp);
        solve(root->right, currSum, k, count, mp);

        // Backtrack
        mp[currSum]--;
    }

    int countAllPaths(Node *root, int k) {

        unordered_map<long long,int> mp;
        mp[0] = 1;

        int count = 0;

        solve(root, 0, k, count, mp);

        return count;
    }
};
