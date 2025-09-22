#include "Dairy.h"


Dairy::Dairy(string n, string s, int u, float p, int d, int m, int y, int l) : Product(n,s,u,p,d,m,y), Perishable(l)
{

}


Dairy::~Dairy(){}
