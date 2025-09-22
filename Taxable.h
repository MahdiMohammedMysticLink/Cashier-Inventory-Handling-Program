#ifndef TAXABLE_H
#define TAXABLE_H

#include "Product.h"
#include "defs.h"

class Taxable : virtual public Product
{
  protected:
    float computeTax();
    
};

#endif
