#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include "Product.h"
#include "defs.h"

class  NonPerishable : virtual public Product
{
  protected:
    NonPerishable();
    void computeExpDate();
    
};

#endif
