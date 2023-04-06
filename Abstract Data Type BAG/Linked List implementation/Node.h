#ifndef Node_H
#define Node_H
template<typename ItemType>
class LinkedBag; //Forward Declaration Objects/Enums
template<typename ItemType>
class Node{
friend LinkedBag<ItemType>;
private:
    ItemType item;
    Node<ItemType>* next;
public:
    Node();
    Node(const ItemType& item);
    Node(const ItemType& item, Node<ItemType>* next);
    void setItem(const ItemType& item);
    void setNext(Node<ItemType>* next);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};
template<typename ItemType>
Node<ItemType>::Node():next(nullptr)
{
}
template<typename ItemType>
Node<ItemType>::Node(const ItemType& item):Node(item,nullptr)
{
}
template<typename ItemType>
Node<ItemType>::Node(const ItemType& item,Node<ItemType>* next):item(item),next(next)
{
}
template<typename ItemType>
void Node<ItemType>::setItem(const ItemType& item)  
{
    this->item = item;
}
template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* next)
{
    this->next = next;
}
template<typename ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}
template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext()  const
{
    return next;
}
#endif