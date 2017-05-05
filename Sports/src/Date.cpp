#include "Date.h"
#include <sstream>
#include <iostream>

Date::Date()
{
	this->_day = 1;
	this->_month= 1;
	this->_year = 1900;
}

 Date::Date(unsigned int day, unsigned int month, unsigned int year)
 {
   if(isYearValid(year))
     {
       _year = year;
     }
   if(isMonthValid(month, year))
     {
       _month = month;
     }
     if(isDayValid(day, month, year))
       {
	 _day = day;
       }
     else
       {
	 std::cout << "Incorrect Date!\n";
	 _day = 0;
	 _month = 0;
	 _year = 0;
       }
 }

 Date::~Date()
 {
   //std::cout << "Destructor of date called!\n";
 }

 bool Date::isDayValid(unsigned int day, unsigned int month, unsigned int year)
 {
   switch(month)
    {
     case 1:
     case 3:
     case 5:
     case 7:
     case 8:
     case 10:
     case 12:
       if(day > 0 && day <= 31)
	 return true;
       break;
     case 4:
     case 6:
     case 11:
       if(day > 0 && day <= 30)
	 return	true;
       break;
     case 2:
       {
       if(year % 4 == 0)
	 {
	 if(day > 0 && day <= 29)
	   {
	   return true;
	   }
	 else if(day > 0 && day <= 28)
	   {
	   return true;
	   }
      	}
       }
       break;

     default:
       return false;
    }
   return false;
 }

 bool Date::isMonthValid(unsigned int month, unsigned int year)
 {
   if(month > 0 && month <= 12)
     return true;

   return false;
 }

 bool Date::isYearValid(unsigned int year)
 {
   if(year > 0)
     return true;

   return false;
 }


 std::string Date::toString()
 {
   std::stringstream ss;
   ss << this->_day << "." << this->_month << "." << this->_year;

   return ss.str();
 }

 unsigned int Date::getDay()
 {
   return this->_day;
 }

 unsigned int Date::getMonth()
 {
   return this->_month;
 }

 unsigned int Date::getYear()
 {
   return this->_year;
 }

 void Date::setDay(unsigned int day)
 {
   _day = day;
 }
 void Date::setMonth(unsigned int month)
 {
   _month = month;
 }

 void Date::setYear(unsigned int year)
 {
   _year = year;
 }




