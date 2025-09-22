#include "OrderServer.h"

void OrderServer::update(Order* order)
{
  orders.add(order);
}

void OrderServer::retrieve(OrderArray& arr)
{
  for (int i=0; i<orders.getSize(); i++)
  { 
    arr.add(orders.get(i));

  }

}

OrderServer::~OrderServer()
{
  orders.cleanup();;


}
