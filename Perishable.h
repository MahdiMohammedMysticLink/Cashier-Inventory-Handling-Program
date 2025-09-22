#ifndef PERISHABLE_H
#define PERISHABLE_H

#include "Product.h"


class  Perishable : virtual public Product
{
  protected:
    virtual ~Perishable();
    Perishable(int=14);
    void computeExpDate();
    int lifespan;
    
};

#endif
