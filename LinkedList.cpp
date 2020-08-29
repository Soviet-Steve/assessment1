#include "LinkedList.h"
LinkedList::LinkedList(){
    length = 0U;
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

} 

/**
 * Fuction: LinkedList::add 
 * 
 * Gets input data based on the nodeType searches for and then creates and add a node to the linked list
 * 
 * input: node data
*/
void LinkedList::add(const nodeType input){

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
uint32_t LinkedList::count(const nodeType input) const{

}


/**
 * Function: LinkedList::sort
 * 
 * Searches through the LinkedLink and sorts the data inside the nodes with bubble sort
*/
void LinkedList::sort(){

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
void LinkedList::addToHead(){

}


/**
 * Function LinkedList::addToTail
 * 
 * Used to add a node to the end of a linkedlist
*/
void LinkedList::addToTail(){

}


/**
 * Function LinkedList::addInteral
 * 
 * Used to add a node to the middle of a linkedlist
*/
void LinkedList::addInternal(){

}


ostream& operator << (ostream& out, const LinkedList& list){
    for(list->pCurrent = list->pHead; list->pCurrent != NULL; list->pCurrent = list->pCurrent->getNext();){ // TODO: Double check pointers, also gogarty is a mad lad
        if(list->pCurrent->getNext() != NULL)
            out << list->pCurrent->getData() << " "; // Space needed as that's how the output is requested
        else
            out << list->pCurrent->getData(); // Document also doesn't have spaces at the end
    }   
    return out; // ostream is great because I don't have to worry about append.
}

void operator += (LinkedList& head, const LinkedList& tail){
    for(tail->pCurrent = tail->pHead; tail->pCurrent != NULL; tail->pCurrent = tail->pCurrent->getNext();) // This part "rotates" through the linked list
        head->add(tail->pCurrent->getData()); // Seems really ineffient to just copy the data like this but... it works?
    return;
} 