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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"
#include <cmath>

using namespace std;


void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Remove product \n\n";
  cout<< "          4. Print inventory \n\n";
  cout<< "          5. Print customers \n\n";
  cout<< "          6. Print orders \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 6) 
  {

    cout << "Enter your selection:  ";
    choice = readInt();
    cout<<endl;
  }
}

void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) 
  {
    cout << "Enter your selection:  ";
    choice = readInt();
    cout << endl;
    if (choice == MAGIC_NUM) return;
  }
}

void UI::printStock(ProdList& list)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  string s;

  cout << endl << "STOCK: " << endl << endl;
  

  list.toString(s);
  cout << s;
}

void UI::printCustomers(CustArray& arr)
{
  cout << endl << "CUSTOMERS: " << endl << endl;

  for (int i=0; i<arr.getSize(); i++) {
    Customer* cust = arr.get(i);
    
    cout << "Id: "<<cust->getId() << "  " << setw(10) << "Customer: " <<cust->getName()
         << "  " << setw(4) <<"Loyalty Points: "<< cust->getPoints() << endl;
    printOnlyThePurchases(cust);
  }
}

void UI::printOnlyThePurchases(Customer* cust)
{ 
   PurchArray& purchases = cust->getPurchases();
  // cout << "               " << "Purchases:" << endl;
   
  cout << endl<<"           Product  Id" << "  " << "Units" << endl;
  cout << "           -----------" << "  " << "-----" << endl; 
   for (int i = 0; i<purchases.getSize(); i++)
  {
    Purchase* purch = purchases.get(i);
 
    cout << "           "<< setw(11) <<purch->getId() << "  " << setw(5) << purch->getUnits() << endl;
  }
  cout << endl<<endl;

}

void UI::printOrders(OrderArray& arr)
{
  string s;
  arr.toString(s);
  cout<<s;
}

/*
void UI::printCustomerPurchases(int custId, CustArray& arr)
{

  Customer* cust = arr.selectedById(custId);
  
  cout<<endl<<"Customer Id: " << cust->getId() << "  " << setw(10)<<"Customer: " << cust->getName() 
  << "  " << setw(4) << "Loyalty Points: "<< cust->getPoints() << endl;  

  PurchArray& purchases = cust->getPurchases();
  cout << endl << setw(13) << "PURCHASES " << endl;
  cout << setw(4)<< "Id" << setw(10)<<  "Units" << endl;
  cout << "  --     -----    " << endl;
  for (int i = 0; i<purchases.getSize(); i++)
  {
    Purchase* purch = purchases.get(i);
    cout << purch->getId() << setw(10) << purch->getUnits() << "  " << endl;
  }
  cout << endl;
}
*/

void UI::printPurchaseSummary(float summary, float origSummary)
{ 
  
 
  int points = round(origSummary);
  
  cout <<endl;
  cout <<"    "<<"Purchase Summary" << endl;
  cout <<"     "<< "Price" << "    " << "Points" << endl;
  cout <<"     $" << fixed << setprecision(2) << summary <<"    "<< points <<endl;
}


void UI::printError(string err)
{
  cout << err << " -- press enter to continue...";
  cin.get();
  cout<<endl;
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}


void UI::printCategories(int& choice, int& lSpan)
{

  choice = -1;
  lSpan = -1;

  cout<< "\nSelect product category \n\n";
  cout<< "          1. Dairy\n\n";
  cout<< "          2. CoffeeTea\n\n";
  cout<< "          3. Bakery\n\n";
  cout<< "          4. Meat\n\n";
  cout<< "          5. MiscGoods\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 5) 
  {
    cout << "Enter your selection:  ";
    choice = readInt();
    cout << endl;
  }
  
  if ( choice == 1 || choice == 3 || choice == 4)
  {
    while (lSpan < 1) 
    {
      cout<< "\nEnter lifespan (Greater than 0):  ";
      lSpan = readInt();
      cout << endl;
    }
    
  }
  
}


void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
  cout<<endl;
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

