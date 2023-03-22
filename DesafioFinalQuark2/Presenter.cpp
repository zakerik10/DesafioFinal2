#include "Presenter.h"
#include "IView.h"
#include "Library.h"
#include "Partner.h"
#include "Vip.h"
#include "Book.h"
#include "Exemplary.h"
#include "Loan.h"
#include "Devolutions.h"
#include "History.h"

#include <iostream>

Presenter::Presenter(IView* view) : mView(view)
{
	this->library = new Library();
}

int Presenter::getLastPartnerIdCreated()
{
	return this->library->getLastPartnerIdCreated();
}

void Presenter::createNewPartner(string name, string lastName)
{
	int id = getLastPartnerIdCreated() + 1;
	Partner* newPartner = new Partner(id, name, lastName);
	this->library->saveNewPartner(newPartner);
}

void Presenter::createNewPartner(string name, string lastName, float monthlyFee)
{
	int id = this->library->getLastPartnerIdCreated() + 1;
	Partner* newPartner = new Vip(id, name, lastName, monthlyFee);
	this->library->saveNewPartner(newPartner);
}

void Presenter::createNewBook(string name, string isbnCode, string author)
{
	Book* newBook = new Book(name, isbnCode, author);
	this->library->saveNewBook(newBook);
}

void Presenter::createNewExemplary(string edition, string ubication)
{
	Exemplary* newExemplary = new Exemplary(this->library->getBookFound(), edition, ubication);
}

bool Presenter::findedPartnerCanTakeBook()
{
	return this->library->getPartnerFound()->canTakeBook();
}

bool Presenter::findedPartnerOwnsBooks()
{
	return this->library->getPartnerFound()->amountBooksInPossession();
}

void Presenter::lendBook()
{
	list<Exemplary*> exemplariesList = this->library->getBookFound()->getExcemplariesList();
	Loan* newLoan = new Loan((*exemplariesList.begin()), this->library->getPartnerFound());
	this->library->saveNewHistory(newLoan);
	this->lastLendBook = newLoan;
}

void Presenter::showHistory()
{
	string title = "Historial";
	mView->showMenuTitle(title);
	mView->showText("");
	list<History*> history = this->library->getHistoryList();
	if (!history.empty()) {
		for (History* i : history) {
			string type = i->getType();
			string bookName = i->getExemplaryBookName();
			string time = i->getTime();
			string bookIsbn = i->getExemplaryBookIsbn();
			string edition = i->getExemplaryEdition();
			string fullName = i->getPartnerFullName();
			string libraryUbication = "";
			if (type == "Devolucion") {
				libraryUbication = i->getExemplaryLibraryUbication();
			}
			mView->showHistoryElement(type, time, bookName, bookIsbn, edition, libraryUbication, fullName);
			mView->showText("");
		}
	}
	else {
		mView->showText("No hubieron movimientos");
	}
}

void Presenter::showExemplariesAvaiable()
{
	string title = "Ejemplares Disponibles";
	mView->showMenuTitle(title);
	mView->showText("");
	list<Book*> bookList = this->library->getBookList();
	Book* book = this->library->getBookFound();

	auto it = find_if(bookList.begin(), bookList.end(), [book](Book*& obj) {
		return obj == book;
	});


	if (it != bookList.end()) {
		if (!book->getExcemplariesList().empty()) {
			for (Exemplary* i : book->getExcemplariesList()) {
				string bookName = book->getName();
				string bookIsbn = book->getIsbnCode();
				string edition = i->getEdition();
				string libraryUbication = i->getUbication();
				mView->showExemplariesAvaiable(bookName, bookIsbn, edition, libraryUbication);
				mView->showText("");
			}
		}
		else {
			mView->showText("Este libro no tiene ejemplares");
		}
	}
	else {
		mView->showText("No se encontró el libro");
	}
}

void Presenter::registerReturn()
{
	Devolutions* newDevolution = new Devolutions(this->library->getExemplaryLendedPartnerFound(), this->library->getPartnerFound());
	this->library->saveNewHistory(newDevolution);
	this->lastReturnedBook = newDevolution;
	//Exemplary* newExemplary = new Exemplary(this->library->getBookFound(), edition, ubication);
	//this->library->getBookFound()->addNewExemplary(this->library->getExemplaryLendedPartnerFound());

}

string Presenter::getNameFindedBook()
{
	return this->library->getBookFound()->getName();
}

string Presenter::getIsbnFindedBook()
{
	return this->library->getBookFound()->getIsbnCode();
}

int Presenter::getAmountExemplariesFindedBook()
{
	return this->library->getBookFound()->getExcemplariesList().size();
}

int Presenter::getIdFindedPartner()
{
	return this->library->getPartnerFound()->getId();
}

bool Presenter::findBook(string isbnOrName)
{
	return this->library->findBookWithIsbnOrName(isbnOrName);
}

bool Presenter::findPartner(string fullName)
{
	return this->library->findPartnerWithIdOrName(fullName);
}

bool Presenter::findPartner(int id)
{
	return this->library->findPartnerWithIdOrName(id);
}

bool Presenter::findBookWithdrawnExemplaries()
{
	list<Exemplary*> withdrawnExemplary = this->library->getPartnerFound()->getWithdrawnExemplary();
	Book* book = this->library->getBookFound();

	auto it = find_if(withdrawnExemplary.begin(), withdrawnExemplary.end(), [book](Exemplary*& obj) {
		return obj->getBook() == book;
	});

	if (it != withdrawnExemplary.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool Presenter::findEditionWithdrawnExemplaries(string edition)
{
	return this->library->findExemplaryLendedPartnerWhitEdition(edition);
}

string Presenter::getNameFindedPartner()
{
	return this->library->getPartnerFound()->getName();
}

string Presenter::getLastNameFindedPartner()
{
	return this->library->getPartnerFound()->getLastName();
}

string Presenter::getLastLendBookType()
{
	return this->lastLendBook->getType();
}

string Presenter::getLastLendBookTime()
{
	return this->lastLendBook->getTime();
}

string Presenter::getLastLendBookExemplaryEdition()
{
	return this->lastLendBook->getExemplaryEdition();
}

string Presenter::getLastLendBookPartnerFullName()
{
	return this->lastLendBook->getPartnerFullName();
}

string Presenter::getLastReturnedBookType()
{
	return this->lastReturnedBook->getType();
}

string Presenter::getLastReturnedBookTime()
{
	return this->lastReturnedBook->getTime();
}

string Presenter::getLastReturnedBookExemplaryEdition()
{
	return this->lastReturnedBook->getExemplaryEdition();
}

string Presenter::getLastReturnedBookPartnerFullName()
{
	return this->lastReturnedBook->getPartnerFullName();
}

string Presenter::getLastReturnedBookUbication()
{
	return this->lastReturnedBook->getExemplaryLibraryUbication();
}
