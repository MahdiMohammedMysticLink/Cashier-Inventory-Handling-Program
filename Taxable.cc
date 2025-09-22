#include "Taxable.h"

float Taxable::computeTax()
{
  return (price*HST_TAX);
}
