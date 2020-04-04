#pragma once
#include "repo.h"

class Controller : public Stock
{
public:
	Controller();
	~Controller();

	void add();
	void remove();


	void read_data(vector<Medikament>& v);
	void write_data(vector<Medikament> v);


};