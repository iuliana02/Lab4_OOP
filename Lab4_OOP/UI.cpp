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
	cout << "Medikament einfugen\n" << "Medikament loschen\n" << "Medikament bearbeiten\n";
	cout << "Gruppieren nach einem String\n";
	cout << "Medikamente knapper als...\n";
	cout << "Gruppieren nach Preis\n";
	cout << endl;

}

void UI::functii()
{
	Controller::add();
	Controller::remove();
}

