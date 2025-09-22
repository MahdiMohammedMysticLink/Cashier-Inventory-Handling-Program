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

#include <cstdlib>
#include "InvControl.h"


InvControl::InvControl()
{
  initProducts();
  initCustomers();
}

void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) 
  {
    view.printUsageError();
    exit(1);
  }

  string option(argv[1]);

  if (option == "-a") 
  {		// Admin menu
    processAdmin();
  }
  else if (option == "-c") 
  {	// Cashier menu
    processCashier();
  }
  else 
  {
    view.printUsageError();
    exit(1);
  }
}

void InvControl::processAdmin()
{
  int    choice, option, lSpan, d, m, y;
  string prodName, prodSize;
  int    prodUnits, prodId, amount;
  float  prodPrice;
  Product* prod;

  while (1) 
  {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) 
    {		// add new product
      view.promptForStr("Product name", prodName);
      view.promptForStr("Product size", prodSize);
      view.promptForInt("# units", prodUnits);
      view.promptForFloat("Price", prodPrice);
      view.promptForInt("Manufacture Year", y);
      view.promptForInt("Manufacture Month", m);
      view.promptForInt("Manufacture day", d);
      view.printCategories(option, lSpan);
      
      switch(option){
        case 1:
          prod = new Dairy(prodName, prodSize, prodUnits, prodPrice, d, m, y, lSpan);
          store.addProd(prod);
          break;
        case 2:
          prod = new CoffeeTea(prodName, prodSize, prodUnits, prodPrice, d, m, y);
          store.addProd(prod);
          break;
        case 3:
          prod = new Bakery(prodName, prodSize, prodUnits, prodPrice, d, m, y, lSpan);
          store.addProd(prod);
          break;
        case 4:
          prod = new Meat(prodName, prodSize, prodUnits, prodPrice, d, m, y, lSpan);
          store.addProd(prod);
          break;
        case 5:
          prod = new MiscGoods(prodName, prodSize, prodUnits, prodPrice, d, m, y);
          store.addProd(prod);
          break;
        default:
          break;
      }
      /*Product* prod = new Product(prodName, prodSize, prodUnits, prodPrice);
      store.addProd(prod);*/
      view.pause();
    }
    else if (choice == 2)
    {	// add inventory
       while(1)
       {
         view.promptForInt("Select a product Id (terminate by 0)", prodId);
           
         if(prodId == 0)
           break;
           
         if (!store.isProductThere(prodId))
         {
           view.printError("Product does not exist");
           continue;
      
         }
         view.promptForInt("Enter number of units", prodUnits);
         
        if (!store.incrementProdUnits(prodId, prodUnits))
          view.printError("Units must be greater than zero");
          
       }
    }
    else if (choice == 3)
    {	// remove inventory
       while(1)
       {
         view.promptForInt("Select a product Id (terminate by 0)", prodId);
           
         if(prodId == 0)
           break;
           
         if (!store.removeProd(prodId))
         {
           view.printError("Product does not exist");
           continue;
         }    
       }
    }
    else if (choice == 4) 
    {	// print inventory
      view.printStock(store.getStock());
      view.pause();
    }
    else if (choice == 5) 
    {// print customers
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else if (choice == 6)
    {
      OrderArray arr;
      orderServer.retrieve(arr);
      view.printOrders(arr);
      view.pause();
    }
    else 
    {
      break;
    }
  }
}

void InvControl::processCashier()
{
  int choice;
  int prodId, custId;
  float summary = 0.0;
  float prodPrice, origPrice;
  prodPrice = 0.0;
  origPrice = 0.0;
  float origSummary = 0.0;
  
  while (1) 
  {
    choice = -1;
    view.cashierMenu(choice);
     
    if (choice == 1) 
    {
       
      view.promptForInt("Enter customer Id", custId);
      if (!store.isCustomerThere(custId))
      {
        view.printError("Customer does not exist");
        continue;
      
      }
      
      Order* order = new Order(store.selectedCustomer(custId));
      while(1)
      {
        
        view.promptForInt("Select a product Id (terminate by 0)", prodId);
           
        if(prodId == 0)
          break;
           
        if (!store.isProductThere(prodId))
        {
          view.printError("Product does not exist");
          continue;
      
        }
       
        if (!store.makePurchase(prodId, custId, prodPrice, origPrice))
        {
          view.printError("Product out of stock!");
          continue;
        }
        
      //  view.printCustomerPurchases(custId, store.getCustomers());
        summary+= prodPrice;
        origSummary+=origPrice;
        order->addPurchase(prodId, prodPrice);
      }
      if(summary == 0.0)
      {
        delete order;
      }
      else
      {
      orderServer.update(order);
      }
      view.printPurchaseSummary(summary, origSummary ); 
      summary=0.0;
      origSummary = 0.0;
      
    }
    else if (choice == 2) 
    {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) 
    {	// print inventory and customers
      OrderArray arr;
      orderServer.retrieve(arr);
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());
      view.printOrders(arr);
      view.pause();
    }
    else 
    {
      break;
    }
  }
}

void InvControl::initProducts()
{
  
  Product* prod;

//the empty case
  prod = new Dairy("Milk", "1 L", 10, 3.99f, 24, 12, 2005, 7);
  store.addProd(prod);


//front
  prod = new Meat("Beef", "2 L", 9, 8.99f, 27, 5, 2015, 9);
  store.addProd(prod);

  prod = new MiscGoods("Daisy's Spicy Chili", "150 g", 8, 1.29f,  28, 2, 2016);
  store.addProd(prod);
  
  prod = new CoffeeTea("Lightening Bolt Instant Coffee", "150 g", 15, 4.99f, 28, 2, 2012);
  store.addProd(prod);
  
  prod = new Bakery("It's Your Bday Chocolate Cake", "500 g", 6, 12.99f, 31, 12, 2016, 1);
  store.addProd(prod);
  
  
  prod = new Meat("Garfield Hamburger Patties", "900 g", 3, 11.99f, 20, 11, 2013, 2);
  store.addProd(prod);

  prod = new MiscGoods("Munchies BBQ Chips", "250 g", 2, 2.99f, 8, 8, 2008);
  store.addProd(prod);

  prod = new MiscGoods("Dogbert Sweet and Spicy Popcorn", "180 g", 0, 2.29f, 9, 9 ,2009);
  store.addProd(prod);

  prod = new Bakery("Daisy's Maple Baked Beans", "220 g", 7, 2.49f, 7, 7, 2014, 8);
  store.addProd(prod);

  prod = new Meat("Marmaduke Hot Dogs", "12-pack", 6, 4.99f, 19, 12, 2015, 5);
  store.addProd(prod);

//middle
  prod = new Dairy("Chunky Munkey Ice Cream", "2 L", 7, 2.97f, 19, 7, 2013, 4);
  store.addProd(prod);

  prod = new Meat("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f, 18, 7, 2014, 8);
  store.addProd(prod);

  prod = new Meat("Happy Baker's Hamburger buns", "8-pack", 4, 3.99f, 16, 6, 2016, 10);
  store.addProd(prod);

  prod = new MiscGoods("Munchies Ketchup Chips", "250 g", 7, 2.99f, 18, 9, 2015);
  store.addProd(prod);

  prod = new MiscGoods("Dogbert Salted Chips", "210 g", 9, 1.99f, 7, 8, 2014);
  store.addProd(prod);
 
 
//end
  prod = new Dairy("Moo-cow 2% milk", "1 L", 11, 2.99f, 7, 9, 2015, 8);
  store.addProd(prod);

  prod = new Dairy("Moo-cow 2% milk", "4 L", 12, 4.99f, 8, 9, 2011, 9);
  store.addProd(prod);

  prod = new CoffeeTea("Moo-cow 5% coffee cream", "250 ml", 13, 1.49f, 20, 12, 2008);
  store.addProd(prod);

  prod = new Bakery("CupCake", "400 g", 14, 5.49f, 2, 2, 2015); //Testing default date and life span value
  store.addProd(prod);

  prod = new CoffeeTea("Lightening Bolt Decaf Coffee", "100 g", 16, 4.99f, 19, 5, 2007);
  store.addProd(prod);


}

void InvControl::initCustomers()
{

  Customer* cust;

  cust = new Customer("Starbuck");
  store.addCust(cust);
  
  cust = new Customer("Apollo");
  store.addCust(cust);
  
  cust = new Customer("Boomer");
  store.addCust(cust);
  
  cust = new Customer("Athena");
  store.addCust(cust);
  
  cust = new Customer("Helo");
  store.addCust(cust);
  
  cust = new Customer("Crashdown");
  store.addCust(cust);
  
  cust = new Customer("Hotdog");
  store.addCust(cust);
  
  cust = new Customer("Kat");
  store.addCust(cust);
  
  cust = new Customer("Chuckles");
  store.addCust(cust);
  
  cust = new Customer("Racetrack");
  store.addCust(cust);
  
}

