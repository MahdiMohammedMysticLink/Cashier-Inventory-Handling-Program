OBJ = main.o InvControl.o Store.o Product.o UI.o ProdList.o CustArray.o Customer.o PurchArray.o Purchase.o Order.o OrderArray.o OrderServer.o Date.o Taxable.o NonTaxable.o Perishable.o NonPerishable.o Dairy.o Meat.o CoffeeTea.o Bakery.o MiscGoods.o

cushop:		$(OBJ)
		g++ -o cushop $(OBJ)

main.o:		main.cc 
		g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Dairy.h
		g++ -c InvControl.cc

UI.o:		UI.cc UI.h 
		g++ -c UI.cc

Store.o:	Store.cc Store.h 
		g++ -c Store.cc

Product.o:	Product.cc Product.h 
		g++ -c Product.cc

ProdList.o:	ProdList.cc ProdList.h 
		g++ -c ProdList.cc

CustArray.o:	CustArray.cc CustArray.h
		g++ -c CustArray.cc

Customer.o:	Customer.cc Customer.h
		g++ -c Customer.cc

Purchase.o:	Purchase.cc Purchase.h
		g++ -c Purchase.cc

PurchArray.o:	PurchArray.cc PurchArray.h 
			g++ -c PurchArray.cc

Order.o:	Order.cc Order.h 
		g++ -c Order.cc

OrderArray.o:	OrderArray.cc OrderArray.h
		g++ -c OrderArray.cc

OrderServer.o:	OrderServer.cc OrderServer.h
		g++ -c OrderServer.cc
		
Date.o:		Date.cc Date.h
		g++ -c Date.cc
		
Taxable.o:	Taxable.cc Taxable.h
		g++ -c Taxable.cc
		
NonTaxable.o:	NonTaxable.cc NonTaxable.h
		g++ -c NonTaxable.cc
		
Perishable.o:	Perishable.cc Perishable.h
		g++ -c Perishable.cc

NonPerishable.o:NonPerishable.cc NonPerishable.h
		g++ -c NonPerishable.cc
		
Dairy.o:	Dairy.cc Dairy.h
		g++ -c Dairy.cc

Meat.o:		Meat.cc Meat.h
		g++ -c Meat.cc
		
CoffeeTea.o:	CoffeeTea.cc CoffeeTea.h
		g++ -c CoffeeTea.cc

Bakery.o:	Bakery.cc Bakery.h
		g++ -c Bakery.cc

MiscGoods.o:	MiscGoods.cc MiscGoods.h
		g++ -c MiscGoods.cc

clean:
	rm -f $(OBJ) cushop
