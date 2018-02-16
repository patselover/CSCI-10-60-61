#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <algorithm>

template <class T>
class node
{
public:
    typedef T value_type;
    //pre: none
    //post: creates a new node with given data and link values
    //      default: 0 and nullptr
    node(const value_type & = value_type(), node * = nullptr);

    //pre: none
    //post: returns data vale stored in this node
    value_type data()const;

    value_type & data();

    //pre: none
    //post: returns link value stored in this node
    node * link ();
    const node* link() const;

    //pre: none
    //post: sets the data field to given value
    void set_data(const value_type & new_data);

    //pre: none
    //post: sets the link field to given value
    void set_link(node *);

    void erase(T key);

private:
    value_type _data;
    node * _link;
    //INVARIANTS:
    // _data holds the data value stroed in this node
    // _link holds the address of the next node
};

template<class T>
void node<T>::erase(T key){
    node<T>* prev = _link;
    if(prev->data() == key){
        prev->set_link(_link);
        prev->set_data(key);
        _link = prev;
    }
    node<T>* temp = prev->link();
    while(temp->data() != key && temp->link() != NULL){
        prev->set_link(temp);
        temp->set_link(temp->link());
        if(temp->data() == key){
            node<T> token(key,temp);
            prev->set_link(&token);
        }
    }
    delete temp;
}

template<class T>
void insert_at(node<T> * & head, T value, std::size_t pos){
    std::size_t count=0;
    if(pos==0){
        head=new node<T>(value,head);
    }
    for(node<T> * p=head; p!=nullptr; p=p->link()){
        if(count==pos-1){
            p->set_link(new node<T>(value,p->link()));
            return;
        }
        count++;
    }
}

#endif // NODE_H
