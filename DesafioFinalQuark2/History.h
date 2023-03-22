#pragma once
#include <string>

using namespace std;

class Book;
class Exemplary;
class Partner;

class History
{
protected:
	string type;
	string time;
	Exemplary* exemplary;
	Partner* partner;
	string currentTime();
public:
	History(Exemplary* exemplary, Partner* partner);
	string getType();
	string getTime();
	string getExemplaryEdition();
	string getExemplaryBookName();
	string getExemplaryBookIsbn();
	string getExemplaryLibraryUbication();
	string getPartnerFullName();
};

