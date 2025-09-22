#ifndef ORDERSERVER_H
#define ORDERSERVER_H

#include "OrderArray.h"

class OrderServer
{

  public:
    ~OrderServer();
    /* 
       Name:  update
    Purpose:  adds an order to orders
    */
    void update(Order*);

     /* 
       Name:  retrieve
    Purpose:  copies orders to the output array
    */
    void retrieve(OrderArray&);

  private:
    OrderArray orders;


};
#endif
