#include "base.h"

class Solution {
    /* Creates a reversed copy. */
    vector<int> reverse_0(vector<int>& lst) {
        vector<int> reversed;
        reversed.resize(lst.size());
        for (int i = 0; i < lst.size(); i++) {
            reversed[lst.size() - i - 1] = lst[i];
        }

        return reversed;
    }

    /* Reverses in-place. No new list created. 
     * This method puts the two outer-most elements in their correct
     * place, and then proceeds to reverse lst[1 .. -1]*/
    void reverse_1(vector<int>& lst) {
        for (int i = 0; i < lst.size() / 2; i++) {
            swap(lst[i], lst[lst.size() - i - 1]);
        }
    }
};
