#pragma once
#include <iostream>

using namespace std;

class Item
{
private:
	int id;
	string name;
	double price;

public:
	Item();
	Item(int pId, string pName, double pPrice);
	~Item();
	string GetName();
	int GetId();
	double GetPrice();
};

