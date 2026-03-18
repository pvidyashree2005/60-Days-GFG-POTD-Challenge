#include <iostream>
#include <queue>
#include <sstream>
#include <cmath>
using namespace std;

// Tree Node
/* struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

// Solution Class
class Solution {
    int ans;
public:
    int distCandy(Node* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    int dfs(Node* root) {
        if (root == nullptr)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        ans += abs(l) + abs(r);

        return root->data + l + r - 1;
    }
};
