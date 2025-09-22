#ifndef MISCGOODS_H
#define MISCGOODS_H

#include "NonPerishable.h"
#include "NonTaxable.h"


class  MiscGoods : public NonPerishable, public NonTaxable
{
   
  public:
    virtual ~MiscGoods();
    MiscGoods(string="Unknown", string="Unknown", int=0, float=0.0f, int=1, int=1, int=2015);
};

#endif
