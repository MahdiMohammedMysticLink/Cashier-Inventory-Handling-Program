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

#ifndef PRODARRAY_H
#define PRODARRAY_H

#include "defs.h"
#include "Product.h"


/*Purpose: To simulate a collection of products and give the tools to access the right product*/

class ProdList
{
  public:
    ProdList();
    ~ProdList();
    
    class Node
    {
     	friend class ProdList;
       
     	private:
       	Node* prev;
       	Node* next;
       	Product* data;

   	};

     /*  Name:  add
      Purpose:  adds a product to the list in ascending order of product expiry date */

    void add(Product*);
    
     /*  Name:  remove
      Purpose:  removes a product from the list and returns true if an item has been removed or false otherwise */

    bool remove(Product*);
    
    /*  Name:  reorg
     Purpose:  sorts the list in ascending order of product expiry date*/
    
    void reorg();
    
    /*   Name: toString
      Purpose: stores each data in a string*/
    
    void toString(string&);

     /*  Name:  get
      Purpose:  get's a product reference from elements based on index*/

    //Product* get(int);
    //int getSize();


     /* Name: isThere
     Purpose: checks if the product is in elements based on id*/

    bool isThere(int);
    
    /*  Name: selectedById
     Purpose: returns a product reference based on the id*/

    Product* selectedById(int);

  private:

    //Product* elements[MAX_ARR];
    Node* head;
    //int size;
};

#endif

