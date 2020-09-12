#include "LinkedList.h"

#define DEBUG

LinkedList::LinkedList(){
    inLength = 0U;
}

LinkedList::~LinkedList(){
    
    for(pCurrent = pHead; pCurrent->getNext() == NULL; pCurrent = pCurrent->getNext()){ // Think of it like a rail worker moving along a track and taking it up as he travels
        if(pCurrent->getPrev() != NULL){
            delete pCurrent->getPrev();
        }
        if(pCurrent->getNext() == NULL){
            delete pCurrent;
        }  
    }
}

/**
 * Function: LinkedList::remove
 * 
 * Searches for a node and deletes it if it matches the input
 * 
 * input: The node data that will be searched for and destoryed
 * 
*/
void LinkedList::remove(const nodeType input){
    for(pCurrent = pHead; pCurrent != NULL; pCurrent = pCurrent->getNext()){
        if(getData() == input){
            if(pCurrent->getPrev() != NULL)
                pCurrent->getPrev()->setNext(pCurrent->getNext());
            if(pCurrent->getNext() != NULL)
                pCurrent->getNext()->setPrev(pCurrent->getPrev());
            delete pCurrent;
            inLength--;
        }
    }
} 

/**
 * Fuction: LinkedList::add 
 * 
 * Gets input data based on the nodeType searches for and then creates and add a node to the linked list
 * 
 * input: node data
*/
void LinkedList::add(const nodeType input){
    istringstream ss((string)input); // String stream code adopted from https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/
    do{
        string word;
        ss >> word;        
        addToTail(word);
        inLength++;
    }while(ss);   
    moveCurr(pTail->getPrev()); // SS adds a " " node to the end of the list so this removes it
    delete pTail;
    pTail = pCurrent;
    pCurrent->setNext(NULL);
    inLength--;
} 

/**
 * Fuction: LinkedList::count
 * 
 * Searches for a number of how often a node matches with the input data
 * 
 * input: node data
 * 
 * returns: match count
*/
uint32_t LinkedList::count(const nodeType input){ // Const not here so that pCurrent can accessed, working on this
    uint32_t count = 0;
    for(pCurrent = pHead; pCurrent != NULL; pCurrent = pCurrent->getNext()){
        if(getData() == input){
            count++;
        }
    }
    return count;
}


/**
 * Function: LinkedList::sort
 * 
 * Searches through the LinkedLink and sorts the data inside the nodes with bubble sort
*/
void LinkedList::sort(){
    Node* pTemp = NULL;
    Node* pIndex = NULL;
    for(pTemp = pHead; pTemp != pTail; pTemp = pTemp->getNext()){
       for(pIndex = pTemp; pIndex != NULL; pIndex = pIndex->getNext()){
            if(pTemp->getData() > pIndex->getData()/* (pTemp > pIndex)*/){
                //cout << "(" << pTemp->getData() << ") > (" << pIndex->getData() << ")" << endl;
                swapText(pTemp, pIndex);
            }
        }
     }
}


/**
 * Function: LinkedList::insert
 * 
 * Private function that does all the inserting handy work
 * Likely not being used
 * 
 * inputs: node data
*/
void LinkedList::insert(const nodeType input){

}


/**
 * Function: LinkedList::extract
 * 
 * This is really the delete function
 * 
*/
void LinkedList::extract(){
    
}


/**
 * Function LinkedList::addToHead
 * 
 * Used to add a node to the start of a linkedlist
*/
void LinkedList::addToHead(const nodeType input){
    if(inLength == 0){
        Node* newNode = new Node(input, NULL, NULL);
        pTail = newNode;
        pHead = newNode;
        pCurrent = newNode;
        return;
    }
    Node* newNode = new Node(input, NULL, pHead);
    pHead->setNext(newNode);
    pHead = newNode;    
}


/**
 * Function LinkedList::addToTail
 * 
 * Used to add a node to the end of a linkedlist
*/
void LinkedList::addToTail(const nodeType input){
    // cout << input << " "; // Used to test the inputs
    if(inLength == 0){
        Node* newNode = new Node(input, NULL, NULL);
        pTail = newNode;
        pHead = newNode;
        pCurrent = newNode;
        return;
    }
    Node* newNode = new Node(input, NULL, pTail);
    pTail->setNext(newNode);
    pTail = newNode;
}


/**
 * Function LinkedList::addInteral
 * 
 * Used to add a node to the middle of a linkedlist
*/
void LinkedList::addInternal(const nodeType input){
    Node* newNode = new Node(input, pCurrent, pCurrent->getNext());
    pCurrent->setPrev( newNode );
    newNode->getPrev()->setNext(newNode); 
    pCurrent = pHead; 
}


Node::nodeType LinkedList::getData() const{
    return pCurrent->getData();
}

Node* LinkedList::getHead() const{
    return pHead;
}

Node* LinkedList::getCurrent() const{
    return pCurrent;
}

Node* LinkedList::getTail() const{
    return pTail;
}


void LinkedList::moveCurr(const Node* input){
    pCurrent = (Node *)input;
}

/**
 * 
 */
void LinkedList::swapText(Node* first, Node* second){ // This *should* be done by moving the pointers around, and it will be done later on, but this is easier to test
    /*
    Node* tmpNext = first->getNext();
    Node* tmpPrev = first->getPrev();
    // Node* tmp = first;

    first->setPrev(second->getPrev());
    first->setNext(second->getNext());
    // first = second;

    second->setPrev(tmpPrev);
    second->setNext(tmpNext);
    // second = tmp;
    */

    
    nodeType tmp = first->getData();
    first->setData(second->getData());
    second->setData(tmp);     
    
}


ostream& operator << (ostream& out, LinkedList& list){
    for(list.moveCurr(list.getHead()); list.getCurrent() != NULL; list.moveCurr(list.getCurrent()->getNext())){ 
        if(list.getCurrent()->getNext() != NULL)
            cout << (LinkedList::nodeType)list.getCurrent()->getData() << " "; // Space needed as that's how the output is requested
        else
            cout << (LinkedList::nodeType)list.getCurrent()->getData(); // Document also doesn't have spaces at the end
    }   
    return out; // ostream is great because I don't have to worry about append.
}





void operator += (LinkedList& first, LinkedList& second){
    for(second.moveCurr(second.getHead()); second.getCurrent() != NULL; second.moveCurr(second.getCurrent()->getNext())){
        first.add(second.getData());
    }
    return;
} 