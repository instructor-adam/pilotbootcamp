#include <iostream>
#include <unordered_set>
#include <list>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenSoFar;
        for (int i : nums) {
            if (seenSoFar.count(i) == 1) {
                return true;
            }
            seenSoFar.insert(i);
        }

        return false;
    }
};

// Just for printing out vectors.
template<typename T>
ostream& operator<<(ostream& o, vector<T> v) {
    if (v.size() == 0) {
        return o << "[]";
    } else if (v.size() == 1) {
        return o << "[" << v[0] << "]";
    } else {
        auto start = v.begin();
        o << "[" << *start;
        start++;
        while(start != v.end()) {
            o << ", " << *start;
            start++;
        }
        return o << "]";
    }
}

int
main() {
    using Input = vector<int>;
    using Output = bool;
    list<pair<Input, Output>> examples {
        {{}, false},
        {{0}, false},
        {{1, 3, 5}, false},
        {{1, 1}, true},
        {{1, 1, 2, 4, 3, 5}, true},
        {{1, 5, 4, 3, 2, 1}, true},
    };
    Solution s;
    for (pair<Input, Output> example : examples) {
        Input input = example.first;
        Output expected = example.second;
        Output actual = s.containsDuplicate(input);
        if (expected == actual) {
            cout << "case: " << input << "| output: " << actual << endl;
        } else {
            cout << "case: " << input << "| output: " << actual 
                << "| expected: " << expected << endl;
        }
    }
}
