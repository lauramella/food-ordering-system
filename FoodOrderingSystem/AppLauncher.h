#pragma once
#include "Item.h"

class AppLauncher
{
private:
	bool notQuitting = true;
	Item* items;  //Pointer to an Equipment type object/array
	Item* choices;
	int itAmount;
	string line;


public:
	AppLauncher();
	void Run();
	~AppLauncher();
};

