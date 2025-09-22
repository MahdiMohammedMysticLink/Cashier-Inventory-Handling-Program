#include "OrderArray.h"

#include <cstdlib>
using namespace std;

OrderArray::OrderArray()
{
  size = 0;
  
  for (int i=0; i<MAX_ARR; ++i) 
  {
    elements[i] = 0;
  }

}

int OrderArray::getSize(){return size;}

Order* OrderArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}


void OrderArray::cleanup()
{

  for(int i=0; i<size; i++)
  {
    delete elements[i];
  }

}


void OrderArray::add(Order* order)
{ 
  if (size >= MAX_ARR)
    return;

  elements[size++] = order;  
}


void OrderArray::toString(string& outStr)
{
  outStr+= "\n ORDERS: \n\n";
  for (int i=0; i<size; i++)
  {

    elements[i]->toString(outStr);
  }

}

