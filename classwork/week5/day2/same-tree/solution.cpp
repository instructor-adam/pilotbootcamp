/*
A solution file template.
*/

#include "base.h"
#include "tree.h"
#include <queue>

class Solution {
    public:
    /* The recursive solution. This comes from a recursive definition
     * of sameness.
     * - The empty tree is the same as itself. We use a null pointer
     *   (NULL) to represent the empty tree.
     * - The empty tree is not equal to any other tree.
     * - Otherwise, two trees are equal if their roots have the same
     *   value and their two left subtrees are equal and their two
     *   right subtrees are equal.
     */
    bool isSameTree_0(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        } else if (p->val != q->val) {
            return false;
        }
        return isSameTree_0(p->left, q->left) &&
            isSameTree_0(p->right, q->right);
    }

    /* We could probably use a BFS here with an invariant.
     * Perhaps our invariant is that two trees are equal if and only
     * if all the corresponding trees in two BFS queues are equal at
     * the start of every iteration.
     * Start: Trivially true, the BFS queues start with the two trees
     * to compare.
     * Maintenance: Suppose we start with the two queues and the
     * property holds for them. Then we have to show that what we do
     * during the loop maintains the invariant.
     * - If the first trees in each queue have diff values, then
     *   those trees aren't equal. Thus the original trees weren't
     *   equal.
     * - If the first trees in each queue have the same value, then
     *   they must have the same # of children in the same posn to be
     *   equal (both one left, both one right, or two children).
     * - If the children of the first trees in each queue are also
     *   equal, and all of the rest of the trees in the queue are
     *   equal, then the two original trees should be equal.
     * Termination: The queue is empty. All of the trees that were
     * ever in the two queues were equal to one another.
     */
    bool isSameTree_1(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        }

        queue<TreeNode*> bfsp;
        queue<TreeNode*> bfsq;
        bfsp.push(p);
        bfsq.push(q);

        while (!bfsp.empty() && !bfsq.empty()) {
            auto nodep = bfsp.front();
            auto nodeq = bfsq.front();
            bfsp.pop();
            bfsq.pop();

            if (nodep->val != nodeq->val) {
                return false;
            } else if (nodep->left == NULL && nodeq->left != NULL) {
                return false;
            } else if (nodep->left != NULL && nodeq->left == NULL) {
                return false;
            } else if (nodep->right == NULL && nodeq->right != NULL) {
                return false;
            } else if (nodep->right != NULL && nodeq->right == NULL) {
                return false;
            }

            if (nodep->left != NULL) {
                bfsp.push(nodep->left);
            }
            if (nodep->right != NULL) {
                bfsp.push(nodep->right);
            }
            if (nodeq->left != NULL) {
                bfsq.push(nodeq->left);
            }
            if (nodeq->right != NULL) {
                bfsq.push(nodeq->right);
            }
        }

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTree_0(p, q);
    }
};
