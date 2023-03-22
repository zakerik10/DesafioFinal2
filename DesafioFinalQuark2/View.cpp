#include "View.h"
#include "IView.h"
#include "Presenter.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const string INVALID_OPTION_MESSAGE = "La opcion ingresada es invalida, por favor reintente.";
const string QUIT_KEY = "x";


void View::showTextSeparator()
{
	showText("--------------------------------------------------");
}

string View::showMenuGeneric(string title, string question)
{
	showMenuTitle(title);
	showBackToMainMenuMessage();
	showText(question);
	//cin.ignore();
	string c = "";
	string str = "";
	string text = "";
	bool empty = true;
	do {
		c = cin.get();
		getline(cin, str);
		text = c + str;
		if (text != "\n") empty = false;
		if (empty) showText("Ingrese un valor");
	} while (empty);
	
	return text;
}

void View::showMainMenu()
{
	string option = "";
	bool exitCondition = false;

	do
	{
		system("cls");
		showTextSeparator();
		showText("-- Bienvenido al administrador de la Libreria --");
		showTextSeparator();
		showText("SELECCIONE UNA OPCION DEL MENU");
		showText("");

		showText("1) Crear socio");
		showText("2) Agregar libro");
		showText("3) Crear ejemplar");
		showText("4) Ver ejemplares disponibles");
		showText("5) Historial de libros Prestados/Devueltos");
		showText("6) Prestar libro");
		showText("7) Registrar devolucion");
		showText("8) Salir");

		cin >> option;
		std::system("cls");
		selectOptionMainMenu(option, exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		cin.get();
		cin.get();
	} while (!exitCondition);

}

void View::selectOptionMainMenu(string option, bool& exitCond)
{
	if (option == "1")
	{
		newPartner();
		exitCond = false;
	}
	else if (option == "2")
	{
		newBook();
		exitCond = false;
	}
	else if (option == "3")
	{
		newExemplary();
		exitCond = false;
	}
	else if (option == "4")
	{
		showExemplariesAvaiable();
		exitCond = false;
	}
	else if (option == "5")
	{
		showHistory();
		exitCond = false;
	}
	else if (option == "6")
	{
		lendBook();
		exitCond = false;
	}
	else if (option == "7")
	{
		registerReturn();
		exitCond = false;
	}
	else if (option == "8")
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		cin.get();
		exitCond = false;
	}
}

void View::showBackToMainMenuMessage()
{
	showTextSeparator();
	showText("Presiona " + QUIT_KEY +  " para volver al menu principal");
	showTextSeparator();
	showText("");
}

string View::showMenuYesOrNo()
{
	string option = "";
	bool ok = false;
	showText("1) Si");
	showText("2) No");
	while (!ok)
	{
		cin >> option;
		if (!cin.fail() && (option == "1" || option == "2" || option == QUIT_KEY)) {
			ok = true;
		}
		else {
			showText(INVALID_OPTION_MESSAGE);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return option;
}

string View::showMenuPartnerVip()
{
	showMenuTitle("Nuevo Socio");
	showBackToMainMenuMessage();
	showText("El nuevo socio, ¿Es VIP?");

	return showMenuYesOrNo();
}

float View::showMenuPartnerMonthlyFee()
{
	showMenuTitle("Nuevo Socio");
	showText("Ingrese la tarifa mensual");
	float monthlyFee = 0.0f;
	bool ok = false;
	while (!ok) {
		cin >> monthlyFee;
		if (!cin.fail() && monthlyFee > 0) {
			ok = true;
		}
		else {
			showText(INVALID_OPTION_MESSAGE);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return monthlyFee;
}

void View::showMenuPartnerInfo(int id, string name, string lastName, string vip, int monthlyFee)
{
	showMenuTitle("Nuevo Socio");
	showText("");

	showTextInLine("Id: ");
	showText(id);

	showTextInLine("Nombre: ");
	showText(name);

	showTextInLine("Apellido: ");
	showText(lastName);

	showTextInLine("Tipo de Socio: ");
	if (vip == "1") {
		showText("VIP");

		showTextInLine("Tarifa Mensual: $");
		showText(monthlyFee);
	}
	else {
		showText("Normal");
	}
}

string View::showMenuBookIsbnCode()
{
	showMenuTitle("Nuevo Libro");
	showBackToMainMenuMessage();
	showText("Ingrese el código ISBN de 13 digitos");
	string isbn = "";
	bool ok = false;
	while (!ok) {
		cin >> isbn;
		if (!cin.fail() && (isbn.size() == 13 || isbn == QUIT_KEY)) {
			ok = true;
		}
		else {
			showText(INVALID_OPTION_MESSAGE);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return isbn;
}


void View::showMenuBookInfo(string name, string isbnCode, string author)
{
	showMenuTitle("Nuevo Libro");
	showText("");

	showTextInLine("Nombre: ");
	showText(name);

	showTextInLine("Código ISBN: ");
	showText(isbnCode);

	showTextInLine("Autor: ");
	showText(author);
}

string View::showMenuFindBookWithIsbnOrName(string title)
{
	showMenuTitle(title);
	showBackToMainMenuMessage();
	showText("Ingrese el nombre o el código ISBN de 13 digitos del libro");
	string isbnOrName = "";
	bool ok = false;
	cin.clear();
	while (!ok) {
		getline(cin, isbnOrName);
		if (!cin.fail()) {
			if (isbnOrName == QUIT_KEY) return isbnOrName;
			if (this->presenter->findBook(isbnOrName)) {
				ok = true;
				return isbnOrName;
			}
			else {
				showText("No se ha encontrado el libro, intenta con otro nombre o código ISBN");
			}
		}
		else {
			showText(INVALID_OPTION_MESSAGE);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return isbnOrName;
}

void View::showMenuExemplaryInfo(string nameFindedBook, string edition, string ubication)
{
	showMenuTitle("Nuevo Ejemplar");
	showText("");

	showTextInLine("Nombre del libro: ");
	showText(nameFindedBook);

	showTextInLine("Edición: ");
	showText(edition);

	showTextInLine("Ubicación en la Biblioteca: ");
	showText(ubication);
}

string View::showMenuFindPartnerWithIdOrName()
{
	showMenuTitle("Prestar Libro");
	showBackToMainMenuMessage();
	showText("Ingresa el Nombre y Apellido o numero de Identificacion (ID) del socio que quiere un ejemplar");
	string idOrName = "";
	bool partnerFinded = false;
	bool ok = false;
	cin.clear();
	while (!ok) {
		getline(cin, idOrName);
		//if (!cin.fail() && idOrName.find(" ") != string::npos) {
		if (!cin.fail() && !idOrName.empty()) {
			if (idOrName == QUIT_KEY) return idOrName;
			bool isId = true;
			for (char const &c : idOrName) {
				if (!isdigit(c)) {
					isId = false;
					break;
				}
			}
			if (isId) {
				partnerFinded = this->presenter->findPartner(stoi(idOrName));
			}
			else {
				partnerFinded = this->presenter->findPartner(idOrName);
			}
			cout << partnerFinded << endl;
			if (partnerFinded) {
				ok = true;
				//return this->presenter->getNameFindedBook();
			}
			else {
				showText("No se ha encontrado al socio, ingrese otro Nombre y Apellido o Id");
			}
		}
		else {
			showText(INVALID_OPTION_MESSAGE);
		}
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return idOrName;
}

string View::showMenuCheckPartnerData()
{
	showMenuTitle("Prestar Libro");
	showBackToMainMenuMessage();
	showText("Los datos son correctos?");
	showText("");

	showTextInLine("Número de Identificación: ");
	showText(this->presenter->getIdFindedPartner());
	showTextInLine("Nombre: ");
	showText(this->presenter->getNameFindedPartner());
	showTextInLine("Aoellido: ");
	showText(this->presenter->getLastNameFindedPartner());


	return showMenuYesOrNo();
}

string View::showMenuFindEditionWithdrawnExemplaries()
{
	showMenuTitle("Registrar Devolución");
	showBackToMainMenuMessage();
	showText("Ingresa la edición del libro que quieres devolver");
	string edition = "";
	bool ok = false;
	cin.clear();
	while (!ok) {
		getline(cin, edition);
		if (!cin.fail() && !edition.empty()) {
			if (edition == QUIT_KEY) return edition;
			if (this->presenter->findEditionWithdrawnExemplaries(edition)) {
				ok = true;
				return edition;
			}
			else {
				showText("A este socio no se le prestó un libro de esta edición, intente nuevamente");
			}
		}
		else {
			showText(INVALID_OPTION_MESSAGE);
		}
	}
	return edition;
}

void View::newPartner()
{
	string title = "Nuevo Socio";
	cin.ignore();
	string name = showMenuGeneric(title, "Ingresa el nombre del nuevo socio");
	if (name == QUIT_KEY) return;

	string lastName = showMenuGeneric(title, "Ingresa el apellido del nuevo socio");;
	if (lastName == QUIT_KEY) return;

	string isVip = showMenuPartnerVip();
	if (isVip == QUIT_KEY) return;

	float monthlyFee = -1.0f;
	if (isVip == "1") {
		monthlyFee = showMenuPartnerMonthlyFee();
		presenter->createNewPartner(name, lastName, monthlyFee);
	}
	else {
		presenter->createNewPartner(name, lastName);
	}
	showMenuPartnerInfo(this->presenter->getLastPartnerIdCreated(), name, lastName, isVip, monthlyFee);
}

void View::newBook()
{
	string title = "Nuevo Libro";
	cin.ignore();
	string name = showMenuGeneric(title, "Ingresa el nombre del nuevo libro");
	if (name == QUIT_KEY) return;

	string isbn = showMenuBookIsbnCode();
	if (isbn == QUIT_KEY) return;

	string author = showMenuGeneric(title, "Ingresa el autor del nuevo libro");
	if (author == QUIT_KEY) return;

	showMenuBookInfo(name, isbn, author);
	this->presenter->createNewBook(name, isbn, author);
}

void View::newExemplary()
{
	string title = "Nuevo Ejemplar";
	cin.ignore();
	string nameFindedBook = showMenuFindBookWithIsbnOrName(title);
	if (nameFindedBook == QUIT_KEY) return;

	string edition = showMenuGeneric(title, "Ingrese la edición del nuevo ejemplar");
	if (edition == QUIT_KEY) return;

	string ubication = showMenuGeneric(title, "Ingrese la ubicación del nuevo ejemplar");
	if (ubication == QUIT_KEY) return;

	this->presenter->createNewExemplary(edition, ubication);
	showMenuExemplaryInfo(this->presenter->getNameFindedBook(), edition, ubication);

}

void View::showExemplariesAvaiable()
{
	string title = "Ejemplares disponibles";
	cin.ignore();

	string nameFindedBook = showMenuFindBookWithIsbnOrName(title);
	if (nameFindedBook == QUIT_KEY) return;

	this->presenter->showExemplariesAvaiable();
}

void View::showHistory()
{
	this->presenter->showHistory();
}

void View::lendBook()
{
	string title = "Prestar Libro";
	string idOrName = "";
	string checkData = "2";
	cin.ignore();
	do {
		idOrName = showMenuFindPartnerWithIdOrName();
		if (idOrName == QUIT_KEY) return;
		checkData = showMenuCheckPartnerData();
		if (checkData == QUIT_KEY) return;
	} while (checkData == "2");
	
	if (this->presenter->findedPartnerCanTakeBook()) {
		string nameFindedBook = showMenuFindBookWithIsbnOrName(title);
		if (nameFindedBook == QUIT_KEY) return;

		if (this->presenter->getAmountExemplariesFindedBook() > 0) {
			this->presenter->lendBook();
			string type = this->presenter->getLastLendBookType();
			string bookName = this->presenter->getNameFindedBook();
			string time = this->presenter->getLastLendBookTime();
			string bookIsbn = this->presenter->getIsbnFindedBook();
			string edition = this->presenter->getLastLendBookExemplaryEdition();
			string fullName = this->presenter->getLastLendBookPartnerFullName();
			showMenuTitle(title);
			this->showHistoryElement(type, time, bookName, bookIsbn, edition, "", fullName);
		}
		else {
			showText("No existen ejemplares de este libro");
			return;
		}
	}
	else {
		showText("Este socio no puede pedir prestado mas libros");
		return;
	}
}

void View::registerReturn()
{
	string title = "Registrar Devolución";
	string idOrName = "";
	string checkData = "2";
	cin.ignore();
	do {
		idOrName = showMenuFindPartnerWithIdOrName();
		if (idOrName == QUIT_KEY) return;
		checkData = showMenuCheckPartnerData();
		if (checkData == QUIT_KEY) return;
	} while (checkData == "2");

	if (this->presenter->findedPartnerOwnsBooks() == 0) {
		showText("No tiene ningun libro en poseción");
		return;
	}

	bool partnerPossessBook = false;
	do {
		string nameFindedBook = showMenuFindBookWithIsbnOrName(title);
		if (nameFindedBook == QUIT_KEY) return;

		if (this->presenter->findBookWithdrawnExemplaries()) {
			partnerPossessBook = true;
		}
		else {
			showMenuTitle(title);
			showText("El socio no tiene este libro en poseción, presione enter y reintente");
			cin.get();
			cin.get();
		}
	} while (!partnerPossessBook);
	

	string edition = showMenuFindEditionWithdrawnExemplaries();
	if (edition == QUIT_KEY) return;

	this->presenter->registerReturn();
	string type = this->presenter->getLastReturnedBookType();
	string bookName = this->presenter->getNameFindedBook();
	string time = this->presenter->getLastReturnedBookTime();
	string bookIsbn = this->presenter->getIsbnFindedBook();
	string ubication = this->presenter->getLastReturnedBookUbication();
	string fullName = this->presenter->getLastReturnedBookPartnerFullName();
	showMenuTitle(title);
	this->showHistoryElement(type, time, bookName, bookIsbn, edition, ubication, fullName);
}

View::View()
{
	setlocale(LC_ALL, "es_Es");
	presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete presenter;
}

void View::showMenuTitle(string title)
{
	system("cls");
	showTextSeparator();
	showText(title);
	showTextSeparator();
	//showTextSeparator();
}

void View::showText(const string& text)
{
	cout << text << endl;
}

void View::showText(float text)
{
	cout << text << endl;
}

void View::showText(int text)
{
	cout << text << endl;
}

void View::showTextInLine(const string& text)
{
	cout << text;
}

void View::showTextInLine(float text)
{
	cout << text;
}

void View::showTextInLine(int text)
{
	cout << text;
}

void View::showHistoryElement(string action, string time, string bookName, string isbn, string edition, string libraryUbication, string fullName)
{
	showText("");

	showTextInLine("Movimiento: ");
	showText(action);

	showTextInLine("Nombre y Apellido: ");
	showText(fullName);

	showTextInLine("Fecha y Hora: ");
	showText(time);

	showTextInLine("Nombre del Libro: ");
	showText(bookName);

	showTextInLine("Código ISBN: ");
	showText(isbn);

	showTextInLine("Edición: ");
	showText(edition);

	if (libraryUbication != "") {
		showTextInLine("Ubicación en la Biblioteca: ");
		showText(libraryUbication);
	}
}

void View::showExemplariesAvaiable(string bookName, string isbn, string edition, string libraryUbication)
{
	showText("");

	showTextInLine("Nombre del Libro: ");
	showText(bookName);

	showTextInLine("Código ISBN: ");
	showText(isbn);

	showTextInLine("Edición: ");
	showText(edition);

	showTextInLine("Ubicación en la Biblioteca: ");
	showText(libraryUbication);
}