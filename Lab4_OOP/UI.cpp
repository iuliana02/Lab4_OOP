#include "UI.h"
#include <iostream>
#include <fstream>
using namespace std;

UI::UI()
{
}
UI::~UI()
{
}

void UI:: meniu()
{
	cout << "\tSmile Apotheke\n";
	cout << "1 - Medikament einfugen\n" << "2 - Medikament loschen\n" << "3 - Medikament bearbeiten\n";
	cout << "4 - Gruppieren nach einem String\n";
	cout << "5 - Medikamente knapper als...\n";
	cout << "6 - Gruppieren nach Preis\n";
	cout << "7 - Undo\n";
	cout << "8 - Redo\n";
	cout << "0 - Exit"<<endl;

}

void UI::functii()
{
	Controller ctrl = Controller();
	while (true)
	{
		meniu();

		int optiune;
		cout << "Alegeti optiunea: \n";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
		{
			
		}
		}
	}

}


