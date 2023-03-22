#include "Book.h"
#include "Exemplary.h"

#include <iostream>

Exemplary::Exemplary(Book* book, string edition, string ubication)
{
	this->book = book;
	this->edition = edition;
	this->ubication = ubication;
	book->addNewExemplary(this);
}

Book* Exemplary::getBook()
{
	return this->book;
}

string Exemplary::getEdition()
{
	return this->edition;
}

string Exemplary::getUbication()
{
	return this->ubication;
}
