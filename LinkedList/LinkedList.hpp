// LinkedList.hpp -- A generic LinkedList class template
//
//              
//              
//              
//
// By Carlos Soares Dias

#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED

#include <cassert>      // For assert 
#include <ostream>      // For std::ostream
#include <utility>      // For std::swap

//template<typename T>
class Node {
    public:
    int value{};
    Node* next{nullptr};

    Node(int val) {
        value = val;
    }
};

//template<typename T>
class LinkedList {
    public:
    LinkedList() = default;

    Node* Add(Node* root, int value) {
        Node* node = new Node(value);
        if (root == nullptr) {
            root = node;
        }
        else {
            Node* temp = root;

            while(temp->next != nullptr){
                temp = temp->next;
            };
            temp->next = node;
        }

        return root;
    }
};


#endif //LINKEDLIST_HPP_INCLUDED