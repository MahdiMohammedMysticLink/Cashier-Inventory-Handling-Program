#ifndef ORDER_H
#define ORDER_H


#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
//#include "PurchArray.h"
#include "Customer.h"


class Order
{
  public:
    Order(Customer*);
    
    /*  Name: addPurchase
     Purpose: Adds a purchase to the order */
   
    void addPurchase(int, float);
   
    /*  Name: toString
     Purpose: store data in a string */   
 
    void toString(string&);

    
  protected:
    static int nextId;
    int id;
    float price;
    Customer* cust;
    PurchArray purchases;
   
    /*  Name: hasItem
     Purpose: Checks if it has the purchase */
    bool hasItem(int);    

};


#endif
