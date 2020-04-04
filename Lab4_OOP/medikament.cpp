#include <string>
//#include "repo.h"
#include <iostream>
#include "medikament.h"
using namespace std;

//constructor
Medikament::Medikament()
{
}
Medikament::Medikament(string name, double konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}

//gettere
string Medikament::get_name() 
{
	return name;
}
double Medikament::get_konz() 
{
	return konzentration;
}
int Medikament::get_menge() 
{
	return menge;
}
double Medikament::get_preis() 
{
	return preis;
}
//settere
void Medikament::set_name(string name) 
{
	name=name;
}
void Medikament::set_konz (double k) 
{
	konzentration=k;
}
void Medikament::set_menge(int menge) 
{
	menge=menge;
}
void Medikament::set_preis (double preis) 
{
	preis=preis;
}

void Medikament::add_menge(int m)
{
	menge += m;
}
void Medikament::remove_menge(int m)
{
	menge -= m;
}

Medikament::~Medikament()
{
}