#include "Library.h"
#include "Partner.h"
#include "Book.h"
#include "History.h"
#include "Exemplary.h"

list<Partner*> Library::getPartnerList()
{
	return this->partnerList;
}

list<Book*> Library::getBookList()
{
	return this->bookList;
}

list<History*> Library::getHistoryList()
{
	return this->historyList;
}

int Library::getLastPartnerIdCreated()
{
	if (this->partnerList.empty()) {
		return -1;
	}
	else {
		return this->partnerList.back()->getId();
	}
}

void Library::saveNewPartner(Partner* newPartner)
{
	this->partnerList.push_back(newPartner);
}

void Library::saveNewBook(Book* newBook)
{
	this->bookList.push_back(newBook);
}

void Library::saveNewHistory(History* newHistory)
{
	this->historyList.push_back(newHistory);
}

void Library::deleteFirstExemplaryBookFound()
{
	this->bookFound->deleteFirstExemplary();
}

bool Library::findBookWithIsbnOrName(string isbnOrName)
{
	bool findedBook = false;
	for (Book* i : this->bookList) {
		if (i->getIsbnCode() == isbnOrName || i->getName() == isbnOrName) {
			findedBook = true;
			this->bookFound = i;
			break;
		}
	}
	return findedBook;
}

bool Library::findPartnerWithIdOrName(string fullName)
{
	bool findedPartner = false;
	size_t pos = fullName.find(" ");
	string name = fullName.substr(0, pos);
	string lastName = fullName.substr(pos + 1);
	for (Partner* i : this->partnerList) {
		if ((i->getName() == name) && (i->getLastName() == lastName)) {
			findedPartner = true;
			this->partnerFound = i;
			break;
		}
	}
	return findedPartner;
}

bool Library::findPartnerWithIdOrName(int id)
{
	bool findedPartner = false;
	//auto it = this->partnerList.begin();
	//for (it; it != this->partnerList.end(); ++it) {
	for (Partner* i : this->partnerList) {
		//if ((*it)->getId() == id) {
		if (i->getId() == id) {
			findedPartner = true;
			this->partnerFound = i;
			break;
		}
	}
	return findedPartner;
}

bool Library::findExemplaryLendedPartnerWhitEdition(string edition)
{
	bool findedExemplary = false;
	for (Exemplary* i : this->partnerFound->getWithdrawnExemplary()) {
		if (i->getEdition() == edition) {
			findedExemplary = true;
			this->exemplaryLendedPartnerFound = i;
			break;
		}
	}
	return findedExemplary;
}

Book* Library::getBookFound()
{
	return this->bookFound;
}

Partner* Library::getPartnerFound()
{
	return this->partnerFound;
}

Exemplary* Library::getExemplaryLendedPartnerFound()
{
	return this->exemplaryLendedPartnerFound;
}
