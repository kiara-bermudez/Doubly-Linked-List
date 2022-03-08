#ifndef NODE_H
#define NODE_H
#include "NetworkPacket.h"

// TODO: Define the Node class
// Note: Since the functions are all small, you can put everything in this file
template <typename T>
class Node {

    private:
        // Variables
        T data;
        Node<T>* next;
        Node<T>* prev;

    public:
        // Default constructor
        Node(): next(nullptr), prev(nullptr) {} 
        // Parameterized constructor
        Node(const T& d): data(d), next(nullptr), prev(nullptr) {}

        
        // Getters
        T getData() { return data;}
        Node<T>* getNext() { return next;}
        Node<T>* getPrev() { return prev;}

        // Setters

        void setData(const T& d) { data = d; }
        void setNext(Node<T>* n) { next = n; }
        void setPrev(Node<T>* p) { prev = p; }

	
};



#endif