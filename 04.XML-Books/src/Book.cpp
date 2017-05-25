/*
 * Book.cpp
 *
 *  Created on: May 25, 2017
 *      Author: vaniugata
 */

#include "Book.h"

Book::Book(std::string author, std::string title, int year, double price)
{
	setAuthor(author);
	setTitle(title);
	setYear(year);
	setPrice(price);
}

Book::~Book()
{
	// TODO Auto-generated destructor stub
}

const std::string& Book::getAuthor() const
{
	return _author;
}

double Book::getPrice() const
{
	return _price;
}

const std::string& Book::getTitle() const
{
	return _title;
}

int Book::getYear() const
{
	return _year;
}

void Book::setAuthor(const std::string& author)
{
	_author = author;
}

void Book::setPrice(double price)
{
	_price = price;
}

void Book::setTitle(const std::string& title)
{
	_title = title;
}

void Book::setYear(int year)
{
	_year = year;
}
