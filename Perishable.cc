#include "Perishable.h"


Perishable::Perishable(int l) : lifespan(l)
{
  computeExpDate();
}
Perishable::~Perishable(){}



void Perishable::computeExpDate()
{
  expiry = manufactured + lifespan;

}
