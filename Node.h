#ifndef BEN_NODE
#define BEN_NODE
class Node{
    public:
        typedef string nodeType;

        /**
         * Pointer mutators and accessors 
        */
        void setNext(const Node* pNext);
        void setPrev(const Node* pPrev);
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
        Node(const nodeType input, Node* pNext = NULL, Node* pPrev = NULL);
        Node();
        ~Node();
    private:
        nodeType* data;
};

#endif