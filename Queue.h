// TODO: Define the Queue class
// Note: You can do everything in this file since the functions can all be very small (hint: use your list funcitons!)

#ifndef QUEUE_H
#define QUEUE_H
#include "DoublyLinkedList.h"

template <typename T>
class Queue
{
private:
    DoublyLinkedList<T> dll;
public:

    bool empty() { return (dll.getLength() == 0);}

    void push_back(T data) { dll.insert(data,dll.getLength()); }

    T pop_front() { return dll.remove(0); }

    std::string toString() { return dll.toString();}

};


#endif