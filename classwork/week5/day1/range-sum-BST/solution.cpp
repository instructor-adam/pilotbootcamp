/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "base.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        /* Does not take advantage of BST properties. Skips no nodes
         * in it's search to see what is in the range of the sum.
         */
        int rangeSumBST_0(TreeNode* root, int L, int R) {
            if (root == NULL) { return 0; }
            if (root->val >= L && root->val <= R) { 
                return root->val + rangeSumBST_0(root->left, L, R) + 
                    rangeSumBST_0(root->right, L, R); 
            } else {
                return rangeSumBST_0(root->left, L, R) +
                    rangeSumBST_0(root->right, L, R); 
            }
        }

        int rangeSumBST_1(TreeNode* root, int L, int R) {
            if (root == NULL) { return 0; }
            if (root->val < L) { return rangeSumBST_1(root->right, L, R); }
            if (root->val > R) { return rangeSumBST_1(root->left, L, R); }
            return root->val + rangeSumBST_1(root->left, L, R) + rangeSumBST_1(root->right, L, R);
        }

        /* Slightly faster answer. I will change the bounds of the sum to
         * avoid possibly unncessary recursions.
         */
        int rangeSumBST_2(TreeNode* root, int L, int R) {
            if (root == NULL) { return 0; }
            if (L > R) { return 0; }
            if (root->val < L) { return rangeSumBST_2(root->right, max(L, root->val), R); }
            if (root->val > R) { return rangeSumBST_2(root->left, L, min(R, root->val)); }
            return root->val + 
                rangeSumBST_2(root->right, max(L, root->val), R) +
                rangeSumBST_2(root->left, L, min(R, root->val));
        }

        int rangeSumBST(TreeNode* root, int L, int R) {
            return rangeSumBST_1(root, L, R);
        }
};
