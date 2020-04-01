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
string Medikament::get_name() const
{
	return this->name;
}
double Medikament::get_konz() const
{
	return this->konzentration;
}
int Medikament::get_menge() const
{
	return this->menge;
}
double Medikament::get_preis() const
{
	return this->preis;
}
//settere
void Medikament::set_name(string name) 
{
	this->name=name;
}
void Medikament::set_konz (double k) 
{
	this->konzentration=k;
}
void Medikament::set_menge(int menge) 
{
	this->menge=menge;
}
void Medikament::set_preis (int preis) 
{
	this->preis=preis;
}

Medikament::~Medikament()
{
}