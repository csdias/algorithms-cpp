#include "./LinkedList.hpp"
#include "cassert"
#include <iostream>

class LinkedListTest {
  public:
    void TestAddingNode() {
      Node* node{nullptr};
      LinkedList list;
      node = list.Add(node, 3);
      node = list.Add(node, 2);
      node = list.Add(node, 7);
      node = list.Add(node, 5);

      assert(node->value == 3);
      assert(node->next->value == 2);

      while(node->next != nullptr){
        std::cout << node->value << std::endl;
        node = node->next;
      }
      std::cout << node->value << std::endl;

    }
};

int main(int argc, char *argv[]) {

  std::cout << "*** Testing the LinkedList Clas ***" << std::endl; 

  LinkedListTest test{};
  test.TestAddingNode();

};