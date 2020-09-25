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

class IndexOutOfBoundsException {};

template<typename T>
class Array {
    private:

    T* m_ptr{nullptr};
    int m_size{};

    bool IsIndexValid(int index) const {
        return (index >= 0) && (index < m_size);
    }

    public:

    // Default constructor
    Array() = default;

    // Shallow copy
    //Array(Array& source) = delete[];

    // Constructor to create an array with the given size (element count)
    explicit Array(int size) {
        if (size != 0){
            m_ptr = new T[size];
            m_size = size;
        }
    }

    // Copy constructor (deep copy)
    Array(const Array& source) {
        if (!source.IsEmpty()){
            m_ptr = new T[source.m_size];
            m_size = source.m_size;
            for(int i{}; i < source.Size(); i++){
                m_ptr[i] = source[i];
            }
        }
    }

    // Move constructor
    Array(Array&& source) 
        // "Steal" the data from source 
        : m_ptr{source.m_ptr}
        , m_size{source.m_size} {
        // Reset source in a safe state
        source.m_ptr = nullptr;
        source.m_size = 0;
    }

    // Assignment operator (via copy-and-swap idiom)
    Array& operator = (Array source) {
        swap(*this, source);
        return *this;
    }

    // Swap two array objects (member-wise swap)
    friend void swap (Array& a, Array& b) noexcept {
        using std::swap;
        swap(a.m_ptr, b.m_ptr);
        swap(a.m_size, b.m_size);
    }
    
    // Safe read-only element access with bounds checking
    T operator [] (int index) const {
        if (!IsIndexValid(index)){
            throw IndexOutOfBoundsException {};
        }
        return m_ptr[index];
    }

    // Safe element access with bounds checking
    T& operator [] (int index) {
        if (!IsIndexValid(index)){
            throw IndexOutOfBoundsException {};
        }
        return m_ptr[index];
    }

    int Size() const {
        return m_size;
    }

    bool IsEmpty() const {
        return m_size == 0;
    }

    int LinearSearch(Array& a, int ini, int end, T value) const {
        if (ini < -1 || ini > a.Size() || end < -1 || end > a.Size()) {
            throw IndexOutOfBoundsException {};
        }

        int index{-1};

        for(int i{ini}; i < end; i++) {
            if (a[i] == value) {
                index = i;
                break;
            }
        }

        return index;
    }

    int BinarySearch(Array& a, T value) const {
        int index{-1};

        a = a.BubbleSort(a);

        int min{};
        int max{a.Size()};
        int med{};

        while(min < max) {
            med = (max + min) / 2;
             if (value > a[med]) {
                min++;
             }
             else if (value < a[med]) {
                 max--;
             }
             else if (value == a[med]) {
                 index = med;
                 break;
             }
        }
        return index;
    }

    Array& BubbleSort(Array& a) {
        T t{};
        for(int i{}; i < a.Size(); i++) {
            for(int j{i+1}; j < a.Size();j++) {
                if (a[i] > a[j]) {
                    t = a[j];
                    a[j] = a[i];
                    a[i] = t;
                }
            }
        }
        return a;
    }

    ~Array() {
        delete[] m_ptr;
    }
};

// Enable idiomatic stream insertion for Array objects
// (e.g. cout << ... << myArray << ...)
template <typename T>
inline std::ostream& operator << (std::ostream& os, Array<T> source) {
    os << "[";
    for(int i{}; i < source.Size(); i++) {
        os << source[i] << " ";
    }
    os << "]";
    return os;
}

#endif //ARRAY_HPP_INCLUDED


// Assignment (deep copy)
// Array operator = (Array& source) {
//     m_ptr = new T[source.size];
//     for(int i{}; i < source.Size(); i++) {
//         m_ptr[i] = source.m_ptr[size];
//     }
// }

// Assignment (member-wise swap)
// Array operator = (Array source) {
//     using namespace std::swap;
//     swap(m_ptr, source.m_ptr);
//     swap(m_size, source.m_size);
// }