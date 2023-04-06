#include<vector>
#include"BagInterface.h"
#include"Node.h"
template<typename ItemType>
class LinkedBag :public BagInterface{
private:
    Node<ItemType>* head;
    int itemCount;
    Node<ItemType>* findNode(const ItemType& item);
public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& bag);// We need deep copy
    virtual ~LinkedBag(); //virtual!!
    int getCurrentSize() const override;
    bool empty() const override;
    bool add(const ItemType& item) override;
    bool remove(const ItemType& item) override;
    void clear() override;
    int getFrequencyOf(const ItemType& item) const override;
    bool contain(const ItemType& item) const override;
    void print() const override;
    std::vector<ItemType> toVector();
    
};
template<typename ItemType>
Node<ItemType>* LinkedBag<ItemType>::findNode(const ItemType& item){
    Node<ItemType>* locater = head;
    for(;locater!=nullptr;locater = locater->next){
        if(locater->item == item)
            return locater;
    }
    return nullptr;
    //finded! return location, if not, return nullptr.
}
template<typename ItemType>
LinkedBag<ItemType>::LinkedBag():head(nullptr), itemCount(0)
{

}
template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& bag){
    this->itemCount = bag.itemCount;
    if(bag.head=nullptr){
        this->head = nullptr;
    }else{
        this->head = new Node<ItemType>();
        Node<ItemType>* oldChainAddress = bag.head;
        Node<ItemType>* newChainAddress = this->head;
        for(;oldChainAddress->next!=nullptr;oldChainAddress = oldChainAddress->next){
            newChainAddress->item = oldChainAddress->item;
            newChainAddress->next = new Node<ItemType>();
            newChainAddress = newChainAddress->next;
        }
            newChainAddress->item = oldChainAddress->item;
            newChainAddress->next = nullptr;
    }
}
template<typename ItemType>
LinkedBag<ItemType>::~LinkedBag(){
    clear();
}
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
    return itemCount;
}
template<typename ItemType>
bool LinkedBag<ItemType>::empty() const{
    return itemCount==0;
}
template<typename ItemType>
bool LinkedBag<ItemType>::add(const ItemType& item){
    //尚未考慮 0個NODE時使用add
    Node<ItemType>newNode(item, head->next);
    head->next = &newNode;
    itemCount++;
}
template<typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& item){

    if(findNode()==nullptr){
        return false;
    }else{
        Node<ItemType>* currentAddress = findNode(item);
        currentAddress->item = currentAddress->item;
        currentAddress = head;
        head = head->next;
        delete currentAddress;
        itemCount--;
    }
}
template<typename ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector(){
    Node<ItemType>* locator = head;
    std::vector<ItemType> bagContent;
    for(;locator!=nullptr;locator=locator->next){
        bagContent.push_back(locator->item);
    }
    return bagContent;
}
template<typename ItemType>
void LinkedBag<ItemType>::clear(){
    Node<ItemType> currentAddress = head;
    head = head->next;
    for(;head!=nullptr;head = head->next){
        delete currentAddress;
        currentAddress = head;
    }
    itemCount = 0;
}
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& item) const{
    int Frequency = 0;
    for(Node<ItemType>* locator;locator!=nullptr;locator=locator->next){
        if(locator->item==item)
            Frequency++;
    }
    return Frequency;
}
template<typename ItemType>
bool LinkedBag<ItemType>::contain(const ItemType& item) const{
    return findNode(item) != nullptr;
}