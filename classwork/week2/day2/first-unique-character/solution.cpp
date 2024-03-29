/* Given a string, find the first non-repeating character in it and
 * return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int first_unique_character(string s) {
    unordered_map<char, int> histogram;
    for (char c : s) { histogram[c]++; }
    for (int i = 0; i < s.size(); i++) {
        if (histogram[s[i]] == 1) { return i; }
    }

    return -1;
}
