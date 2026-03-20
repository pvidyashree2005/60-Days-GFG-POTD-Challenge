#include <iostream>
#include <vector>
using namespace std;

/* BST Node */
/* class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = NULL;
        Node* succ = NULL;

        Node* cur = root;

        while (cur != NULL) {
            if (key < cur->data) {
                succ = cur;
                cur = cur->left;
            }
            else if (key > cur->data) {
                pred = cur;
                cur = cur->right;
            }
            else {
                // predecessor
                if (cur->left != NULL) {
                    Node* temp = cur->left;
                    while (temp->right != NULL)
                        temp = temp->right;
                    pred = temp;
                }

                // successor
                if (cur->right != NULL) {
                    Node* temp = cur->right;
                    while (temp->left != NULL)
                        temp = temp->left;
                    succ = temp;
                }
                break;
            }
        }

        vector<Node*> res;
        res.push_back(pred);
        res.push_back(succ);
        return res;
    }
};

