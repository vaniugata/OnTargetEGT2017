#include <iostream>
#include "pugixml.hpp"
#include "Book.h"
#include "BookStore.h"
#include <string>

int main()
{
	pugi::xml_document doc;
	if (!doc.load_file("books.xml"))
	{
		std::cerr << "cant open books.xml.\n";
		return -1;
	}
	pugi::xml_node books = doc.child("bookstore");



	for (pugi::xml_node book = books.child("book"); book; book = book.next_sibling("book"))
	{
			std::string title = book.child("title").text().as_string();
			std::string author = book.child("author").text().as_string();
			int year = book.child("year").text().as_int();
			double price = book.child("price").text().as_double();

			Book* bookObj = new Book(author, title, year, price);
			BookStore::books.push_back(bookObj);
	}


	for(unsigned int i = 0; i < BookStore::books.size(); ++i)
	{
		std::cout << BookStore::books[i]->getTitle();
		std::cout << "\n";
	}

	return 0;
}
