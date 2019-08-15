/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes'
values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Accepted
*/

#include "base.h"
#include "tree.h"

class Solution {
    public:
        /* A solution that just modifies BFS while keeping track of
         * the level of each node in the traversal.
         */
        vector<vector<int>> levelOrder_0(TreeNode* root) {
            /* This queue will be used to do a BFS traversal of the
             * tree. Each time we explore a node, we will put it in
             * the right array in our answers 2d array.
             */
            if (root == NULL) { return {}; }
            queue<pair<TreeNode*, int>> nodesAndLevels;
            vector<vector<int>> answers;
            nodesAndLevels.push({root, 0});
            while(!nodesAndLevels.empty()) {
                auto toExplore = nodesAndLevels.front();
                TreeNode* current = toExplore.first;
                int currentLevel = toExplore.second;
                nodesAndLevels.pop();
                /* When you explore a node, place it in the correct
                 * level
                 */
                if (answers.size() == currentLevel) {
                    answers.push_back({current->val});
                } else {
                    answers[currentLevel].push_back(current->val);
                }
                /* Otherwise, perform a BFS. Just place the nodes on
                 * the queue as you would in a BFS
                 */
                if (current->left != NULL) {
                    nodesAndLevels.push({current->left, currentLevel + 1});
                }
                if (current->right != NULL) {
                    nodesAndLevels.push({current->right, currentLevel + 1});
                }
            }

            return answers;
        }

        /* A recursive method to do a level order traversal.
         * Base Case: An empty tree has no 'levels'. It's level order
         * traversal is the empty list [].
         * Inductive Step: Suppose we had a non empty tree. It's root
         * would be the one node in the 1st level (depth 0). Each of
         * its children subtrees would have a level order traversal we
         * could get. The depths of each level would match up
         * completely, except when one tree is deeper than another. In
         * this case, we can consider the corresponding levels for the
         * shorter tree as being empty.
         *
         * Anyhow, the correct level order traversal for the deeper
         * levels would be the concatenation of the corresponding
         * levels in each tree.
         */
        vector<vector<int>> levelOrder_1(TreeNode* root) {
            if (root == NULL) {
                return {};
            } else {
                auto left_order = levelOrder_1(root->left);
                auto right_order = levelOrder_1(root->right);
                auto lit = left_order.begin();
                auto rit = right_order.begin();
                auto shorter = left_order.size() > right_order.size() ?
                    right_order.size() : left_order.size();
                int i = 0;
                while (i < shorter) {
                    left_order[i].insert(left_order[i].end(),
                            right_order[i].begin(),
                            right_order[i].end());
                    i++;
                }
                if (right_order.size() > left_order.size()) {
                    left_order.insert(left_order.end(),
                            right_order.begin() + i,
                            right_order.end());
                }
                left_order.insert(left_order.begin(), {root->val});
                return left_order;
            }
        }

        vector<vector<int>> levelOrder(TreeNode* root) {
            return levelOrder_1(root);
        }

        /* You can also avoid keeping level as a number altogether.
         * Just build the level order traversal one level at a time.
         * Start with the 1st level, and note that the 2nd level is
         * all the children of the 1st level, and 3rd level is all the
         * children of the 2nd level, and so on.
         *
         * TODO: finish approach.
        vector<vector<int>> levelOrder_1(TreeNode* root) {
            if (root == NULL) { return {}; }
            vector<vector<TreeNode*>> LOTnodes;
            vector<vector<int>> LOT;
        }
         */

};
