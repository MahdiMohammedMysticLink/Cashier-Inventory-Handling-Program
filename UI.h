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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdList.h"
#include "CustArray.h" 
#include "OrderArray.h"

/* Purpose: To provide the right tools to prompt the user and print information to the user as well as providing tools to deal with 
            possible errors */

class UI
{
  public:

    /*Name: adminMenu 
     *Purpose: Prompts the user for Administrator choice options*/
     
     void adminMenu(int&);
     

    /*Name:       cashierMenu 
     *Purpose:    Prompts the user for Cashier options */

    void cashierMenu(int&);
    

    /*Name:       promptForInt
     *Purpose:    Prompts the user for an int */

    void promptForInt(string, int&);
    

    /*Name:       promptForString
     *Purpose:    Prompts the user for a string */

    void promptForStr(string, string&);
    
    
    /*Name:       promptForFloat
     *Purpose:    Prompts the user for a float*/

    void promptForFloat(string, float&);
    
   
    /*   Name:    printError
     *Purpose:    Prints any string as an error*/

    void printError(string);
    
    
    /*   Name:    printUsageError
      Purpose:    Prints a usage message*/

    void printUsageError();
    

    /*   Name:    printStock
      Purpose:    prints all the products in stock*/

    void printStock(ProdList&);

   
    /*   Name:    printCustomers
      Purpose:    prints all the customers*/

    void printCustomers(CustArray&);
    
    
    /*   Name:    pause
      Purpose:    pauses the program and continues once the user enters the <ENTER> key*/

    void pause();
    

    /*   Name:    printCustomerPurchases
      Purpose:    prints the purchases made by the customer and customer information*/

  // void printCustomerPurchases(int, CustArray&);


    /*   Name:    printPurchaseSummary
      Purpose:    prints a summary of the purchases*/

    void printPurchaseSummary(float, float);
    
    
    /*   Name:    printOrders
      Purpose:    prints a summary of the orders*/
    void printOrders(OrderArray&);
    
    
    /*   Name:    printCategories
      Purpose:    Prompts the user for options to add a new product*/
    void printCategories(int&, int&);  
    
     
  private:
    
    /*   Name:    readInt
      Purpose:    reads an int from the user*/

    int    readInt();

    
    /*   Name:    printOnlyThePurchases
      Purpose:    prints the purchases of a customer*/

    void printOnlyThePurchases(Customer*);


};

#endif
