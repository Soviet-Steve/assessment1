#ifndef BEN_LINKED_LIST
#define BEN_LINKED_LIST
#include "Node.h"

class LinkedList{
    public:
        typedef string nodeType;

        void remove(const nodeType input); // This may need to be extended.
        void add(const nodeType input); // This basically becomes a very short function in case that sorts out to 3 smaller functions
        uint32_t count(const nodeType input) const; // Check to see if this needs to be sorted.
        void sort();
        
        /**
         * Constructors and deconstructors
        */
        LinkedList(/* args */);
        ~LinkedList();
    private:
        void insert(const nodeType input);
        void extract(); // This is the remove function but for a single word.
        void addToHead(); // 3 Smaller functions that add to the linked list.
        void addToTail();
        void addInternal();
        uint32_t inLength; // Everytime the add function gets called the data 
        Node* pHead;
        Node* pTail;
        Node* pCurrent;
};

ostream& operator << (ostream& out, const LinkedList& list);
void operator += (LinkedList& head, const LinkedList& tail);
#endif