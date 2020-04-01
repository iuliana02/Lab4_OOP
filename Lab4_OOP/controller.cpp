#include <iostream>
#include <string>
#include "controller.h"
#include "repo.h"
using namespace std;

Controller::Controller()
{
}
Controller::~Controller()
{
}

void Controller::add()
{
	cout << "Name des Medikaments\n";
	string name;
	cin >> name;
	cout << "Konzentration des Medikaments\n";
	double konz;
	cin >> konz;
	bool ok = Stock::add_medicament(name, konz);
}

void Controller::remove()
{
}