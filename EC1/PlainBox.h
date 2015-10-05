#ifndef _PLAIN_BOX
#define _PLAIN_BOX
#include "BoxInterface.h"
template < class ItemType >    // Indicates this is a template definition
// Declaration for the class PlainBox

class PlainBox:public BoxInterface <ItemType>
{
  private:
// Data fi eld
  ItemType item;

  public:
// Default constructor
  PlainBox ();

// Parameterized constructor
  PlainBox (const ItemType &theItem);

// Mutator method that can change the value of the data fi eld
virtual void setItem (const ItemType &theItem);

// Accessor method to get the value of the data fi eld
virtual ItemType getItem () const;

};  // end PlainBox

//Template class definitions can not be seperate from its declrations since the compiler needs to know template definitions and type
template < class ItemType >
PlainBox < ItemType >::PlainBox ()
{
}   // end default constructor

template < class ItemType >
PlainBox < ItemType >::PlainBox (const ItemType & theItem)
{
    item = theItem;
} 
template < class ItemType >
void PlainBox<ItemType>::setItem (const ItemType &theItem)
{
    item = theItem;
}   // end setItem

template < class ItemType >
ItemType PlainBox<ItemType>::getItem () const
{
    return item;
}   // end getItem

#endif