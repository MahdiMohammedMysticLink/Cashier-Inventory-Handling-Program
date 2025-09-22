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

#include <string>
#include <cstdlib>
using namespace std;



#include "CustArray.h"

CustArray::CustArray()
{
  size = 0;
  
  for (int i=0; i<MAX_ARR; ++i) 
  {
    elements[i] = 0;
  }
  
}

int CustArray::getSize() { return size; }


Customer* CustArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void CustArray::add(Customer* cust)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = cust;
}


bool CustArray::isThere(int id)
{
  for (int i=0; i<size; i++)
  {

    if (elements[i]->getId() == id)
    {
      return true;
    }
  }
return false;
}


Customer* CustArray::selectedById(int id)
{
  for (int i=0; i<size; i++)
  {

    if (elements[i]->getId() == id)
    {
      return elements[i];
    }

  }
}


CustArray::~CustArray()
{

  for(int i=0; i<size; i++)
  {
    delete elements[i];
  }

}




