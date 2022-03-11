#include "Item.h"

Item::Item()
{
	id = 0;
	name = "";
	price = 0.0;

}

Item::Item(int pId, string pName, double pPrice)
{
	id = pId;
	name = pName;
	price = pPrice;

}

int Item::GetId()
{
	return id;
}

double Item::GetPrice()
{
	return price;
}

string Item::GetName()
{
	return name;
}

Item::~Item()
{
	//cout << "Destroying the memory.. or perhaps releasing." << endl;
}
