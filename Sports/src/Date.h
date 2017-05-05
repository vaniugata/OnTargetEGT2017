#ifndef DATE_H_
#define DATE_H_

#include <string>

class Date
{
private:
  unsigned int _day;
  unsigned int _month;
  unsigned int _year;

  bool isDayValid(unsigned int day, unsigned int month, unsigned int year);
  bool isMonthValid(unsigned int month, unsigned int year);
  bool isYearValid(unsigned int year);

public:
  Date();
  Date(unsigned int day, unsigned int month, unsigned int year);
  ~Date();
  std::string toString();

  //getters
  unsigned int getDay();
  unsigned int getMonth();
  unsigned int getYear();

  //setters
  void setDay(unsigned int day);
  void setMonth(unsigned int month);
  void setYear(unsigned int year);
};



#endif /* DATE_H_ */
