/*
Given a sorted array, remove all the duplicate entries from the array.

each entry in array is guaranteed to be between $-10^5$ and $10^5$

```
Examples:
    input: [0, 0, 1, 1]
    output: [0, 1]

    input: [1, 2, 3]
    output: [1, 2, 3]

    input: [0, 1, 1, 2, 3, 3, 4, 4, 4, 5]
    output: [0, 1, 2, 3, 4, 5]
```
*/

#include "base.h"

class Solution {
    public:
        void remove_duplicates_0(vector<int>& numbers) {
            /* This is the exclusive end of a starting subarray of
             * numbers which contains no duplicates.
             */
            int noDupesEnd = 1;
            int i = 1;
            for (int i = 1; i < numbers.size(); i++) {
                if (numbers[i] != numbers[noDupesEnd - 1]) {
                    numbers[noDupesEnd] = numbers[i];
                    noDupesEnd++;
                }
            }

            numbers.resize(noDupesEnd);
        }

        void remove_duplicates_1(vector<int>& numbers) {
            vector<int> new_numbers {numbers[0]};
            for (int i : numbers) {
                if (i != new_numbers.back()) new_numbers.push_back(i);
            }
            numbers = new_numbers;
        }

        void remove_duplicates(vector<int>& numbers) {
            remove_duplicates_0(numbers);
        }
};

