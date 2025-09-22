#ifndef NONTAXABLE_H
#define NONTAXABLE_H

#include "Product.h"

class  NonTaxable : virtual public Product
{
  protected:
    virtual ~NonTaxable();
    float computeTax();
    
};

#endif
