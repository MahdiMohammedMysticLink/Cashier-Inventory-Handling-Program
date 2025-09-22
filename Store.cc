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


#include "Store.h"

ProdList& Store::getStock()     { return stock; }

CustArray& Store::getCustomers() { return customers; }

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

bool Store::removeProd(int id)
{      

  if (isProductThere(id))
  {
    return stock.remove(selectedProduct(id));
  }
  else
  {
    return false;
  }
}

Product* Store::selectedProduct(int id){
  return stock.selectedById(id);
}

bool Store::isProductThere(int id)
{
  return stock.isThere(id);

}

void Store::addCust(Customer* cust)
{
  customers.add(cust);
}

Customer* Store::selectedCustomer(int id)
{
  return customers.selectedById(id);
}

bool Store::isCustomerThere(int id)
{
  customers.isThere(id);
}


bool Store::makePurchase(int prodId, int custId, float& prodPrice, float& origPrice)
{

  Product* prod  = selectedProduct(prodId);
  if(prod->getUnits() < 1) 
    return false;

  origPrice = prod->getPrice();
  prodPrice = prod->getPrice() + prod->computeTax();
  Customer* cust = selectedCustomer(custId);
  cust->makePurchase(prodId);
  prod->decrementUnits();
  stock.reorg();
  cust->incrementTally(prod->getPrice());
  
  
  return true;
}

bool Store::incrementProdUnits(int id, int units)
{

  if(units<1)
    return false;

  Product* prod  = selectedProduct(id);
  prod->incrementUnits(units);
  stock.reorg();
  
  return true;

}


