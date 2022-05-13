#include <algorithm>

namespace cs1c
{
    // vector header
    // a vector which approximates the stl vector
    template<typename T>
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
    template <typename T>
    vector<T>::vector() // default constructor
        : size_v{ 0 }, elem{ nullptr }, space{ 0 } {}

    template <typename T>
    vector<T>::vector(int s) // alternate constructor
        : size_v{ s }, elem{ new T[s] }, space{ s }
    {
        for (int i = 0; i < size_v; i++)
            elem[i] = 0;
    }
    template <typename T>
    vector<T>::vector(const vector& source) // copy constructor
        : size_v{ source.size_v }, elem{ new T[source.size_v] }, space{ source.space }
    {
        // using copy algorithm to copy the contents of source array to this array
        std::copy(source.elem, source.elem + source.size_v, elem);
    }
    template <typename T>
    vector<T>& vector<T>::operator=(const vector& source) // copy assignment
    {
        T* p = new T[source.size_v];  // create a pointer pointing to a dynamic array
        std::copy(source.elem, source.elem + source.size_v, p); // copy all source data to "p"
        delete[] elem;
        elem = p;
        size_v = source.size_v;
        return *this;
    }
    template <typename T>
    vector<T>::vector(const vector&& source) noexcept // move constructor
        : size_v{ source.size_v }, elem{ source.elem }
    {
        source.elem = nullptr;
        source.size_v = 0;
    }
    template <typename T>
    vector<T>& vector<T>::operator=(const vector&& source) noexcept // move assignment
    {
        if (this != &source)
        {
            delete[] elem;
            elem = source.elem;
            size_v = source.size_v;
            source.elem = nullptr;
        }
        return *this;
    }
    template <typename T>
    vector<T>::~vector() // destructor
    {
        delete[] elem;
    }
    // ===== I
    template <typename T>
    T& vector<T>::operator[] (int n) // access: return reference
    {
        return elem[n];
    }
    template <typename T>
    // Ch: change this line to T& vector<T>::operator[](int n ) const 
    T& vector<T>::operator[] (int n) const // access: return reference
    {
        return elem[n];
    }
    template <typename T>
    int vector<T>::size() const // the current size
    {
        return size_v;
    }
    template <typename T>
    int vector<T>::capacity() const // current available space
    {
        return space;
    }
    template <typename T>
    void vector<T>::resize(int newsize) // grow
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = 0; // initialize new elements
        size_v = newsize;

    }
    template <typename T>
    void vector<T>::push_back(T val) // add element
    {
        if (space == 0)
            reserve(8);             // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space);     // get more space
        elem[size_v] = val;           // add val at end
        ++size_v;                   // increase the size (size_v is the number of elements)

    }
    template <typename T>
    void vector<T>::reserve(int newalloc) // get more space
    {
        T* newElem = new T[newalloc]();
        for (int i = 0; i < size_v; i++)
        {
            newElem[i] = elem[i];
        }
        // delete old array
        delete[] elem;
        // assign new array content to elem pointer
        elem = newElem;
        space = newalloc;
        // newElem pointer disappears at end of func
    }
    // ==== T
    // Similar to typedef

    //template <typename T>
    //using iterator = T*;
    // <typename T>
    //using const_iterator = const T*;

    template <typename T>
    typename vector<T>::iterator vector<T>::begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }
    template <typename T>
    typename vector<T>::const_iterator vector<T>::begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }
    template <typename T>
    typename vector<T>::iterator vector<T>::end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }
    template <typename T>
    typename vector<T>::const_iterator vector<T>::end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }
    template <typename T>
    typename vector<T>::iterator vector<T>::insert(iterator p, const T& v) // insert a new element v before p
    {
        // if the vector has NO free space
        if (!(space - size_v))
        {
            reserve(space * 2);
            *p = v;
        }
        for (vector<T>::iterator it = this->end(); it != p; it--)
        {
            *(it) = *(it - 1);
        }
        *p = v;
        size_v++;
        return p;
    }
    template <typename T>
    typename vector<T>::iterator vector<T>::erase(vector<T>::iterator p) // remove element pointed to by p
    {
        //iterator<T> erasedElem = new T[space]; unecessary
        p--;
        while (++p != (this->end() - 1))
        {
            if (size_v == 0)
                return nullptr;
            *p = *(p + 1);
        }
        // don't worry about cleanup of last value
        size_v--;
        return p;
    }
}
