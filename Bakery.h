#ifndef BAKERY_H
#define BAKERY_H

#include "Perishable.h"
#include "Taxable.h"

class  Bakery : public Perishable, public Taxable
{
  public:
    virtual ~Bakery();
    Bakery(string="Unknown", string="Unknown", int=0, float=0.0f, int=1, int=1, int=2015, int=14);

};

#endif
