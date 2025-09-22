#include "Order.h"

int Order::nextId = 6001;

Order::Order(Customer* c)
{
  id = nextId++;
  cust = c;
  price = 0.0;
}

bool Order::hasItem(int prodId)
{
  return purchases.isThere(prodId);
}

void Order::addPurchase(int prodId, float prodPrice)
{
  price+= prodPrice;
  
  if (hasItem(prodId))
  {
    Purchase* purchase = purchases.selectedById(prodId);
    purchase->incrementUnits();  
  }
  else
  { 
    
    Purchase* p = new Purchase(prodId);
    purchases.add(p);
  }

}

void Order::toString(string& outStr)
{
 
   stringstream ss;

   ss << endl << "Order Id: "<< id << "   Total Price: $" << fixed << setprecision(2) << price << "   Customer:  "<< cust->getName() << endl;
   outStr += ss.str();
   ss.str("");
   purchases.toString(outStr);

}
