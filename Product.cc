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

#include "Product.h"

int Product::nextProdId = 5001;

Product::Product(string n, string s, int u, float p, int d, int m, int y) : manufactured(d,m,y)
{ 
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
  
}

Product::~Product(){}

int    Product::getId()    { return id;    }
string Product::getName()  { return name;  }
string Product::getSize()  { return size;  }
int    Product::getUnits() { return units; }
float  Product::getPrice() { return price; }
void   Product::decrementUnits(){units--;}
void   Product::incrementUnits(int num) { units += num; }
Date&  Product::getExpDate(){ return expiry;}

void Product::toString(string& outStr)
{ 
   stringstream ss;
   ss << id   << "  " << setw(40) << name << "  "
         << setw(10) << size << "  " << setw(4)  << units << "    "         
         << "$" << ss.str()
     << setw(6) << fixed << setprecision(2) << price << "    ";
   
   outStr += ss.str();
   expiry.toString(outStr);
   ss.str("");
}


