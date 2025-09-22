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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;


/* Purpose: to simulate a role of a customer*/

#include "PurchArray.h"


class Customer
{
  public:
    Customer(string="Unknown");
    int         getId();
    string      getName();
    int         getPoints();
    PurchArray& getPurchases();
    float       getPriceTally();


   /*   Name:   makePurchase
     Purpose:   used to make a purchase
    */

    void        makePurchase(int);

   /*   Name:  hasItem
     Purpose:  checks if it has an item according to the id */

    bool        hasItem(int);

   
   /*    Name: incrementTally
      Purpose: increments the priceTally which is the total amount paid by the customer*/

    void        incrementTally(float);
    
    
  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
    PurchArray purchases;
    float      priceTally;
  
    
    
};

#endif
