#include <algorithm>
#include "shape.h"

namespace cs1c
{
// vector header
// a vector which approximates the stl vector
template<class T>
class vector
{
 int size_v;     // the size
 T* elem;     // a pointer to the elements
 int space;     // size+free_space
public:
 vector();     // default constructor
 explicit vector(int s);    // alternate constructor
 vector(const vector&);    // copy constructor
 vector& operator=(const vector&);  // copy assignment
 vector(const vector&&) noexcept;    // move constructor
 vector& operator=(const vector&&) noexcept; // move assignment
 ~vector();      // destructor
 T& operator[](int n);    // access: return reference
// change this line to T& operator[](int n); to not get compile error, but might cause issues in the future
 const T& operator[](int n);    // access: return reference
T& operator[](int n) const;    // access: return reference
 int size() const;    // the current size
 int capacity() const;     // current available space
 void resize(int newsize);   // grow
 void push_back(T val);   // add element
 void reserve(int newalloc);    // get more space

 using iterator = T*;
 using const_iterator = const T*;
 iterator begin();   // points to first element
 const_iterator begin() const;
 iterator end();   // points to one beyond the last element
 const_iterator end() const;
 iterator insert(iterator p, const T& v); // insert a new element v before p
 iterator erase(iterator p);    // remove element pointed to by p
};


// vector definitions
// ==== C
template <class T>
vector<T>::vector() // default constructor
: size_v{0}, elem{nullptr}, space{0} {}

template <class T>
vector<T>::vector(int s) // alternate constructor
: size_v{s}, elem{new T[s]}, space{s}
{
    for (int i = 0; i < size_v; i++)
        elem[ i ] = 0;
}
template <class T>
vector<T>::vector(const vector& source) // copy constructor
: size_v{source.size_v}, elem{new T[source.size_v]}, space{source.space}
{
    // using copy algorithm to copy the contents of source array to this array
    std::copy(source.elem, source.elem + source.size_v, elem);
}
template <class T>
vector<T>& vector<T>::operator=(const vector& source) // copy assignment
{
    T* p = new T[source.size_v];  // create a pointer pointing to a dynamic array
    std::copy(source.elem, source.elem + source.size_v, p); // copy all source data to "p"
    delete[ ] elem;
    elem = p;
    size_v = source.size_v;
    return *this;
}
template <class T>
vector<T>::vector(const vector&& source) noexcept // move constructor
: size_v{source.size_v}, elem{source.elem}
{
    source.elem = nullptr;
    source.size_v = 0;
}
template <class T>
vector<T>& vector<T>::operator=(const vector&& source) noexcept // move assignment
{
    if (this != &source)
    {
        delete[ ] elem;
        elem = source.elem;
        size_v = source.size_v;
        source.elem = nullptr;
    }
    return *this;
}
template <class T>
vector<T>::~vector() // destructor
{
    delete[ ] elem;
}
// ===== I
template <class T>
T& vector<T>::operator[] (int n) // access: return reference
{
return elem[n];
}
template <class T>
//change this line to T& vector<T>::operator[](int n ) const
const T& vector<T>::operator[] (int n) // access: return reference
// Ch: change this line to T& vector<T>::operator[](int n ) const
T& vector<T>::operator[] (int n) const // access: return reference
{
return elem[n];
}
template <class T>
int vector<T>::size() const // the current size
{
    return size_v;
}
template <class T>
int vector<T>::capacity() const // current available space
{
    return space;
}
template <class T>
void vector<T>::resize(int newsize) // grow
{
reserve(newsize);
for (int i = size_v; i < newsize; ++i)
    elem[i] = 0; // initialize new elements
size_v = newsize;

}
template <class T>
void vector<T>::push_back(T val) // add element
{
    if (space == 0)
        reserve(8);             // start with space for 8 elements
    else if (size_v == space)
        reserve(2 * space);     // get more space
    elem[size_v] = val;           // add val at end
    ++size_v;                   // increase the size (size_v is the number of elements)

}
template <class T>
void vector<T>::reserve(int newalloc) // get more space
{
  T* newElem = new T[newalloc]();
  for(int i = 0; i < size_v; i++)
  {
    newElem[i] = elem[i];
  }
  // delete old array
  delete [] elem;
  // assign new array content to elem pointer
  elem = newElem;
  space = newalloc;
  // newElem pointer disappears at end of func
}
// ==== T
// Similar to typedef
/*

template <class T>
using iterator = T*;
template <class T>
using const_iterator = const T*;

template <class T>
iterator vector<T>::begin() // points to first element
{
        if (size_v == 0)
                   return nullptr;
        return elem[0];
        return &elem[0];
}
template <class T>
const_iterator vector<T>::begin() const
{
        if (size_v == 0)
                    return nullptr;
        return elem[0];
        return &elem[0];
}
template <class T>
iterator vector<T>::end() // points to one beyond the last element
{
        if (size_v == 0)
                    return nullptr;
        return elem[size_v - 1];
        return &elem[size_v];
}
template <class T>
const_iterator vector<T>::end() const
{
        if (size_v == 0)
                    return nullptr;
        return elem[size_v - 1];
        return &elem[size_v];
}
template <class T>
iterator vector<T>::insert(iterator p, const T& v) // insert a new element v before p
{
  // if the vector has NO free space
  if(!(space - size_v))
  {
    reserve(space * 2);
    *p = v;
  }
  for(iterator it = this.end(); it != p; it--)
  {
    *(it +1) = *it;
  }
  *p = v;

  return p;
}
template <class T>
iterator vector<T>::erase(iterator p) // remove element pointed to by p
{
  iterator erasedElem = new T[space];
  while(++p != this.end())
  {
    *erasedElem = *p;
  }
  return elem = erasedElem;
}
*/

}
