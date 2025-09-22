#ifndef PURCHASE_H
#define PURCHASE_H



#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

#include "defs.h"
#include "Purchase.h"

/*Purpose: Simulate a purchase and provides the right tools regarding purchase informatiaon*/


class Purchase
{

  public:
    Purchase();
    Purchase(int);
    int getId();
    void setId(int);

    /*   Name:  incrementUnits
      Purpose:  increments the units of the purchase */

    void incrementUnits();
    int getUnits();

    
    /*  Name: toString
     Purpose: store data in a string */   

    void toString(string&);

 protected:
    int id;
    int units;


};


#endif
