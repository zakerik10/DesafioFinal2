#include <iostream>
#include "Book.h"
#include "Exemplary.h"

Book::Book(string name, string isbnCode, string author)
{
	this->name = name;
	this->isbnCode = isbnCode;
	this->author = author;
}

string Book::getName()
{
	return this->name;
}

string Book::getIsbnCode()
{
	return this->isbnCode;
}

string Book::getAuthor()
{
	return this->author;
}

void Book::addNewExemplary(Exemplary* exemplary)
{
	excemplariesList.push_back(exemplary);
}

bool Book::checkExcemplariesAvailable()
{
	return !excemplariesList.empty();
}

list<Exemplary*> Book::getExcemplariesList()
{
	return this->excemplariesList;
}

void Book::deleteFirstExemplary()
{
	try {
		if (this->checkExcemplariesAvailable()) {
			this->excemplariesList.pop_front();
		}
		else {
			throw EMPTY_LIST_MESSAGE;
		}
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
}
