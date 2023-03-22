#pragma once
#include <string>
using namespace std;

class Book;

class Exemplary
{
private:
	Book* book;
	string edition;
	string ubication;
public:
	Exemplary(Book* book, string edition, string ubication);
	Book* getBook();
	string getEdition();
	string getUbication();
};

