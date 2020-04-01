#pragma once
#include <string>
#include <vector>
#include "medikament.h"
using namespace std;

class Stock
{
private:
	vector<Medikament> medicamente;

public:
	Stock();
	~Stock();

	bool add_medicament(string name, double konz);
	bool remove_medicament(string name, double konz);
};