#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstdlib>

class table
{
public:
    static const std::size_t CAPACITY = 100;
    table();
    void insert(const int &);
    void remove(int);
    bool is_present(int)const;
    void find(int key, bool &, int &)const;
    std::size_t size() const{return used;}
private:
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;

    int _data[CAPACITY];
    std::size_t used;

    std::size_t hash(int) const;
    std::size_t next_index(std::size_t)const;
    void find_index(int, bool&, std::size_t&)const;
    bool never_used(std::size_t)const;
    bool is_vacant(std::size_t) const;
};

#endif // HASHTABLE_H
