/*
 * Complete the 'linked_list_pivot' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST lst
 *  2. INTEGER key
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

/*
For any integer $k$, the pivot of a list of integers with respect to $k$
is that list with its nodes reordered so that all nodes containing
keys less than $k$ appear before nodes containing $k$, and all nodes
containing keys greater than $k$ appear after nodes containing $k$. 

**The relative ordering of nodes that appear before $k$ and after $k$
must remain unchanged**; the same must hold for nodes holding keys
equal to $k$. 

NOTE: With a linked list, you can identify relative order of nodes
with the same value because each node has a pointer in memory; you can
tell the different nodes apart.

Examples
```
lst: 5 -> 4 -> 3 -> 2 -> 1
key: 3
output: 2 -> 1 -> 3 -> 5 -> 4
NOTE: the output 1 -> 2 -> 3 -> 4 -> 5 would be wrong

lst: 1 -> 2 -> 3 -> 4 -> 3 -> 4 -> 8 -> 5 -> 6
key: 4
output: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 8 -> 5 -> 6
NOTE: Careful about the relative positioning of the 2 nodes with value
3. You HAVE to have the first 3 in the list come before the 2nd 3 in
the list.

lst: 1, 2, 3, 4, 3, 4, 8, 5, 6, 
key: 3
output: 2 -> 1 -> 3 -> 5 -> 4
NOTE: the output 1 -> 2 -> 3 -> 4 -> 5 would be wrong
```
*/

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

#include "base.h"

class Solution {
    public:
    SinglyLinkedListNode* linked_list_pivot(SinglyLinkedListNode* lst, int key) {
        // Pointers for maintining 3 different lists Using dummy heads.
        SinglyLinkedListNode* ltHead = new SinglyLinkedListNode(0);
        SinglyLinkedListNode* eqHead = new SinglyLinkedListNode(0);
        SinglyLinkedListNode* gtHead = new SinglyLinkedListNode(0);
        SinglyLinkedListNode* ltIter = ltHead;
        SinglyLinkedListNode* eqIter = eqHead;
        SinglyLinkedListNode* gtIter = gtHead;

        SinglyLinkedListNode* current = lst;
        while (current) {
            SinglyLinkedListNode* next = current->next;
            if (current->data < key) {
                ltIter->next = current;
                ltIter = ltIter->next;
            } else if (current->data > key) {
                gtIter->next = current;
                gtIter = gtIter->next;
            } else {
                eqIter->next = current;
                eqIter = eqIter->next;
            }
            current = next;
        }

        gtIter->next = nullptr;
        ltIter->next = eqHead->next;
        eqIter->next = gtHead->next;
        SinglyLinkedListNode* head = ltHead->next;

        delete ltHead;
        delete eqHead;
        delete gtHead;

        return head;
    }
};

