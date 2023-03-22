#include "Partner.h"
#include "Vip.h"

Vip::Vip(int id, string name, string lastName, float monthlyFee) : Partner(id, name, lastName)
{
    this->monthlyFee = monthlyFee;
    this->maxBooksCanWithdraw = 3;
}
