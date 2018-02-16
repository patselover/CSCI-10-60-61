#include "hashtable.h"
#include <cassert>
table::table(){
    for(std::size_t i = 0; i<100; ++i)
        _data[i]=NEVER_USED;
    used = 0;
}

void table::insert(const int & key){
    assert(key >= 0);
    bool present;
    std::size_t index;
    find_index(key,present,index);
    if(!present){
        assert(size() < 100);
        while(!is_vacant(index))
            index = next_index(index);
        ++used;
    }
    _data[index] = key;
}

void table::remove(int key){
    assert(key >= 0);
    std::size_t index;
    bool found;
    find_index(key,found,index);
    if(found){
        _data[index]=PREVIOUSLY_USED;
        --used;
    }
}

bool table::is_present(int key)const{
    return is_vacant(hash(key));
}

//void table::find(int key, bool& found, std::size_t& result)const{
//    find_index(key,found,result);
//}

std::size_t table::hash(int key) const{
    return (key % 100);
}
std::size_t table::next_index(std::size_t index)const{
    return((index + 1) % 100);
}
void table::find_index(int key, bool& found, std::size_t& index)const{
    assert(key >= 0);
    std::size_t count = 0;
    index = hash(key);

    while(((count<100) && (!never_used(index)) && (_data[index] != key))){
        ++count;
        index = next_index(index);
    }
    found = (_data[index] == key);
}
inline bool table::never_used(std::size_t index)const{
    return _data[index] == NEVER_USED;
}
inline bool table::is_vacant(std::size_t index) const{
    return ((_data[index] == NEVER_USED) || (_data[index] == PREVIOUSLY_USED));
}
