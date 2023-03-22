#include "Exemplary.h"
#include "Partner.h"
#include "Devolutions.h"
#include "Book.h"

Devolutions::Devolutions(Exemplary* exemplary, Partner* partner) : History(exemplary, partner)
{
	this->type = "Devolucion";
	this->time = this->currentTime();
	this->exemplary->getBook()->addNewExemplary(exemplary);
	this->partner->deleteWithdrawnExemplary(exemplary);
}
