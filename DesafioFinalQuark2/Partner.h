#pragma once
#include <string>
#include <list>
using namespace std;

const string CANT_WITHDRAW_EXEMPLARY_MESSAGE = "This partner cannot withdraw more exemplaries.";
const string EXEMPLARY_ON_LIST_MESSAGE = "The exemplary was already here.";

class Exemplary;
class Book;

class Partner
{
protected:
	int id;
	string name;
	string lastName;
	int maxBooksCanWithdraw = 1;
	list<Exemplary*> withdrawnExemplaries;
public:
	Partner(int id, string name, string lastName);
	int getId();
	string getName();
	string getLastName();
	int getMaxBooksCanWithdraw();
	void addNewWithdrawnExemplary(Exemplary* exemplary);
	void deleteWithdrawnExemplary(Exemplary* exemplary);
	list<Exemplary*> getWithdrawnExemplary();
	bool canTakeBook();
	int amountBooksInPossession();
};

