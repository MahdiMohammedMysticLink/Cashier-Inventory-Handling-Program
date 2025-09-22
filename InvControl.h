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

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"
#include "OrderServer.h"
#include "Dairy.h"
#include "CoffeeTea.h"
#include "Bakery.h"
#include "Meat.h"
#include "MiscGoods.h"


/* Purpose: To provide the control flow of dealing with the inventory in a store as a cashier or an adminstrator */


class InvControl
{
  public:
    InvControl();

    /*   Name:  launch
      Purpose:  launches the program based on run time input paramaters and put's the user in the right process. */

    void launch(int, char*[]);
  private:
    Store     store;
    UI        view;
    OrderServer orderServer;
    
    /*   Name:  initProducts
      Purpose:  initializes products and adds them to the store's stock*/

    void      initProducts();
    
    /*   Name:  initCustomers
      Purpose:  initializes customers and adds them to the store's customers*/

    void      initCustomers();

    /*   Name:  processAdmin
      Purpose:  runs the administrator process and options and makes the necessary changes to store*/

    void      processAdmin();


    /*   Name:  processAdmin
      Purpose:  runs the cashier process and option and makes the necessary changes to store*/

    void      processCashier();
};
#endif
