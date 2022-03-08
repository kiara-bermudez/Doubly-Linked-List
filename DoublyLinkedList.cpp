// TODO: Write the source functions for the DoublyLinkedList
#include "DoublyLinkedList.h"

// Default constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : length(0), front(nullptr), back(nullptr) {}

// Rule of Three
// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* ptr = nullptr;         // Create node pointer
    
    while(front != nullptr) {       // Loop through linked list
        ptr = front;                // deleting the head node of the list
        front = front->getNext();   // until there are no nodes remaining
        ptr->setNext(nullptr);
        delete ptr;
    }

    front = nullptr;
    back = nullptr;
    ptr = nullptr;
}    

// Copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& dll) : length(0), front(nullptr), back(nullptr) {
    if (dll.front == nullptr) {                         // Check whether dll is empty
        front= nullptr;
        back = nullptr;
        length = 0;
        return;
    }

    Node<T>* curr = dll.front;                             // Current node in dll
    Node<T>* newNode = nullptr;                            // New node in new list
    Node<T>* prev = nullptr;                               // Previous node in new list
    int cnt = 0;                                        // Count of elements in list

    while (curr != nullptr) {                           // Loop though dll

        newNode = new Node<T>(curr->getData());                 // Create node in new list

        if (front == nullptr) {                          // Check whether front has not been set
            front = newNode;                             // Set front
        } 

        if (prev != nullptr) {                          // Check whether prev is set to a node
            prev->setNext(newNode);                       // Set prev next to new node 
        }

        prev = newNode;                                 // Set prev node

        curr = curr->getNext();                              // Move on to next node in dll

        newNode = nullptr;                              // Nullify newNode

        cnt++;                                          // Increment cnt
    } 

    back = prev;                                        // Set back
    length = cnt;                                       // Set length
}

// Copy assingment operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs) {
    if (this == &rhs) {                                 // Self-assignment
        return *this;
    }

    this->~DoublyLinkedList();                          // Clear list;

    if (rhs.front == nullptr) {                         // Check whether source list is empty
        front = nullptr;
        back = nullptr;
        return *this;
    }

    Node<T>* curr = rhs.front;                             // Current node in source list
    Node<T>* newNode = nullptr;                            // New node in new list
    Node<T>* prev = nullptr;                               // Previous node in new list
    int cnt = 0;                                        // Count of elements in list

    while (curr != nullptr) {                           // Loop though the source list

        newNode = new Node<T>(curr->getData());                 // Create node in new list

        if (front == nullptr) {                         // Check whether front has not been set
            front = newNode;                            // Set front
        } 

        if (prev != nullptr) {                          // Check whether prev is set to a node
            prev->setNext(newNode);                       // Set prev next to new node 
        }

        prev = newNode;                                 // Set prev node

        curr = curr->getNext();                              // Move on to next node in source list

        newNode = nullptr;                              // Nullify newNode

        cnt++;                                          // Increment cnt
    } 

    back = prev;                                        // Set back
    length = cnt;                                       // Set length


    return *this;                                       // Return pointer to self
}


// Functions
// Insert a new node into list
template <typename T>
void DoublyLinkedList<T>::insert(T data, int index) {

    // Check if index is out of range
    if (index > length || index < 0) {
        throw std::out_of_range("Index outside of list bounds - i");
    }

    // Create temp nodes
    Node<T>* newNode = new Node<T>(data);
    Node<T>* prev = nullptr;
    Node<T>* curr = front;

    // Insertion:
    // If empty
    // Then new node is the front and back of list
    if (front == nullptr) {
        front = newNode;
        back = newNode;
    }
    // Insert at front
    // Then new node is the new front
    else if (index == 0) {
        newNode->setNext(curr);
        front->setPrev(newNode);
        front = newNode;
    }
    // Insert at end
    // Then new node is the new back
    else if (index == length) {
        // If list is only head
        if (front->getNext() == nullptr) {
            front->setNext(newNode);
            newNode->setPrev(front);
            back = newNode;
        } else {    // If more than 1 node in list
            back->setNext(newNode);
            newNode->setPrev(back);
            back = newNode;
        }

        
    }
    // Insert in middle
    else {
        int cnt = 0;
        // Loop through list until you reach index where you want to insert node
        while(curr != nullptr && cnt < index) {
            prev = curr;
            curr = curr->getNext();
            cnt++;
        } 
        // Insert node between the current and previous nodes
        newNode->setNext(curr);
        newNode->setPrev(prev);
        prev->setNext(newNode);
        curr->setPrev(newNode);
    }

    // Increment length
    length++;
    
}

// Remove node fron list
template <typename T>
T DoublyLinkedList<T>::remove(int index) {

    // Check if list is empty or index is out of range
    if(length == 0 || index < 0 || index >= length) {
        throw std::out_of_range("Index outside of list bounds");
    }

    //Node* target = new Node(data_);
    Node<T>* curr = front;
    Node<T>* prev = nullptr;
    int cnt = 0;
    T target;

    // Remove single element
    if(length == 1) {
        target = curr->getData();
        delete curr;
        front = nullptr;
        back = nullptr;
    }
    // Remove front
    else if (index == 0) {
        target = curr->getData();
        front = curr->getNext();
        curr->getNext()->setPrev(nullptr);
        delete curr;
    }
    //Remove back
    else if (index == length - 1) {
        
        curr = back;
        target = curr->getData();

        // If there are more than 2 nodes
        if (front->getNext() != back){ 
            back = back->getPrev();
            back->setNext(nullptr);
            curr->setPrev(nullptr);
            delete curr;
            curr = nullptr;
        } else {   // If there are 2 nodes or less
            front->setNext(nullptr);            
            curr->setPrev(nullptr);
            delete curr;            
            curr=nullptr;
            back = front;
        }
        


    }
    // Remove from middle
    else {
        // Traverse to index of node we want to remove
        while(curr != nullptr && cnt < index) {
        prev = curr;
        curr = curr->getNext();
        cnt++;
        }
        target = curr->getData();

        // Update pointers
        prev->setNext(curr->getNext());
        curr->getNext()->setPrev(prev);
        delete curr;
    }  

    length--;    // Decrement length
    return target;

}

// Returns the data of the list as a string
template <typename T>
std::string DoublyLinkedList<T>::toString() {
    std::string output;                     // String output variable
    std::ostringstream os;                  // Ostream
    Node<T>* current = front;                  // Current node of list

    while (current != nullptr) {            // Loop thorugh list,
        os << current->getData() << " ";    // putting each nodes data into ostringstream
        current = current->getNext();
    }

    output = os.str();                      // Convert ostringstream to string
    os.clear();                             // Clear ostringstream

	return output;
}

template class DoublyLinkedList<NetworkPacket>;
template class DoublyLinkedList<int>;