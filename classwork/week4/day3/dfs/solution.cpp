/*
Code for a depth first search of a tree
*/

#include "base.h"
#include "tree.h"
#include <stack>

class Solution {
    public:
        void depth_first_search_recursive(Binary_Tree* root) {
            if (root == nullptr) { return; }
            else {
                cout << root->value << endl;
                depth_first_search_recursive(root->left);
                depth_first_search_recursive(root->right);
            }
        }

        void depth_first_search_iterative(Binary_Tree* root) {
            if (root == nullptr) { return; }
            stack<Binary_Tree*> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                auto node = nodes.top();
                nodes.pop();
                cout << node->value << endl;
                /* We want to visit the left child first, so we push
                 * it last so it is at the top of the stack of nodes
                 * to visit.
                 */
                if (node->right != nullptr) {
                    nodes.push(node->right);
                }
                if (node->left != nullptr) {
                    nodes.push(node->left);
                }
            }
        }
};
