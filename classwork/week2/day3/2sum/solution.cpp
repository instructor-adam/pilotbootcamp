#include "base.h"

class Solution {
    /* The hash tables method */
    bool pair_sums_to_target_0(vector<int> list, int target) {
        unordered_set<int> numbers;
        for (int i : list) {
            numbers.insert(i);
        }

        for (int i : list) {
            /* i + (target - i) = target */
            if (numbers.count(target - i) > 0) {
                return true;
            } 
        }

        /* No pair was found. */
        return false;
    }
    /* The nested loops method. */
    bool pair_sums_to_target_1(vector<int> list, int target) {
        for (int i = 0; i < list.size() - 1; i++) {
            /* We can view this loop as the lookup step to find an
             * appropriate 2nd member of a pair containing list[i].
             * The worst-case time for this loop is list.size() - j:
             * when no member exists such that list[i] + list[j] =
             * target.
             */
            for(int j = i + 1; j < list.size(); j++) {
                if (list[i] + list[j] == target) return true;
            }
        }

        return false;
    }
    /* Hash tables method with best-case constant time */
    bool pair_sums_to_target_2(vector<int> list, int target) {
        unordered_set<int> numbers;
        for (int i : list) {
            /* i + (target - i) = target */
            if (numbers.count(target - i) > 0) {
                return true;
            } else {
                numbers.insert(i);
            }
        }

        /* No pair was found. */
        return false;
    }
    /* The sorted lists method. If the list is already sorted then the
     * time complexity of this approach is O(n). If the list is not
     * already sorted, then the time complexity is O(n) + time to sort
     * the list which is usually O(n log n).
     */
    bool pair_sums_to_target_3(vector<int> list, int target) {
        sort(list.begin(), list.end());
        int begin = list.begin(), end = list.end() - 1;
        while (begin != end) {
            int sum = *begin + *end;
            if (sum == target) return true;
            else if (sum < target) begin++;
            else end--;
        }

        return false;
    }
};
