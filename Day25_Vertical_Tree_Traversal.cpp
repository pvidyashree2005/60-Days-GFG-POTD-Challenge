#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure of a tree node
/* struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:

    vector<vector<int>> verticalOrder(Node *root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        // map to store nodes at each horizontal distance
        unordered_map<int, vector<int>> mp;

        // queue for BFS traversal (node, horizontal distance)
        queue<pair<Node*, int>> q;

        int minHD = 0, maxHD = 0;

        // push root with horizontal distance 0
        q.push({root, 0});

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            // store node data in map
            mp[hd].push_back(node->data);

            // update minimum and maximum HD
            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);

            // push left child with hd - 1
            if(node->left)
                q.push({node->left, hd - 1});

            // push right child with hd + 1
            if(node->right)
                q.push({node->right, hd + 1});
        }

        // collect results from leftmost HD to rightmost HD
        for(int i = minHD; i <= maxHD; i++) {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};
