#ifndef DAIRY_H
#define DAIRY_H

#include "Perishable.h"
#include "NonTaxable.h"

class Dairy : public Perishable, public NonTaxable
{
  public:
    virtual ~Dairy();
    Dairy(string="Unknown", string="Unknown", int=0, float=0.0f, int=1, int=1, int=2015, int=14);

};

#endif
