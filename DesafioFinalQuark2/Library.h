#pragma once
#include <string>
#include <list>

using namespace std;

class Partner;
class Book;
class History;
class Exemplary;


class Library
{
private:
	list<Partner*> partnerList;
	list<Book*> bookList;
	list<History*> historyList;
	Book* bookFound = nullptr;
	Partner* partnerFound = nullptr;
	Exemplary* exemplaryLendedPartnerFound = nullptr;
public:
	list<Partner*> getPartnerList();
	list<Book*> getBookList();
	list<History*> getHistoryList();
	int getLastPartnerIdCreated();
	void saveNewPartner(Partner* newPartner);
	void saveNewBook(Book* newBook);
	void saveNewHistory(History* newHistory);
	void deleteFirstExemplaryBookFound();
	bool findBookWithIsbnOrName(string isbnOrName);
	bool findPartnerWithIdOrName(string fullName);
	bool findPartnerWithIdOrName(int id);
	bool findExemplaryLendedPartnerWhitEdition(string edition);
	Book* getBookFound();
	Partner* getPartnerFound();
	Exemplary* getExemplaryLendedPartnerFound();
};

