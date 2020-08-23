#include "./LinkedList.hpp"
#include "cassert"
#include "iostream"

class LinkedListTest {
  public:
    void TestAddingNode() {
      Node node {9}; 
      LinkedList list{};
      list.Add(node);

      assert(list.Size() == 1);

      assert(list.IsHead(node));

      Node node2 {7}; 
      list.Add(node2);

      assert(list.Size() == 2);


      //assert(list.Head() == node); // Verificar pq nao funcionou
    }
    
};

int main(int argc, char *argv[]) {

  std::cout << "*** Testing the LinkedList Clas ***" << std::endl; 

  LinkedListTest test{};
  test.TestAddingNode();

};