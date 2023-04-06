#ifndef BAG_INTERFACE_H
#define BAG_INTERFACE_H
template<typename ItemType>
class BagInterface{
public:
    virtual int getCurrentSize() const = 0;
    virtual bool empty() const = 0;
    virtual bool add(const ItemType& item) = 0;
    virtual bool remove(const ItemType& item) = 0;
    virtual void clear() = 0;
    virtual int getFrequencyOf(const ItemType& item) const = 0;
    virtual bool contain(const ItemType& item) const = 0;
    virtual void print() const = 0;
};
#endif