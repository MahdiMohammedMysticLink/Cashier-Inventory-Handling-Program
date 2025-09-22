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

#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"


/*Purpose: To simulate a collection of customers and required functions to access the right customer*/

class CustArray
{
  public:
    CustArray();
    ~CustArray();
     /*  Name:  add
      Purpose:  adds a customer to elements */

    void add(Customer*);
   
     /*  Name:  get
      Purpose:  get's a customer reference from elements based on index*/

    Customer* get(int);
    int getSize();
   
     /* Name:   isThere
     Purpose:   checks if the customer is in elements based on id*/

    bool isThere(int);

    /*  Name:   selectedById
     Purpose:   returns a customer reference based on the id*/

    Customer* selectedById(int);
  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif

