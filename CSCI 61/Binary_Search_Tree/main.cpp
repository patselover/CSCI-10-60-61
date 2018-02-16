#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "node.h"
#include <queue>
using namespace std;
void next(int it, node * root);
void bst_reverse(node * root);

node * binary_tree(const string & prefix){
    stringstream ss(prefix);
    string temp;
    std::string::size_type sz;
    ss>>temp;
    int token = std::stoi(temp,&sz);
    node tree(token);
    while(ss>>temp){
        token = std::stoi(temp,&sz);
        next(token,&tree);
    }
    return &tree;
}

void next(int it, node * root){
    if(root->is_leaf()){
        if(root->data() >= it)
            root->set_left_link(new node(it));
        else
            root->set_right_link(new node(it));
        return;
    }
    if(it <= root->data())
        next(it, root->left());
    if(it >= root->data())
        next(it, root->right());
}

void bst_reverse(node * root){
    if(root->is_leaf())
        return;
    node * left = root->left();
    node * right = root->right();
    root->set_left_link(right);
    root->set_right_link(left);
    if(right != NULL)
        bst_reverse(right);
    if(left != NULL)
        bst_reverse(left);
}

int main()
{
    node * bst = binary_tree(string("10 3 4 5 6 7 8"));
    //bst_reverse(bst);
    node * p = bst;
    queue<node *> q;
    q.push(p);
    while (!q.empty())
    {
        node *ptr = q.front();
        q.pop();
        if (ptr != nullptr)
        {
            cout << ptr->data() << endl;
            q.push(ptr->left());
            q.push(ptr->right());
        }
    }
    return 0;
}

