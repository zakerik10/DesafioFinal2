#pragma once
#include "IView.h"
#include <string>
using namespace std;

class Presenter;

class View : public IView
{
private:
	Presenter* presenter;
	void showTextSeparator();
	string showMenuGeneric(string title, string question);
	void showMainMenu();
	void selectOptionMainMenu(string option, bool& exitCond);
	string showMenuYesOrNo();
	string showMenuPartnerVip();
	float showMenuPartnerMonthlyFee();
	void showMenuPartnerInfo(int id, string name, string lastName, string vip, int monthlyFee);
	string showMenuBookIsbnCode();
	void showMenuBookInfo(string name, string isbnCode, string author);
	string showMenuFindBookWithIsbnOrName(string title);
	void showMenuExemplaryInfo(string nameFindedBook, string edition, string ubication);
	string showMenuFindPartnerWithIdOrName();
	string showMenuCheckPartnerData();
	string showMenuFindEditionWithdrawnExemplaries();
	void newPartner();
	void newBook();
	void newExemplary();
	void showExemplariesAvaiable();
	void showHistory();
	void lendBook();
	void registerReturn();
public:
	View();
	~View() override;
	void showMenuTitle(string title) override;
	void showBackToMainMenuMessage() override;
	void showText(const string& text) override;
	void showText(float text) override;
	void showText(int text) override;
	void showTextInLine(const string& text) override;
	void showTextInLine(float text) override;
	void showTextInLine(int text) override;
	void showHistoryElement(string action, string time, string bookName, string isbn, string edition, string libraryUbication, string fullName) override;
	void showExemplariesAvaiable(string bookName, string isbn, string edition, string libraryUbication) override;
};

