#ifndef BOXINTERFACE_H
#define BOXINTERFACE_H

template <class ItemType> class BoxInterface
{
public:
    
    virtual void setItem (const ItemType &theItem) = 0;
    
    virtual ItemType getItem () const = 0;
    
};  // end BoxInterface
#endif
