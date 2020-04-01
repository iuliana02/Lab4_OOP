#include "controller.h"
#include "repo.h"
#include <iostream>
using namespace std;

int main()
{
	Stock repo;
	Medikament m1 = Medikament("Nurofen", 10, 23, 17);
	Medikament m2 = Medikament("Ibuprofen", 200, 15, 20);
	Controller::add();

}