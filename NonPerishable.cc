#include "NonPerishable.h"


NonPerishable::NonPerishable()
{
  computeExpDate();
}


void NonPerishable::computeExpDate()
{
  expiry = manufactured + LIFE_SPAN;
}
