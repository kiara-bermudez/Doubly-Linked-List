// TODO: Define the DoublyLinkedList class
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <sstream>

template <typename T>
class DoublyLinkedList {

    // Variables
    int length;                                 // Length - number of elements in the list
    Node<T>* front;                                // Pointer to front element
    Node<T>* back;                                 // Pointer to back element

    public:

        DoublyLinkedList();                               // Default constructor

        // Rule of Three
        ~DoublyLinkedList();                              // Destructor
        DoublyLinkedList(const DoublyLinkedList<T>& dll);               // Copy constructor
        DoublyLinkedList<T>& operator =(const DoublyLinkedList<T>& rhs);  // Copy assignment operator

        // Getters
        int getLength() { return length; }
        Node<T>* getFront() { return front; }
        Node<T>* getBack() { return back; }

        // Functions
        void insert(T data, int index); 
        T remove(int index);
        std::string toString();

};

#endif