#include "Exemplary.h"
#include "Partner.h"
#include "Library.h"
#include "Loan.h"
#include "Book.h"

Loan::Loan(Exemplary* exemplary, Partner* partner) : History(exemplary, partner)
{
	this->type = "Prestamo";
	this->time = this->currentTime();
	this->partner->addNewWithdrawnExemplary(exemplary);
	this->exemplary->getBook()->deleteFirstExemplary();
}
