#ifndef HASHT_H
#define HASHT_H
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include "node.h"

class table
{
public:
    static const std::size_t CAPACITY = 26;
    table();
    table(const table&);
    void insert(const std::string&);
    void remove(std::string);
    void find(std::string key, bool& found, std::size_t)const;
    bool is_present(std::string key) const;
    std::size_t size() const{return total;}

private:
    node<std::string> * _data[CAPACITY];
    std::size_t total;
    std::size_t hash(std::string key) const;
};

table::table(){
    for(std::size_t i = 0; i<CAPACITY; ++i)
        _data[i]->set_link(NULL);
    total = 0;
}

table::table(const table& HTable){
    for(std::size_t i = 0; i<CAPACITY; ++i)
        _data[i]->set_link(HTable._data[i]);
}

void table::insert(const std::string& key){
    assert(key[0] >= 'a' && key[0] >= 'z');
    bool present;
    std::size_t index;
    find(key,present,index);
    insert_at(_data[hash(key)],key,index);
    ++total;
}

void table::remove(std::string key){
    bool present;
    std::size_t index;
    find(key,present,index);
    if(present){
        node<std::string> *token = _data[hash(key)];
        token->erase(key);
        _data[hash(key)] = token;
        --total;
    }
}

void table::find(std::string key, bool& found, std::size_t index)const{
    node<std::string>*token = _data[hash(key)];
    index = 0;
    while(token->data() != key && token->link() != NULL){
        token->set_link(token->link());
        ++index;
    }
    found = (token->data() == key);
}

bool table::is_present(std::string key) const{
    bool present;
    std::size_t index;
    find(key,present,index);
    return present;
}

std::size_t table::hash(std::string key) const{
    return ('z'-key[0]);
}

#endif // table_H
