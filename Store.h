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

#ifndef STORE_H
#define STORE_H

#include "ProdList.h"
#include "CustArray.h"

/*Purpose: To simulate a store and provide the tools to make a transaction and provide needed information of a store*/

class Store
{
  public:
  
    ProdList& getStock();
    CustArray& getCustomers();

    /*   Name:   addProd
      Purpose:   adds a product to stock*/

    void       addProd(Product*);
    
    /*   Name:  remove
      Purpose:  removes a product from the list and returns true if an item has been removed or false otherwise */
     bool      removeProd(int);


    /*   Name:   addCust
      Purpose:   adds a customer to costumers*/

    void       addCust(Customer*);

  
    /*   Name:   isCustomerThere
      Purpose:   checks if a customer exists in customers*/

    bool       isCustomerThere(int);


    /*   Name:  isProductThere
      Purpose:  checks if a product exists in stock*/

    bool       isProductThere(int);


    /*   Name:  makePurchase
      Purpose:  makes a transaction and required changes to the product units sold,
                allocating points to the customer, incrementing priceTally of Customer,
                initializing the purchase when necessary, and adding it to the customer's 
                record of purchases. It also registers the original product price as an out parameter,
                and a separate cost with the taxed amount. 
                Also checks if there is a valid product unit amount.*/
                                                              
    bool       makePurchase(int, int, float&, float&);
    
    
    /*   Name:  incrementProdUnits(int, int)
      Purpose:  Increments the units of the product and checks that the units entered 
                is greater than zero */
    
    bool       incrementProdUnits(int, int);

   
    /*    Name: selectedCustomer
       Purpose: returns the selected customer reference based on the customer id.*/ 
  
    Customer*  selectedCustomer(int); 
  
  private:
    ProdList   stock;
    CustArray  customers;
  

    /*    Name: selectedProduct
       Purpose: returns the selected product reference based on the product id.*/ 
  
    Product*   selectedProduct(int);

};

#endif
