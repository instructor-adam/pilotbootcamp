/* EOPI problem 6.5
Implement a function which takes as input an array and a key, and
updates the array so that all occurrences of the input key have been
removed and the remaining elements have been shifted left to fill the
emptied indices. Return the number of remaining elements. There are no
requirements as to the values stored beyond the last valid element.

Examples:
input: [0, 1, 1, 2, 3], 1
output: [0, 2, 3]
*/

class Solution {
    /* Returns true if found and removed element. Returns false
     * otherwise. Modifies the lst to remove the 1st ocurrence of key
     * shifting elements left as needed.
     */
    bool remove_single(vector<int>& lst, int key) {
        for (int i = 0; i < lst.size() - 1; i++) {
            if (lst[i] == key) {
                // Shift left.
                for (int j = i + 1; j < lst.size(); j++) {
                    lst[j - 1] = lst[j];
                }
                lst.resize(lst.size() - 1);
                return true;
            }
        }

        // If the last element is the earliest occurrence of the key,
        // then remove it by resizing the list.
        if (lst.back() == key) {
            lst.resize(lst.size() - 1);
            return true;
        }

        return false;
        // In case the last element of the l
    }
    /* Just keep removing elements from the array. */
    int remove_0(vector<int>& lst, int key) {
        while (remove_single(lst, key)) {}
        return lst.size();
    }
    /* Remove in bulk. 
    int remove_1(vector<int>& lst, int key) {
    }
    */
};
