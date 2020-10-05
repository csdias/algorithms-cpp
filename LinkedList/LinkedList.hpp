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

    ~Node() {
        delete next;
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

    Node* removeElements(Node* head, int val) {    
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr) {
            while(curr->value == val) {                    
                if (!curr->next) {
                    if (prev) prev->next = nullptr;
                    curr = prev;
                    break;
                }                    
                curr->value = curr->next->value;
                curr->next = curr->next->next;
            }
            if (!curr) break;
            
            prev = curr;
            curr = curr->next;
        }
        
        return (!prev?curr:head);
    }

};


#endif //LINKEDLIST_HPP_INCLUDED