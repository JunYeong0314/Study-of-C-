#ifndef ChainNode_hpp
#define ChainNode_hpp

template <class T> class Chain;

template <class T>
class ChainNode{
    friend class Chain<T>;
private:
    T data;
    ChainNode *link;
};

template <class T>
class Chain{
public:
    Chain(){
        first = 0;
    }
private:
    ChainNode<T> *first;
};

template <class T>
class ChainIterator{
public:
    ChainIterator(ChainNode<T>* startNode = 0){
        current = startNode;
    }
    T& operator*() const{
    return current -> data;
    }
    
    T* operator->() const{
        return &current -> data;
    }
    
    ChainIterator& operator++(){
        current = current->link;
        return *this;
    }
    
    ChainIterator operator++(int){
        ChainIterator old = *this;
        current = current->link;
        return old;
    }
    
    bool operator != (const ChainIterator right) const{
        return current != right.current;
    }
    
    bool operator == (const ChainIterator right) const{
        return current == right.current;
    }
private:
    ChainNode<T>* current;
};

#endif /* ChainNode_hpp */
