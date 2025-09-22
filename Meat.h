#ifndef MEAT_H
#define MEAT_H

#include "Perishable.h"
#include "NonTaxable.h"

class  Meat : public Perishable, public NonTaxable
{

  public:
    virtual ~Meat();
    Meat(string="Unknown", string="Unknown", int=0, float=0.0f, int=1, int=1, int=2015, int=14);

};

#endif
