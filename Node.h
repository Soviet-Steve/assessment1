#ifndef BEN_NODE
#define BEN_NODE
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
    public:
        typedef string nodeType;

        /**
         * Pointer mutators and accessors 
        */
        void setNext(const Node* pInputNext);
        void setPrev(const Node* pInputPrev);
        Node* getNext()const;
        Node* getPrev()const;

        /**
         * Data mutators and accessors 
        */
        void setData(const nodeType& input);
        nodeType getData()const;

        /**
         * Constructors and deconstructors
        */
        Node(const nodeType input, Node* pInputNext = NULL, Node* pInputPrev = NULL);
        Node();
        ~Node();
    private:
        nodeType* pData;
        Node* pNext;
        Node* pPrev;
};

bool operator < (const Node& first, const Node& second);
bool operator > (const Node& first, const Node& second);

#endif