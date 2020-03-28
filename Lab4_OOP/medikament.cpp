#include <iostream>
#include "medikament.h"
using namespace std;

//constructor
Med::Med()
{
}
Med::Med(string name, double konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}

//gettere
string Med::get_name() const
{
	return this->name;
}
double Med::konzentration() const
{
	return this->konzentration;
}
int Med::get_menge() const
{
	return this->menge;
}
double Med::get_preis() const
{
	return this->preis;
}
//settere
void Med::set_name(string name) 
{
	this->name=name;
}
void Med::konzentration_s (double k) 
{
	this->konzentration=k;
}
void Med::set_menge(int menge) 
{
	this->menge=menge;
}
void Med::set_preis (int preis) 
{
	this->preis=preis;
}

Med::~Med()
{
}