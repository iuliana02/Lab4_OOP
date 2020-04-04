#include "repo.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Stock::Stock()
{
}

bool Stock::add_medicament(string name, double konz)
{
	int save_menge = 0, save_pos = 0; //pt functiile de redo/undo
	bool ok = false; //cu ok verific daca medicamentul exista sau trebe sa il adaug
	for (int i = 0; i < medicamente.size(); i++)
	{
		if ((medicamente[i].get_name() != name) && (medicamente[i].get_konz() != konz)) //daca nu exista medicamentul resp., adaug un nou obiect de tipul Medikament
		{
			cout << "Neues Produkt\n";
			cout << "Welche Menge wollen Sie einfugen?\n";
			int m;
			cin >> m;
			cout << "Welches Preis soll das Medikament haben?";
			int p;
			cin >> p;
			Medikament NeuesMed;
			NeuesMed.set_name(name);
			NeuesMed.set_konz(konz);
			NeuesMed.set_preis(p);
			NeuesMed.set_menge(m);
			medicamente.push_back(NeuesMed); //am adaugat in vectorul de medicamente noul medicament
			cout << "Eingefugen\n";
			save_menge = m;
			save_pos = i;
		}
		if (ok == false)//daca medicamentul exista, actualizez doar cantitatea
		{
			cout << "Der Medikament existiert schon\n";
			cout << "Welche Menge wollen Sie einfugen?\n";
			int m;
			cin >> m;
			medicamente[i].add_menge(m);//maresc cantitatea
			cout << "Eingefugen!";
			ok = true;
			save_pos = i;
			save_menge = m;
			//salvez indicele si cantitatea pt ca imi vor trebui pt functiile de redo/undo
		}
	}
	cout << "Wollen Sie Redo/Undo fur die vorige Operation machen?\n";
	string antwort;
	cin >> antwort;
	if (antwort == "Ja")
	{
		cout << "Redo->1 / Undo->2\n";
		int d;
		cin >> d;
		if (d == 1)//Redo 
		{
			//cresc cantitatea, indiferent daca initial am crescut cantitatea sau am adaugat un medicament nou, fiindca acum medicamentul exista sigur
			medicamente[save_pos].add_menge(save_menge);
			return true;
		}
		else if (d == 2)//daca fac Undo, sterg elementul inserat->return false
		{
			if (ok == false) //trebuie sa sterg medicamentul fiindca acesta nu exista inainte
				medicamente.erase(medicamente.begin() + save_pos);
			else //scad doar cantitatea
				medicamente[save_pos].remove_menge(save_menge);
			return false;
		}
	}
	else
		cout << "Ok, danke!\n";
	return true;
}


bool Stock::remove_medicament(string name, double konz)
{
	//ok1 il folosesc pt a verifica daca am gasit medicamentul, iar ok2 pt a semnala cand l-am sters
	bool ok1 = false,ok2=false;
	if (medicamente.size() == 0)
		cout << "Keine Medikamente zu loschen! Apotheke leer";
	else
	{
		int i = 0; 
		while (i <= medicamente.size())
		{
			if (medicamente[i].get_name() == name && medicamente[i].get_konz() == konz)
			{
				cout << "Medikament gefunden!";
				ok1 = true;
				if (i == 0) {
					medicamente.erase(medicamente.begin());//sterg primul element
					ok2 = true;
				}
				else {
					medicamente.erase(medicamente.begin() + i);
					ok2 = true;
				}
				i++;
			}
			else
			{
				ok1 = false; //nu am gasit inca medicamentul
			}
		}
		if (ok1 == false)
		{
			cout << "Der Medikament wurde nicht gefunden";
			return false;
		}
	}

	if (ok2 == true) //daca am sters medicamentul
	{
		//nu vad ce sens are sa fac redo daca am sters deja elementul
		cout << "Wollen Sie Undo zu der vorigen Operation machen?\n";
		string rasp;
		cin >> rasp;
		if (rasp == "Ja")
		{
			add_medicament(name, konz);
			cout << "Medikament wurde zuruck eingefugt";
			return false;
		}
	}
	return true;
} 


Stock::~Stock()
{
}