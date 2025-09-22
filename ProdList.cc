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

#include "ProdList.h"

ProdList::ProdList() : head(0) //size(0)
{}


bool ProdList::isThere(int id)
{
  for (Node* currNode=head; currNode!=0; currNode = currNode->next)
  {

    if (currNode->data->getId() == id)
    {
      return true;
    }
  }
  return false;
}


Product* ProdList::selectedById(int id)
{
  for (Node* currNode=head; currNode!=0; currNode = currNode->next)
  {

    if (currNode->data->getId() == id)
    {
      return currNode->data;
    }
  }
}


//int ProdList::getSize() { return size; }


/*Product* ProdList::get(int index)
{

	int count = 0;
	Node* currNode = 0;

  if (index < 0 || index >= size)
    exit(1);
    
  for ( currNode = head;
        count != index; 
        currNode = currNode->next, count++) {
   }
  
  return currNode->data;
}
*/

void ProdList::add(Product* prod)
{
  /*if (size >= MAX_ARR)
    return;*/
    
  Node *currNode, *prevNode, *newNode;
		
  currNode = head;
  prevNode = 0;
  newNode = new Node;
  newNode->data = prod;
  while (currNode != 0) 
  {
    if(currNode->data->getExpDate() > prod->getExpDate() )
      break;
	      
    prevNode = currNode;
    currNode = currNode->next;
  }
  if (prevNode == 0) 
  {
    head = newNode;
  }
  else 
  {
    prevNode->next = newNode;
  }		
  newNode->next = currNode;
  newNode->prev = prevNode;
  if (currNode != 0)
  {
    currNode->prev = newNode;
  }

    //size++;
}

bool ProdList::remove(Product* prod)
{
  Node *prevNode, *currNode;

  currNode = head;
  prevNode = 0;
  
  while (currNode != 0)
  {
    if (currNode->data->getId() == prod->getId())
    	break;
    	
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0)
   return false;

  

  if (prevNode == 0)
  {
    head = currNode->next;
  }
  else
  {
    prevNode->next = currNode->next;
  }
  
  if (currNode->next != 0) // when not last
  {
    currNode->next->prev = prevNode;
  }

  delete currNode->data;
  delete currNode;
  
  //size--;
  
  return true;
}


void ProdList::reorg()
{

  Node* prevNode, *currNode;
  Product* temp;
  bool swap = true;
  while (swap)
  {
    prevNode = head;
    currNode = prevNode->next;
    swap = false;
    for(; currNode != 0; prevNode = currNode, currNode=currNode->next)
    {
      if(prevNode->data->getExpDate() > currNode->data->getExpDate())
      {
        temp = currNode->data;
	currNode->data = prevNode->data;
	prevNode->data = temp;
	 
        swap = true;
      }
    }
  }
	
}


void ProdList::toString(string& outStr)
{

  Node* currNode = head;

  outStr += "\nFORWARDS:\n\n";
  
  outStr+= " ID                                 Name             Size    Qty    Price      Expiry Date (yyyy/dd/mm)\n";
  outStr+= " --                                 ----             ----    ---    -----      ------------------------\n";
  if (currNode != 0)
  {
    for (; currNode->next!=0; currNode = currNode->next)
    {
    currNode->data->toString(outStr);
    }


    currNode->data->toString(outStr); //print last
  }
  
  
  outStr += "\nBACKWARDS:\n\n";
  
  outStr+= " ID                                 Name             Size    Qty    Price      Expiry Date (yyyy/dd/mm)\n";
  outStr+= " --                                 ----             ----    ---    -----      ------------------------\n";
  
  for (; currNode!=0; currNode = currNode->prev)
  {
    currNode->data->toString(outStr);
  }
  
}


ProdList::~ProdList()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }

}




