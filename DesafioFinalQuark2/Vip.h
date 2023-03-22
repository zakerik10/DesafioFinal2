#pragma once
#include <string>
using namespace std;

class Partner;

class Vip : public Partner
{
private:
	float monthlyFee;
public:
	Vip(int id, string name, string lastName, float monthlyFee);
};

