// StackArray.cpp -- A generic stack allocated array class template 
//
//              Implements a generic stack allocated array 
//
// By Carlos Soares Dias

#include <iostream>     // For cout
#include <cassert>      // For assert 
#include <ostream>      // For std::ostream
#include <utility>      // For std::swap

template<typename T>
class AllocaStackArray {
    private:
    T* m_data; 

    public:
    // allocate in the stack memory
    // lack compiler optimization
    // compiler doesn't know how big it'll be
    AllocaStackArray(int size) {
        m_data = (T*)alloca(size * sizeof(T));
    }
};

template<typename T, size_t S>
class StackArray {
    private:

    T m_data[S];

    public:

    constexpr size_t Size() const {
        return S;
    }

    const T& operator [] (int index) const {
        return m_data[index];
    }

    T& operator [] (int index) {
        return m_data[index];
    }
};

int main(int argc, char* argv[]) {

    AllocaStackArray<int> s{5};

    StackArray<int, 5> h;
    h[0] = 1; h[1] = 2; h[2] = 3; h[3] = 4; h[4] = 5; h[5] = 6; h[6] = 7;

    static_assert(h.Size() < 10, "Size is too large!");

    for(int i{}; i < h.Size(); i++) {
        std::cout << h[i] << std::endl;
    }

};
