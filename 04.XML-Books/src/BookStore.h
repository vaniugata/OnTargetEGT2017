#ifndef SRC_BOOKSTORE_H_
#define SRC_BOOKSTORE_H_

#include "Book.h"
#include <vector>

class BookStore
{
public:

	static  std::vector<Book*> books;

	BookStore();
	virtual ~BookStore();
	static void addToBooks(Book& book);
};

#endif /* SRC_BOOKSTORE_H_ */
