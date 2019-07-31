#include "base.h"

class Node {
public:
    int value;
    Node* next;
};

class Solution {
    /* Just keep removing elements from the array. */
    int remove_0(Node* head, int key) {
        auto dummy_head = new Node(0, head);
        auto predecessor = dummy_head;
        auto current = head;
        while (current != NULL) {
            if (current->value == key) {
                Node* the_next = current->next;
                predecessor->next = the_next;
                delete current;
                current = the_next;
            } else {
                predecessor = predecessor->next;
                current = current->next
            }
        }
        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};
