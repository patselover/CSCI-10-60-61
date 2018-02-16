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
    void insert_at(node<T> * & head, node::value_type value, std::size_t pos);
private:
    value_type _data;
    node * _link;
    //INVARIANTS:
    // _data holds the data value stroed in this node
    // _link holds the address of the next node
};

template<class T>
std::size_t list_size(const node<T> * head);

template<class T>
void list_head_insert (node<T> * & head, node<T> * & tail, const T & value);

template<class T>
void list_tail_insert(node<T> * & head, node<T> * & tail, const T & value);

template<class T>
std::ostream & operator << (std::ostream & os, const node<T> * head);

template<class T>
node<T>* list_search(node<T>* head, const T & value);

template<class T>
node<T>* list_locate(node<T>* head, std::size_t pos);

template<class T>
void list_copy(const node<T> *orig_head, const node<T> *orig_tail, node<T> * & new_head, node<T> * & new_tail){
    new_head = new_tail = nullptr;
    for(const node<T> p=orig_head; p!=nullptr; p=p->link()){
        list_tail_insert(new_head, new_tail, p->data());
    }
}

template<class T>
void remove(node<T> * previous){
    node<T>* temp = previous ->link();
    previous->set_link(temp->link());
    delete temp;
}

template<class T>
void list_head_remove(node<T> * & head, node<T> * & tail){
    if(head==nullptr){
        return;
    }
    node<T> * temp = head;
    head = head->link();
    delete temp;
    if(head == nullptr){
        tail = head;
    }
}

template<class T>
void list_clear(node<T> * & head, node<T> * & tail){

}

template<class T>
void list_remove(node<T> * previous){

}

template<class T>
void list_insert(node<T> * previous, const T & value){
    previous->set_link(new node(value,previous->link()));
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
