#include "Node.h"

/**
 * Non default contructor, which should be used
 */
Node::Node(const nodeType input, Node* pInputNext /*= NULL */, Node* pInputPrev /*= NULL*/ ){
    pData = new nodeType(input); // Don't fully know if this right, I think it works but it's calling the contructor for the object which could prove to be problematic
    pNext = pInputNext;
    pPrev = pInputPrev;
}

/**
 * Default contructor, shouldn't have to use, but might get used
 */
Node::Node(){
    pData = new nodeType;
    pNext = NULL;
    pPrev = NULL;
}

/**
 * Default destructor deletes only the object that the node is pointing, otherwise it could delete adjecnt nodes 
 */
Node::~Node(){
    delete pData;
}


/**
 * Sets the next node, pretty simple
 */
void Node::setNext(const Node* pInputNext){
    pNext = (Node *)pInputNext; // Pointer casting?
}


/**
 * Sets the prev node, pretty simple
 */
void Node::setPrev(const Node* pInputPrev){
    pPrev = (Node *)pInputPrev;
}


/**
 * Returns a *pointer* to the next node, quite basic
 */
Node* Node::getNext()const{
    return pNext;
}

/**
 * Returns a *pointer* to the prev node, again really basic
 */
Node* Node::getPrev()const{
    return pPrev;
}


/**
 * Sets the data incase it needs to be changed? 
 */
void Node::setData(const nodeType& input){
    *pData = (nodeType)input; // Get this line right, so my normal convention is pVar = *newPVar (sometimes with pointer casting), but i cant deference on the right end side and pData* = is treated as *=
}

Node::nodeType Node::getData()const{
    return *pData;
}