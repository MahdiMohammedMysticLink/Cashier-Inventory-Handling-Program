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

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iomanip>
#include <sstream>
#include "Date.h"
using namespace std;


/*Purpose: To simulate a product and provide tools to deal with product information*/

class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f, int=1, int=1, int=2015);
    virtual ~Product();
    int    getId();
    string getName();
    string getSize();
    int    getUnits();
    float  getPrice();
    Date&  getExpDate();

   /*    Name: computeTax
      Purpose: computes tax */

    virtual float   computeTax() = 0;
    
    /*   Name: toString
      Purpose: store data in a string */
       
    void   toString(string&);

    /*   Name: decrementUnits
      Purpose: decrements the units of the product */

    void decrementUnits();
    
    /*   Name: incrementUnits(int);
      Purpose: Increments the units of the product */
      
    void incrementUnits(int);


  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    Date       manufactured;
    Date       expiry;
    
    /*   Name:   computeExpDate
      Purpose:   calculates expiry date */

    virtual void   computeExpDate() = 0;
};

#endif
