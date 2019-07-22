#include <iostream>
#include <unordered_set>

using namespace std;

/* Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting
with any positive integer, replace the number by the sum of the
squares of its digits, and repeat the process until the number equals
1 (where it will stay), or it loops endlessly in a cycle which does
not include 1. Those numbers for which this process ends in 1 are
happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

/* This is almost the same problem as finding if a list contains any
 * duplicates. The sequence is not in memory, but you do know how to
 * generate it: split the current number into it's individual digits,
 * sum up the squares of each digit.
 */
class Solution {
public:
    int nextElement(int n) {
        // while not a single digit number
        int squareDigitSum = 0;
        while (n >= 10) {
            int smallestDigit = n % 10;
            squareDigitSum += smallestDigit * smallestDigit;
            n /= 10;
        }

        squareDigitSum += n * n;
        return squareDigitSum;
    }
    bool isHappy(int n) {
        unordered_set<int> seenBefore;
        int current = n;
        seenBefore.insert(current);
        while (current != 1) {
            // If we've seen current before...
            if (seenBefore.count(current) == 1) {
                // because we found a cycle that will never hit the
                // value 1.
                return false;
            }
            current = nextElement(current);
            seenBefore.insert(current);
        }
        return true;
    }
};

int
main() {
    Solution s;
    int example = 2;
    while (example != 1) {
        cout << example << ", ";
        example = s.nextElement(example);
    }
    cout << 
}
