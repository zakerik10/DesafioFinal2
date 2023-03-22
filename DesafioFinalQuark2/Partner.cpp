#include <iostream>
#include "Partner.h"
#include "Exemplary.h"
#include "Book.h"

Partner::Partner(int id, string name, string lastName)
{
	this->id = id;
	this->name = name;
	this->lastName = lastName;
}

int Partner::getId()
{
	return this->id;
}

string Partner::getName()
{
	return this->name;
}

string Partner::getLastName()
{
	return this->lastName;
}

int Partner::getMaxBooksCanWithdraw()
{
	return this->maxBooksCanWithdraw;
}

void Partner::addNewWithdrawnExemplary(Exemplary* exemplary)
{
	withdrawnExemplaries.push_back(exemplary);
}

void Partner::deleteWithdrawnExemplary(Exemplary* exemplary)
{
	auto it = find(withdrawnExemplaries.begin(), withdrawnExemplaries.end(), exemplary);

	if (it != withdrawnExemplaries.end()) {
		withdrawnExemplaries.erase(it);
	}
}

list<Exemplary*> Partner::getWithdrawnExemplary()
{
	return this->withdrawnExemplaries;
}

bool Partner::canTakeBook()
{
	return this->withdrawnExemplaries.size() < maxBooksCanWithdraw;
}

int Partner::amountBooksInPossession()
{
	return this->withdrawnExemplaries.size();
}

//void Partner::borrowExemplary(Exemplary* exemplary)
//{
//	try {
//		if (this->canTakeBook()) {
//			this->withdrawnExemplaries.push_back(exemplary);
//		}
//		else {
//			throw CANT_WITHDRAW_EXEMPLARY_MESSAGE;
//		}
//	}
//	catch (const char* msg) {
//		cerr << "Error: " << msg << endl;
//	}
//}

//void Partner::returnExemplary(Exemplary* exemplary)
//{
//	try {
//		auto it = find(withdrawnExemplaries.begin(), withdrawnExemplaries.end(), exemplary);
//		if (it != withdrawnExemplaries.end()) {
//			this->withdrawnExemplaries.push_back(exemplary);
//		}
//		else {
//			throw EXEMPLARY_ON_LIST_MESSAGE;
//		}
//	}
//	catch (const char* msg) {
//		cerr << "Error: " << msg << endl;
//	}
//}