class Node {
public:
    int value;
    Node* next;
};

class Solution {
    Node* reverse_sublist(Node* L, int start, int finish) {
        if (start == finish) {
            return L;
        }

        Node* dummy_head = new Node(0, L);
        auto sublist_head = dummy_head;
        int k = 1;
        while (k++ < start) {
            sublist_head = sublist_head->next;
        }

        auto sublist_iter = sublist_head->next;
        while (start++ < finish) {
            auto temp = sublist_iter->next;
            sublist_iter->next = temp->next;
            temp->next = sublist_head->next;
            sublist_head->next = temp;
        }

        return dummy_head->next;
    }

    /* The head node is node 0, start is inclusive, start is
     * exclusive.
    void reverse_list_range(Node* head, int start, int end) {
        // Nothing to reverse.
        if (start == end) {
            return;
        }
        int index = 0;
        Node* current = head;
        while (index < start) {
            index++;
            current = current->next;
        }
        Node* section_head = new Node(0, NULL);
        Node* first = new Node(current->value, NULL);
        Node* section_tail = first;
        index++;
        current = current->next;
        while (index < end) {
            Node* new_entry = new Node(current->value, 
                    reversed_section_head->next)
        }
    }
    */
};
