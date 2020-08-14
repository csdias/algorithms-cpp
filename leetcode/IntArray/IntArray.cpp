
#include <iostream>
#include "ostream"
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
//#include "string"
#include "utility"

class IndexOutOfBoundException {};

class IntArray {
  private:  
    int m_size{};
    int *m_ptr{nullptr};

    bool IsIndexValid (int index) const {
      return (index >= 0 && index < m_size);
    }  

  public:

    // Default constructor
    IntArray() = default;

    // Shallow constructor (the delete is to disable)
    //IntArray(const IntArray&) = delete; 

    // Constructor to create an array with the given size (element count)
    explicit IntArray (int size) {
      m_ptr = new int[size] {};
      m_size = size;
    }

    // Copy constructor (deep copy)
    IntArray(const IntArray& source) { 
      if (!source.IsEmpty()) {
        m_size = source.Size();
        m_ptr = new int[m_size]{};

        for(int i{}; i < source.Size(); i++) {
          m_ptr[i] = source[i];
        }
      }
    }

    bool IsEmpty() const {
      return m_size == 0;
    }

    int Size() const {
      return m_size;
    }

    // Overload operator = 
    // IntArray& operator = (const IntArray& source) {

    //   // Prevent self-assignment (x = x)
    //   if (&source != this) {

    //       // Release the previous array block
    //       delete[] m_ptr;
          
    //       m_ptr = new int[source.Size()]{};
    //       for(int i{}; i < source.Size(); i++){
    //         m_ptr[i] = source[i];
    //       }
    //   }

    //   return *this;
    // }

    // Overload operator = (copy swap idiom)
    IntArray& operator = (IntArray source){
      swap(*this, source);
      return *this;
    }

    // Overload operator [] (set)
    int& operator [] (int index) {
      if (!IsIndexValid(index))
        throw IndexOutOfBoundException();

      return m_ptr[index];
    }

    // Overload operator [] (get)
    int operator [](int index) const {
      if (!IsIndexValid(index))
        throw IndexOutOfBoundException();
      return m_ptr[index];
    }
    
    friend void swap (IntArray&& source) {
      //m_ptr = source.m_ptr;
      //m_size = source.m_size;
      
      source.m_ptr = nullptr;
      source.m_size = 0;
    }

    void swap(IntArray& a, IntArray& b){

      int* ptr{};
      int size{};

      ptr = a.m_ptr;
      size = a.m_size;

      a.m_ptr = b.m_ptr;
      a.m_size = b.m_size;

      b.m_ptr = ptr;
      b.m_size = size;

      ptr = nullptr;
    }

    ~IntArray(){ 
      delete[] m_ptr;
    }
};

  std::ostream& operator << (std::ostream& os, IntArray& source) {
    os << "[";
    for (int i{}; i < source.Size(); i++) {
      os << source[i] << " ";        
    }
    os << "]";
    return os;
  }

int main(int argc, char *argv[]) {
  try {

    int x{4};
    int y{8};

    IntArray ar{3};
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    
    IntArray cr{3};
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    
    IntArray br = ar;

    cr = ar;



    br[1] = 4;

    ar.swap(br,ar);


    for(int i{}; i < ar.Size(); i++){
      std::cout << ar[i] << std::endl;
    }

    for(int i{}; i < br.Size(); i++) {
      std::cout << br[i] << std::endl;
    }  
  }
  catch(const IndexOutOfBoundException& e)
  {
    std::cout << "Index out of bounds exception" << '\n';
  }
  
};