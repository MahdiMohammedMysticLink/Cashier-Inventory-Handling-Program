#ifndef PURCHARRAY_H
#define PURCHARRAY_H

#include "defs.h"
#include "Purchase.h"

/*Purpose: To simulate a collection of purchases and tools to access the right purchase*/

class PurchArray
{
  public:
    PurchArray();
    ~PurchArray();

   /*   Name:  add
     Purpose:  adds a purchase to elements*/

    void add(Purchase*);
   
   /*   Name:  get
     Purpose:  returns a purchase reference based on index from elements */

    Purchase* get(int);

    int getSize();

    /*  Name: isThere
     Purpose: checks if a product has been bought already based on id of the product*/

    bool isThere(int);

    /*   Name: selectedById(int);
      Purpose: returns a purchase reference for the purchase already made*/

    Purchase* selectedById(int);

    /*  Name: toString
     Purpose: store data in a string */   

    void toString(string&);
   
  private:
    Purchase* elements[MAX_ARR];
    int size;
};

#endif




