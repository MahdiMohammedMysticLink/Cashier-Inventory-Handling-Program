#ifndef COFFEETEA_H
#define COFFEETEA_H

#include "NonPerishable.h"
#include "Taxable.h"

class  CoffeeTea : public NonPerishable, public Taxable
{
  
  public:
    virtual ~CoffeeTea();
    CoffeeTea(string="Unknown", string="Unknown", int=0, float=0.0f, int=1, int=1, int=2015);

};

#endif
