#ifndef BINTREE_H
#define BINTREE_H
#include <string>

class binTree
{
public:

    // pre: none
    // post: creates a new binTree node with given data and link values
    //       defaults: 0 and nullptr
    binTree(const std::string &, binTree * left = nullptr, binTree * right = nullptr);

    // pre: none
    // post: returns data value stored in this binTree
    std::string data() const;

    // pre: none
    // post: returns link value stored in this binTree
    binTree * left_link();
    binTree * right_link();
    const binTree * left_link() const;
    const binTree * right_link() const;

    // pre: none
    // post: sets the data field to given value
    void set_data(const std::string &);

    // pre: none
    // post: sets the link field to given value
    void set_left_link(binTree *);
    void set_right_link(binTree *);

    // pre: target value to remove
    // post: returns 0 if value not found returns 1 if value found and erased
    bool erase_one(std::string, binTree *);

    //pre: takes in ptr to left child of node
    //post: returns value of last node on left most subtree
    std::string left_subtree_value(binTree link);

    // pre: takes in ptr to right child of node
    //post: returns value of last node on right most subtree
    std::string right_subtree_value(binTree link);

    //CONSTANT
    bool is_leaf() const {return (_left_link == nullptr) && (_right_link == nullptr);}

private:
    std::string _data;
    binTree *   _left_link;
    binTree *   _right_link;
    // invariants:
    //  _data holds the data value stored in this binTree
    //  _link holds the address of the next binTree
};
void print(binTree * root);
void preorder(binTree * root);

#endif // BINTREE_H
