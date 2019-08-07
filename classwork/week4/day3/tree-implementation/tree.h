#ifndef TREE__H
#define TREE__H
class Binary_Tree {
public:
    int value;
    Binary_Tree* left;
    Binary_Tree* right;
    Binary_Tree(int v, Binary_Tree* left = nullptr, Binary_Tree* right = nullptr)
        : value(v), left(left), right(right) {}
};

#endif

