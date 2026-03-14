#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        unordered_map<int, int> mp;
        queue<pair<Node*, int>> q;

        int minHD = 0, maxHD = 0;

        q.push({root, 0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            if(mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);

            if(node->left)
                q.push({node->left, hd - 1});

            if(node->right)
                q.push({node->right, hd + 1});
        }

        for(int i = minHD; i <= maxHD; i++) {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};

