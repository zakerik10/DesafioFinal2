#pragma once
#include <string>
#include <list>
using namespace std;

const string EMPTY_LIST_MESSAGE = "The list of Exemplaries is empty.";

class Exemplary;

//struct ExemplariesQueueNode
//{
//	Exemplary* exemplary;
//	ExemplariesQueueNode* next;
//};

class Book
{
private:
	//ExemplariesQueueNode* excemplariesList = nullptr;
	list<Exemplary*> excemplariesList;
	string name;
	string isbnCode;
	string author;
public:
	Book(string name, string isbnCode, string author);
	string getName();
	string getIsbnCode();
	string getAuthor();
	void addNewExemplary(Exemplary* exemplary);
	bool checkExcemplariesAvailable();
	list<Exemplary*> getExcemplariesList();
	void deleteFirstExemplary();
};

