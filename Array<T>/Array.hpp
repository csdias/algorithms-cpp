// Array.hpp -- A generic array class template
//
//              Implements several features from copy constructor,
//              to copy-and-swap idiom, move constructor,
//              printing via overloaded operator<<, etc.
//
// By Carlos Soares Dias

#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

#include <cassert>      // For assert 
#include <ostream>      // For std::ostream
#include <utility>      // For std::swap

class IndexOutOfBoundException {};

template<typename T>
class Array {
    private:

    T* m_ptr{nullptr};
    int m_size{};

    bool IsIndexValid(int index){
        return (index > 0 && index <= size);
    }

    public:

    // Default constructor
    Array<T>() = default;

    // Shallow copy
    //Array<T>(Array& source) = delete[];

    // Constructor to create an array with the given size (element count)
    explicit Array<T>(int size) {
        if (size != 0){
            m_ptr = new T[size];
            m_size = size;
        }
    }

    // Copy constructor (deep copy)
    Array<T>(const Array<T>& source) {
        if (!source.IsEmpty){
            m_ptr = new T[source.m_size];
            m_size = source.m_size;
            for(int i{}; i < source.Size(); i++){
                m_ptr[i] = source[i];
            }
        }
    }

    // Move constructor
    Array<T>(Array<T>&& source) 
        // "Steal" the data from source 
        : m_ptr{source.m_ptr}
        , m_size{source.m_size} {
        // Reset source in a safe state
        source.m_ptr{nullptr};
        source.m_size{};
    }

    // Assignment operator (via copy-and-swap idiom)
    Array<T>& operator = (Array<T> source){
        swap(*this, source);
        return *this;
    }

    // Swap two array objects (member-wise swap)
    friend swap (Array<T>& a, Array<T>& b) noexcept {
        using std::swap;
        swap(a.m_ptr, b.m_ptr);
        swap(b.m_size, b.m_size);
    }
    
    // Safe read-only element access with bounds checking
    T operator [] (int index) const {
        if (!IsIndexValid(index)){
            throw new IndexOutOfBoundException;
        }
        return m_ptr[index];
    }

    // Safe element access with bounds checking
    T& operator [] (int index) {
        if (!IsIndexValid(index)){
            throw new IndexOutOfBoundException;
        }
        return m_ptr[index];
    }

    int Size const {
        return m_size;
    }

    bool IsEmpty const {
        return m_size == 0;
    }

    Array<T>& operator [] (int index) {
        return *m_ptr[index];
    }

    Array<T> operator [] (int index) const {
        return *m_ptr[index];
    }

    ~Array() {
        delete[] m_ptr;
    }
};

// Enable idiomatic stream insertion for Array objects
// (e.g. cout << ... << myArray << ...)
template <typename T>
inline std::ostream& operator << (std::ostream& os, const Array<T> source) {
    std::ostream os;
    os << "["
    for(int i{}; i < source.Size(); i++) {
        os << source[i] << " ";
    }
    os << "]";
    return os;
}

#endif //ARRAY_HPP_INCLUDED


    // Assignment (deep copy)
    // Array<T> operator = (Array<T>& source) {
    //     m_ptr = new T[source.size];
    //     for(int i{}; i < source.Size(); i++) {
    //         m_ptr[i] = source.m_ptr[size];
    //     }
    // }

    // Assignment (member-wise swap)
    // Array<T> operator = (Array<T> source) {
    //     using namespace std::swap;
    //     swap(m_ptr, source.m_ptr);
    //     swap(m_size, source.m_size);
    // }