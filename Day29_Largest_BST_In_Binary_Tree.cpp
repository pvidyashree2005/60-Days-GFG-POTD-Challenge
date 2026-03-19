#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

/* Tree node structure */
/* struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
public:

    struct Info {
        int size;
        int minVal;
        int maxVal;
        bool isBST;

        Info(int s, int mn, int mx, bool bst) {
            size = s;
            minVal = mn;
            maxVal = mx;
            isBST = bst;
        }
    };

    Info solve(Node* root, int &maxSize) {
        if (!root) {
            return Info(0, INT_MAX, INT_MIN, true);
        }

        Info left = solve(root->left, maxSize);
        Info right = solve(root->right, maxSize);

        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {

            int currSize = left.size + right.size + 1;
            maxSize = max(maxSize, currSize);

            return Info(
                currSize,
                min(root->data, left.minVal),
                max(root->data, right.maxVal),
                true
            );
        }

        return Info(0, INT_MIN, INT_MAX, false);
    }

    int largestBst(Node *root) {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};

