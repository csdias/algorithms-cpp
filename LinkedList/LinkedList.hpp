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

class Node {
    private:
    int m_value{};

    public:
    explicit Node(int value) {
        m_value = value;
    }

    Node* m_next{}; 

    bool operator == (Node node) const {
        return (m_value == node.m_value && this == &node);
    }

};

//template<typename T>
class LinkedList {
    private:
    int m_size {};
    Node* m_head {};

    public:
    int Size() const {
        return m_size;
    }

    bool IsHead(Node& node) {
        return m_head == &node;
    }

    Node& Head() {
        return *m_head;
    }

    Node& Add(Node& node) {
        if (m_head == nullptr) {
            m_head = &node;
            m_size++;
            return *m_head;
        }

        Node node_ = *m_head;

        while(&node_.m_next != nullptr){
            node_ = node_->m_next;
        };

        node_->m_next = _node;

        return *m_head;
    }
};


#endif //LINKEDLIST_HPP_INCLUDED