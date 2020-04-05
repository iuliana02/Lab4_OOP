#include <iostream>
#include <fstream>
#include <string>
#include "controller.h"
//#include "UI.h"
using namespace std;

Controller::Controller() : Repo()
{
	repo = Repo();
}

bool Controller::is_empty()
{
	if (repo.len == 0)
		return true;
	return false;
}

bool Controller::search(Medikament m)
{
	if (is_empty())
	{
		return false;
	}
	for (int i = 0; i < repo.len; ++i)
	{
		if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
			return true;
	}
	return false;
}

void Controller::add(Medikament m)
{
	if (search(m) == false)
	{
		repo.med[repo.len] = m;
		repo.len++;
		if (repo.len == repo.capacity) 
		{
			//resize
			repo.capacity *= 2;
			Medikament* n = new Medikament[repo.capacity];
			for (int i = 0; i < repo.len; ++i)
				n[i] = repo.med[i];
			delete repo.med;
			repo.med = n;
		}
	}
	else //daca medicamentul exista deja, cresc doar cantitatea
	{
		for (int i = 0; i < repo.len; ++i)
		{
			if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
				repo.med[i].set_menge(repo.med[i].get_menge + m.get_menge());
		}
	}
	cout << repo.len << endl;
	action a;
	a.act = 1;
	a.m = m;
	istoric_undo.push_back(a);
}

void Controller::undo_add(Medikament m)
{
	if (search(m) == false)
	{
		repo.med[repo.len] = m;
		repo.len++;
		if (repo.len == repo.capacity) //container full
		{
			repo.capacity *= 2;
			Medikament* n = new Medikament[repo.capacity];
			for (int i = 0; i < repo.len; ++i)
				n[i] = repo.med[i];
			delete repo.med;
			repo.med = n;
		}
	}
	else
	{
		for (int i = 0; i < repo.len; ++i)
			if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
				repo.med[i].set_menge(repo.med[i].get_menge() + m.get_menge());
	}
	action a;
	a.act = 1;
	a.m = m;
	istoric_redo.push_back(a);
}

void Controller::remove(Medikament m)
{
	if (is_empty())
	{
		cout << "Apotheke leer\n";
		return;
	}
	if (search(m) == false)
	{
		cout << "Dieser Medikament existiert nicht.\n";
		return;
	}
	Medikament n;
	for (int i = 0; i < repo.len; ++i)
	{
		if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
		{
			m = repo.med[i];
			for (int k = i + 1; k < repo.len; ++k)
				repo.med[k - 1] = repo.med[k];
			repo.len--;
		}
	}
	action a;
	a.act = 3;
	a.m = n;
	istoric_undo.push_back(a);
}

void Controller::undo_remove(Medikament m)
{
	if (is_empty())
	{
		cout << "Apotheke leer\n";
		return;
	}
	if (search(m) == false)
	{
		cout << "Dieser Medikament existiert nicht\n";
		return;
	}
	for (int i = 0; i < repo.len; ++i)
	{
		if ((m.get_name() == repo.med[i].get_name()) && (m.get_konz() == repo.med[i].get_konz()))
		{
			for (int k = i + 1; k < repo.len; k++)
				repo.med[k - 1] = repo.med[k];
			repo.len--;
		}
	}
	action a;
	a.act = 3;
	a.m = m;
	istoric_redo.push_back(a);
}



Controller::~Controller()
{
	delete repo.med;
}