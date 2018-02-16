#ifndef NODE_H
#define NODE_H

class node
{
public:
    //CONSTRUCTOR
    node(const int & init_data, node * right = nullptr, node * left = nullptr);

    //MODIFIERS
    bool erase_one(node *, int);
    void set_left_link(node *);
    void set_right_link(node *);
    void set_value(int);

    //CONSTANTS
    int data() const {return _data;}
    node * left() const {return _left_link;}
    node * right() const {return _right_link;}
    bool is_leaf() const {return left() == nullptr && right() == nullptr;}
private:
    int _data;
    node * _left_link;
    node * _right_link;
};

    int left_subtree_value(node);
    int right_subtree_value(node);

#endif // NODE_H
