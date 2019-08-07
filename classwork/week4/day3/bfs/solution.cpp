/*
Code for breadth-first-search
*/

#include "base.h"
#include <queue>
#include "tree.h"

class Solution {
    public:
        breadth_first_search(Binary_Tree* root) {
            queue<Binary_Tree*> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                auto node = nodes.pop();
                cout << node->value << endl;
                if (node->left != nullptr) {
                    nodes.push(node->left);
                }
                if (node->right != nullptr) {
                    nodes.push(node->right);
                }
            }
        }
};
