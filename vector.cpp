#include "vector.h"

using namespace cs1c
{
// ==== C
template <class T>
vector<T>::vector() // default constructor
: size_v{0}, elem{nullptr}, space{0} {}

template <class T>
explicit vector<T>::vector(int s) // alternate constructor
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
vector& vector<T>::operator=vector(const vector& source) // copy assignment
{
	T* p = new T[source.size_v];  // create a pointer pointing to a dynamic array
	std::copy(source.elem, source.elem + source.size_v, p); // copy all source data to “p”
	delete[ ] elem;
	elem = p;
	size_v = source.size_v;
	return *this;
}
template <class T>
vector<T>::vector(const vector&& source) noexcept // move constructor
: size_v{source.size_v}, elem{source.elem)
{
	source.elem = nullptr;
	source.size_v = 0;
}
template <class T>
vector& vector<T>::operator=vector(const vector&& source) noexcept // move assignment
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
T& operator[] (int n) // access: return reference
{
	return elem[n];
}
const T& operator[] (int n) // access: return reference
{
	return elem[n];
}
int size() const // the current size
{
	return size_v;
}
int capacity() const // current available space
{
	return space;
}
void resize(int newsize) // grow
{
	reserve(newsize);
	for (int i = size_v; i < newsize; ++i)
		elem[i] = 0; // initialize new elements
	size_v = newsize;
}
void push_back(T val) // add element
{
	if (space == 0)
		reserve(8);				// start with space for 8 elements
	else if (size_v == space)
		reserve(2 * space);		// get more space
	elem[size_v] = d;			// add d at end
	++size_v;					// increase the size (size_v is the number of elements)
}
void reserve(int newalloc) // get more space
{
	// never decrease allocation
	// allocate new space
	// copy old elements
	// deallocate old space
	if(elem == 0)
	{
		size_v = 0;
		space = 0;
	}	
	T * Newbuffer = new T [newalloc];
	unsigned int l_Size = space < size_v ? space : size_v;

	for (unsigned int i = 0; i < l_Size; i++)
		Newbuffer[i] = buffer[i];

	my_capacity = capacity;
	delete[] buffer;
	buffer = Newbuffer;
}
// ==== T
// Similar to typedef
using iterator = T*;
using const_iterator = const T*;

iterator begin() // points to first element
{
	if (size_v == 0)
		return nullptr;
	return elem[0];
}
const_iterator vector::begin() const
{
	if (size_v == 0)
		return nullptr;
	return elem[0];
}
iterator vector::end() // points to one beyond the last element
{
	return elem[size_v - 1];
}
const_iterator vector::end() const
{
	return elem[size_v - 1];
}
iterator vector::insert(iterator p, const T& v) // insert a new element v before p
{
	// if the vector has NO free space
	if(!(space - size_v))
	{
		reserve(space * 2);
		*p = v;
	}
	for(iterator it = this.end(); it != p; it—)
	{
		*(it +1) = *it;
	}
	*p = v;

	return p;
}
iterator vector::erase(iterator p) // remove element pointed to by p
{
	iterator erasedElem = new T[space];
	while(++p != this.end())
	{
		*erasedElem = *p;
	}
	return elem = erasedElem;
}

