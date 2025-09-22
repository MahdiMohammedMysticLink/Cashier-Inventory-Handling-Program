

#include "PurchArray.h"

#include <cstdlib>
using namespace std;


PurchArray::PurchArray()
{
  size = 0;
  
  for (int i=0; i<MAX_ARR; ++i) 
  {
    elements[i] = 0;
  }

}


int PurchArray::getSize() { return size; }




bool PurchArray::isThere(int id)
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

Purchase* PurchArray::selectedById(int id)
{

 for (int i=0; i<size; i++)
  {

    if (elements[i]->getId() == id)
    {
      return elements[i];
    }
  }

}

Purchase* PurchArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}


void PurchArray::add(Purchase* purch)
{ 
  if (size >= MAX_ARR)
    return;

  elements[size++] = purch;  
}


PurchArray::~PurchArray()
{

  for(int i=0; i<size; i++)
  {
    delete elements[i];
  }

}

void PurchArray::toString(string& outStr)
{
  outStr+= "\n          Product Id  Units \n";
  outStr+= "          ----------  ----- \n";
  for (int i=0; i<size; i++)
  {

    elements[i]->toString(outStr);
  }

}
