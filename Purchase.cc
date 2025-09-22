#include "Purchase.h"


Purchase::Purchase()
{
id = -1;
units = 0;
}


Purchase::Purchase(int prodId)
{
id = prodId;
units = 1; //because this is only used when making first purchase
}


int Purchase::getId(){ return id;}

int Purchase::getUnits(){return units;}

void Purchase::incrementUnits(){ units++;}

void Purchase::toString(string& outStr)
{
  stringstream ss;
  ss <<setw(20)<<id << setw(7) << units << endl;
  outStr += ss.str();
  ss.str("");
  

}


