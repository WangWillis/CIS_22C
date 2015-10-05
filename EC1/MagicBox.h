#ifndef MAGICBOX_H
#define MAGICBOX_H
#include "PlainBox.h"
template < class ItemType > class MagicBox:public PlainBox < ItemType >
{
private:
  bool firstItemStored;

public:
	MagicBox ();
	MagicBox (const ItemType & theItem);

	void setItem (const ItemType & theItem);

};  // end MagicBox

//Template class definitions can not be seperate from its declrations since the compiler needs to know template definitions and type
template < class ItemType > MagicBox < ItemType >::MagicBox ()
{
    PlainBox < ItemType > ();
     firstItemStored = false;	// Box has no magic initially
}   // end default constructor

template < class ItemType > MagicBox < ItemType >::MagicBox (const ItemType & theItem)
{
    firstItemStored = false;	// Box has no magic initially
    
    setItem (theItem);
    // Box has magic now
}   // end constructor
template < class ItemType > void MagicBox<ItemType>::setItem (const ItemType & theItem)
{
    if (!firstItemStored)
    {
        PlainBox < ItemType >::setItem (theItem);
        firstItemStored = true;	// Box now has magic
    }	// end if
}   // end setItem
#endif
