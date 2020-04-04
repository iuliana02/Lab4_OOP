#include <iostream>
#include <fstream>
#include <string>
#include "controller.h"
#include "UI.h"
using namespace std;

Controller::Controller() : Stock()
{
}

void Controller::add()
{
	read_data(medicamente);
	cout << "Name des Medikaments\n";
	string name;
	cin >> name;
	cout << "Konzentration des Medikaments\n";
	double konz;
	cin >> konz;
	bool ok = Stock::add_medicament(name, konz);
	while (ok == false) //nu am adaugat inca medicament
	{
		cout << "Name des Medikaments\n";
		string name;
		cin >> name;
		cout << "Konzentration des Medikaments\n";
		double konz;
		cin >> konz;
		bool ok = Stock::add_medicament(name, konz);
	}
	write_data(medicamente);
}

void Controller::remove()
{
	read_data(medicamente);
	cout << "Name des Medikaments\n";
	string name;
	cin >> name;
	cout << "Konzentration des Medikaments\n";
	double konz;
	cin >> konz;
	bool ok = Stock::remove_medicament(name, konz);
	while (ok == false) //nu am adaugat inca medicament
	{
		cout << "Name des Medikaments\n";
		string name;
		cin >> name;
		cout << "Konzentration des Medikaments\n";
		double konz;
		cin >> konz;
		bool ok = Stock::remove_medicament(name, konz);
	}
	write_data(medicamente);
}


void Controller:: read_data(vector <Medikament>& v)
{
	fstream f;
	f.open("data.txt");

	string aux;
	const string* aux2;
	while (!f.eof())
	{
		Medikament med;
		f >> aux;
		med.set_name(aux);
		f >> aux;
		double konz = atof(aux.c_str());
		med.set_konz(konz);
		f >> aux;
		int menge = stoi(aux);
		med.set_menge(menge);
		f >> aux;
		double preis = atof(aux.c_str());
		med.set_preis(preis);

		v.push_back(med);
	}
	v.erase(v.end() - 1);
	f.close();
}

void Controller:: write_data(vector <Medikament> v)
{
	fstream f;
	f.open("data.txt");

	for (int i = 0; i <= v.size(); i++)
		f << v[i].get_name() << " " << v[i].get_konz() << " " << v[i].get_menge() << " " << v[i].get_preis() << endl;
	f.close();
}

Controller::~Controller()
{
}