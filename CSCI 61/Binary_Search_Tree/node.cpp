#include "node.h"
#include <string>
//CONSTRUCTOR
node::node(const int & init_data, node * right, node * left){
    _data = init_data;
    _right_link = right;
    _left_link = left;
}

void node::set_left_link(node * link){
    _left_link = link;
}

void node::set_right_link(node * link){
    _right_link = link;
}

void node::set_value(int value){
    _data = value;
}
