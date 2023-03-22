#pragma once
#include "History.h"

using namespace std;

class History;
class Exemplary;
class Partner;
class Book;

class Devolutions : public History
{
public:
	Devolutions(Exemplary* exemplary, Partner* partner);
};

