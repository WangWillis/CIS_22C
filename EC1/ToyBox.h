#ifndef _TOY_BOX
#define _TOY_BOX
#include "PlainBox.h"

enum Color
{ BLACK, RED, BLUE, GREEN, YELLOW, WHITE };

template < class ItemType > class ToyBox:public PlainBox < ItemType >
{
private:
  Color boxColor;

public:
  ToyBox ();
  ToyBox (const Color & theColor);

  ToyBox (const ItemType & theItem, const Color & theColor);

  Color getColor () const;

};  // end ToyBox

//Template class definitions can not be seperate from its declrations since the compiler needs to know template definitions and type
template <class ItemType>ToyBox<ItemType>::ToyBox()
{
    PlainBox < ItemType > ();
    boxColor = BLACK;
}   // end default constructor

template < class ItemType > ToyBox < ItemType >::ToyBox (const Color & theColor)
{
    PlainBox < ItemType > ();
    boxColor = theColor;
}   // end constructor

template < class ItemType > ToyBox < ItemType >::ToyBox (const ItemType & theItem, const Color & theColor)
{
    PlainBox <ItemType > ();

    PlainBox < ItemType >::setItem (theItem);
    boxColor = theColor;
}   // end constructor
template < class ItemType > Color ToyBox < ItemType >::getColor () const
{
  return boxColor;
}   // end getColor

#endif