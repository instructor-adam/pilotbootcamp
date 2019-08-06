/*
NestedInteger use examples:

Example: test = 5
NestedInteger test1(5);
// or
NestedInteger test2;
test.setInteger(5);

Example: test = []
NestedInteger test;

Example: test = [1]
NestedInteger test;
test.add(1);

Example: test = [1, 2, 3]
NestedInteger test;
test.add(1);
test.add(2);
test.add(3);

Example: test = [1, 2, 3, [4, 5], 6]
NestedInteger test;
test.add(1); // [1]
test.add(2); // [1, 2]
test.add(3); // [1, 2, 3]
NestedInteger nested;
nested.add(4); // [4]
nested.add(5); // [4, 5]
test.add(nested); // [1, 2, 3, [4, 5]]  
test.add(6); // [1, 2, 3, [4, 5], 6]

*/

// A possible implementation:
class NestedInteger {
    int * integer = nullptr;
    int * vector<NestedInteger> lst = nullptr;
    public:
    // Constructor initializes an empty nested list.
    NestedInteger() {
        lst = new vector<NestedInteger>;
    }

    // Constructor initializes a single integer.
    NestedInteger(int value) {
        integer = new int;
        *integer = value;
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return *integer;
    }
 
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        if (lst != nullptr) {
            delete lst;
            lst = nullptr;
        }
        if (integer == nullptr) {
            integer = new int;
        }
        *integer = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        if (integer != nullptr) {
            delete integer;
            integer = nullptr;
        }
        if (lst == nullptr) {
            lst = new vector<NestedInteger>;
        }
        lst.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        const vector<NestedInteger>& result = *lst;
        return result;
    }
};

};
