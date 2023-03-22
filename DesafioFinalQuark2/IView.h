#pragma once
#include <string>
using namespace std;

class IView
{
public:
	virtual ~IView() = default;
	virtual void showMenuTitle(string title) = 0;
	virtual void showBackToMainMenuMessage() = 0;
	virtual void showText(const string& text) = 0;
	virtual void showText(float text) = 0;
	virtual void showText(int text) = 0;
	virtual void showTextInLine(const string& text) = 0;
	virtual void showTextInLine(float text) = 0;
	virtual void showTextInLine(int text) = 0;
	virtual void showHistoryElement(string action, string time, string bookName, string isbn, string edition, string libraryUbication, string fullName) = 0;
	virtual void showExemplariesAvaiable(string bookName, string isbn, string edition, string libraryUbication) = 0;
};




