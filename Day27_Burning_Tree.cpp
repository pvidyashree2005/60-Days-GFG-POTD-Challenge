#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Tree Node Definition
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
public:

    // Create parent mapping + find target node
    Node* findTargetAndParent(Node* root, unordered_map<Node*, Node*>& parent, int target) {
        
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target)
                targetNode = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    int minTime(Node* root, int target) {

        unordered_map<Node*, Node*> parent;

        // Step 1: Get target node + parent mapping
        Node* targetNode = findTargetAndParent(root, parent, target);

        // Step 2: BFS to simulate burning
        queue<Node*> q;
        unordered_map<Node*, bool> visited;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool isBurning = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // Left
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    isBurning = true;
                }

                // Right
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    isBurning = true;
                }

                // Parent
                if (parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                    isBurning = true;
                }
            }

            if (isBurning) time++;
        }

        return time;
    }
};
