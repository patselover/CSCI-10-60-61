#include "bintree.h"
#include <string>
#include <iostream>
binTree::binTree(const std::string & init_data,
                 binTree * left, binTree * right)
{
    _data = init_data;
    _left_link = left;
    _right_link = right;
}


std::string binTree::data() const
{
    return _data;
}

binTree * binTree::left_link()
{
    return _left_link;
}

binTree * binTree::right_link()
{
    return _right_link;
}

const binTree * binTree::left_link() const
{
    return _left_link;
}

const binTree * binTree::right_link() const
{
    return _right_link;
}

void binTree::set_data(const std::string & new_data)
{
    _data = new_data;
}

void binTree::set_left_link(binTree * new_link)
{
    _left_link = new_link;
}

void binTree::set_right_link(binTree * new_link)
{
    _right_link = new_link;
}

bool erase_one(std::string target, binTree * node){
    while(!node->is_leaf() && node->data()!= target){
        if(target < node->data())
            erase_one(target, node->left_link());
        else
            erase_one(target, node->right_link());
    }
    if(node->is_leaf()){
        if(target == node->data()){
            delete node;
            return 1;
        }
        else return 0;
    }
}

std::string right_subtree_value(binTree * link){
    if(!link->is_leaf()){
        right_subtree_value(link->right_link());
    }
    else{
        std::string token = link->data();
        delete link;
        return token;
    }
}
std::string left_subtree_value(binTree * link){
    if(!link->is_leaf()){
        left_subtree_value(link->left_link());
    }
    else{
        std::string token = link->data();
        delete link;
        return token;
    }
}

void print(binTree * root){
    std::cout<<root->data();
}

void preorder(binTree * root){
    print(root);
    while(root->left_link()!=NULL && root->right_link()!=NULL){
        preorder(root->left_link());
        preorder(root->right_link());
        return;
    }
}
