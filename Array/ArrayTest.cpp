#include "./Array.hpp"
#include "cassert"
#include "iostream"

class ArrayTest {
  public:
    void TestDefaultCtor() {

      Array<int> a{};
      assert(a.Size() == 0);

      Array<double> b{};
      assert(b.Size() == 0);
    }
    
};

int main(int argc, char *argv[]) {

  std::cout << "*** Testing the Array<T> Template Clas ***" << std::endl; 
  ArrayTest test{}; 
  test.TestDefaultCtor();

};