#ifndef BEN_LINKED_LIST
#define BEN_LINKED_LIST
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

class LinkedList{
    public:
        typedef Node::nodeType nodeType;

        void remove(const nodeType input); // This may need to be extended.
        void add(const nodeType input); // This basically becomes a very short function in case that sorts out to 3 smaller functions
        uint32_t count(const nodeType input); // Check to see if this needs to be sorted.
        void sort();
        nodeType getData() const;
        Node* getHead() const;
        Node* getCurrent() const; 
        void moveCurr(const Node* input);
        Node* getTail() const;
        
        /**
         * Constructors and deconstructors
        */
        LinkedList(/* args */);
        ~LinkedList();
    private:
        void insert(const nodeType input);
        void extract(); // This is the remove function but for a single word.
        void addToHead(const nodeType input); // 3 Smaller functions that add to the linked list.
        void addToTail(const nodeType input);
        void addInternal(const nodeType input);
        uint32_t inLength; // Everytime the add function gets called the data 
        Node* pHead;
        Node* pTail;
        Node* pCurrent;
};

ostream& operator << (ostream& out, LinkedList& list);
void operator += (LinkedList& first, LinkedList& second);
#endif