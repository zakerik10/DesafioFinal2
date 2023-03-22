#include "Book.h"
#include "Exemplary.h"
#include "Partner.h"
#include "History.h"
#include "Loan.h"

#include <iomanip>
#include <chrono>
#include <sstream>

History::History(Exemplary* exemplary, Partner* partner)
{
	this->exemplary = exemplary;
	this->partner = partner;
}

string History::getType()
{
    return this->type;
}

string History::getTime()
{
    return this->time;
}

string History::getExemplaryEdition()
{
    return this->exemplary->getEdition();
}

string History::getExemplaryBookName()
{
    return this->exemplary->getBook()->getName();
}

string History::getExemplaryBookIsbn()
{
    return this->exemplary->getBook()->getIsbnCode();
}

string History::getExemplaryLibraryUbication()
{
    return this->exemplary->getUbication();
}

string History::getPartnerFullName()
{
    return this->partner->getName() + " " + this->partner->getLastName();
}

string History::currentTime()
{
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    tm tm_struct;
    if (localtime_s(&tm_struct, &time) != 0) {
        // Error al llamar a localtime_s()
        // Manejo del error
    }
    stringstream ss;
    ss << put_time(&tm_struct, "%d-%m-%Y %H:%M:%S");
    std::string time_str = ss.str();
    return time_str;
}
