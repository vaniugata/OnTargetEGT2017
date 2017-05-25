#ifndef SRC_BOOK_H_
#define SRC_BOOK_H_

#include <string>

class Book
{
private:
	std::string _author;
	std::string _title;
	int _year;
	double _price;


public:
	Book(std::string author = "", std::string title = "", int year = 0, double price = 0.0);
	virtual ~Book();

	//getters
	const std::string& getAuthor() const;
	double getPrice() const;
	const std::string& getTitle() const;
	int getYear() const;

	//setters
	void setAuthor(const std::string& author);
	void setPrice(double price);
	void setTitle(const std::string& title);
	void setYear(int year);
};

#endif /* SRC_BOOK_H_ */
