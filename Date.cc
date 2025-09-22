#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

void Date::setDate(int d, int m, int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}


int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

int Date::daysBeforeLastMonth(){

   switch(month)
   {
     case 1:
       return 0;
     case 2:
       return 31;
     case 3:
       return 59;
     case 4:
       return 90;
     case 5:
       return 120;
     case 6:
       return 151;
     case 7:
       return 181;
     case 8:
       return 212;
     case 9:
       return 243;
     case 10:
       return 273;
     case 11:
       return 304;
     case 12:
       return 334;
   }

}



int Date::computeMonth(int d)
{

  if (d <= 31)
  {
    return 1;
  } 
  else if(d<=59)
  {
    return 2;
  }

  else if(d<=90)
  {
    return 3;
  }
    
  else if(d<=120)
  {
    return 4;
  }
  else if(d<=151)
  {
    return 5;
  }
  
  else if(d<=181)
  {
    return 6;
  }
  else if(d<=212)
  {
    return 7;
  }
  else if(d<=243)
  {
    return 8;
  }
  else if(d<=273)
  {
    return 9;
  }
  else if(d<=304)
  {
    return 10;
  }
  else if(d<=334)
  {
    return 11;
  }
  else if(d<=365)
  {
    return 12;
  }
  

}


bool Date::operator>(Date& d)
{
  return(convertToDays() > d.convertToDays());

}


Date& Date::operator+=(int d)
{
  int tmpdays = convertToDays();
  tmpdays += d;
  computeDate(tmpdays);

  return *this;

}


Date Date::operator+(int d)
{
  Date tmpDate = *this;

  tmpDate += d;
  return tmpDate;
}


Date& Date::operator=(const Date& d)
{
  setDate(d.day, d.month, d.year);
  return *this;
}


void Date::toString(string& outStr)
{
   stringstream ss;
   ss << setw(4) << setfill('0')  << year << "/" << setw(2) << setfill('0') <<  month  << "/" << setw(2)<< setfill('0') << day <<endl;

   outStr += ss.str();
   ss.str("");

}


void Date::computeDate(int d)
{

  int numYears = 0;

  numYears = d/365;
  d = d%365;
  
  if(d == 0)
    d = 365;
 
  year = numYears;
 
  month = computeMonth(d);
  
  
  day = d - daysBeforeLastMonth();
  
}



int Date::convertToDays()
{

  return (year*365 + daysBeforeLastMonth() + day);

}




