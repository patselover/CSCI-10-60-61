#ifndef LBAG_H
#define LBAG_H

template<class T>
class lbag
{
public:
    typedef T value_type;
    typedef std::size_t size_type;
    lbag();
    lbag(const lbag &);
    ~lbag();
    void operator = (const lbag &);

    size_type size() const;
    size_type count(const T &) const;

    void insert(const T &);
    void operator += (const lbag &);

    bool erase_one(const T &);
    size_type erase(const T &);

};

template<class T>
void lbag<T>::operator =(const lbag<T> & b)
{
    list_copy;
}

template<class T>
lbag();
template<class T>
template<class T>
template<class T>
template<class T>
template<class T>
template<class T>
#endif // LBAG_H
