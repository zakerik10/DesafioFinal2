#pragma once
#include <string>
#include <list>
using namespace std;

class IView;
class Library;
class Partner;
class Vip;
class Book;
class Exemplary;
class Loan;
class Devolutions;
class History;

class Presenter
{
	IView* mView = nullptr;
	Library* library = nullptr;
	Loan* lastLendBook = nullptr;
	Devolutions* lastReturnedBook = nullptr;
public:
	Presenter(IView* view);
	int getLastPartnerIdCreated();
	void createNewPartner(string name, string lastName); // Normal Partner
	void createNewPartner(string name, string lastName, float monthlyFee); // Vip Partner
	void createNewBook(string name, string isbnCode, string author);
	void createNewExemplary(string edition, string ubication);
	bool findedPartnerCanTakeBook();
	bool findedPartnerOwnsBooks();
	void lendBook();
	void showHistory();
	void showExemplariesAvaiable();
	void registerReturn();
	string getNameFindedBook();
	string getIsbnFindedBook();
	int getAmountExemplariesFindedBook();
	int getIdFindedPartner();
	bool findBook(string isbnOrName);
	bool findPartner(string fullName);
	bool findPartner(int id);
	bool findBookWithdrawnExemplaries();
	bool findEditionWithdrawnExemplaries(string edition);
	string getNameFindedPartner();
	string getLastNameFindedPartner();
	string getLastLendBookType();
	string getLastLendBookTime();
	string getLastLendBookExemplaryEdition();
	string getLastLendBookPartnerFullName();
	string getLastReturnedBookType();
	string getLastReturnedBookTime();
	string getLastReturnedBookExemplaryEdition();
	string getLastReturnedBookPartnerFullName();
	string getLastReturnedBookUbication();
};

