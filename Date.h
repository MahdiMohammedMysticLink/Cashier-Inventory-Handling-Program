#ifndef DATE_H
#define DATE_H

#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

/*Purpose: To simulate a date*/

class Date
{
  public:
    Date(int=0,int=0,int=1999);
    void setDate(int,int,int);
    
 /*   Name:    +=
      Purpose: adds a number of days to the date*/
    
    Date& operator+=(int);


 /*   Name:    +
      Purpose: adds number of days to the date and returns a copy of the result without changing the orignal date*/

    Date operator+(int);

  
 /*   Name:    >
      Purpose: checks if a date object is greater*/

    bool operator>(Date&);
  
 /*   Name:    =
      Purpose: assigns a date to the date object*/

    Date& operator=(const Date&);

 /*   Name:    toString
      Purpose: store data in a string */

    void toString(string&);
   
    
  private:
    int day;
    int month;
    int year;
    
    /*  Name:    lastDayInMonth  
        Purpose: get's lastDay in month    */
  
    int lastDayInMonth();

    
    /*  Name:    daysBeforeLastMonth 
        Purpose: get number of days before the last Month    */

    int daysBeforeLastMonth();

      
    /*  Name:    computeMonth  
        Purpose: calculates which month the amount of days is in   */

    int computeMonth(int);
    

    /*  Name:    convertToDays 
        Purpose: calculates the amounts of days current date has  */

    int convertToDays();

    
    /*  Name:    computeDate 
        Purpose: calculates the year, month, and day with amount of days given  */

    void computeDate(int);

};




#endif
