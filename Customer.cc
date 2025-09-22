

/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cmath>
#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n)
{
  id         = nextCustId++;
  name       = n;
  points     = 0;
  priceTally = 0;
  
 
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }


PurchArray& Customer::getPurchases(){return purchases;}


bool Customer::hasItem (int id) {

  if (purchases.getSize() == 0) 
     return false;
  return purchases.isThere(id); 

}





float Customer::getPriceTally()
{
  return priceTally; 
}


void Customer::incrementTally(float price)
{
  priceTally += price;
  points = round(priceTally); 
}


void Customer::makePurchase(int id)
{

  if (hasItem(id))
  {
    Purchase* purchase = purchases.selectedById(id);
    purchase->incrementUnits();  
  }
  else
  { 
    
    Purchase* p = new Purchase(id);
    purchases.add(p);
  }

}




