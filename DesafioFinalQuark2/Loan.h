#pragma once
#include "History.h"

using namespace std;

class Exemplary;
class Partner;
class History;
class Book;

class Loan : public History
{
public:
	Loan(Exemplary* exemplary, Partner* partner);
};

