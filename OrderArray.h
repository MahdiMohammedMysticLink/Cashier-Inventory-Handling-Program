



#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "defs.h"
#include "Order.h"

/*Purpose: To simulate a collection of orders */

class OrderArray
{
  public:
    OrderArray();
    void cleanup();

   /*   Name:  add
     Purpose:  adds a order to elements*/

    void add(Order*);

   /*  Name:  toString
    Purpose:  store data in a string*/

    void toString(string&);

    int getSize();

    
   /*  Name:  get
    Purpose:  get's an order from elements based on index*/
    Order* get(int);
   
  private:
    Order* elements[MAX_ARR];
    int size;

};

#endif
