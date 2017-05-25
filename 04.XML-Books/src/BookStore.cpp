/*
 * BookStore.cpp
 *
 *  Created on: May 25, 2017
 *      Author: vaniugata
 */

#include "BookStore.h"

std::vector<Book*> BookStore::books;

BookStore::BookStore()
{
	// TODO Auto-generated constructor stub

}

BookStore::~BookStore()
{
	// TODO Auto-generated destructor stub
}

void BookStore::addToBooks(Book& book)
{
	books.push_back(&book);
}
