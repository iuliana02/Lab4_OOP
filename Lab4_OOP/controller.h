#pragma once
#include "repo.h"

class Controller : public Stock
{
public:
	Controller();
	~Controller();

	void add();
	void remove();
};