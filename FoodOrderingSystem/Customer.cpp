#include "Customer.h"
#include <string>

Customer::Customer()
{
	name = "";
	phoneNumber = "";
	delivery = false;
	address = "";
	payment = "";
}

Customer::Customer(string pName, string pPhoneNumber, bool pDelivery, string pAddress, string pPayment)
{
	name = pName;
	phoneNumber = pPhoneNumber;
	delivery = pDelivery;
	address = pAddress;
	int retVal = stoi(pPayment);
	payment = paymentsArray[retVal - 1];
}

void Customer::PrintDelivery()
{
	cout << "Are these correct? (y/n)" << endl;
	cout << "\nName: " << name << endl;
	cout << "Phone number: " << phoneNumber << endl;
	cout << "Order type: Delivery" << endl;
	cout << "Address: " << address << endl;
	cout << "Payment: " << payment << endl;

}

void Customer::PrintPickUp()
{
	cout << "Are these correct? (y/n)" << endl;
	cout << "Name: " << name << endl;
	cout << "Phone number: " << phoneNumber << endl;
	cout << "Order type: Pick up" << endl;
	cout << "Payment: " << payment << endl;
}

Customer::~Customer()
{
	//cout << "Destroying the memory.. or perhaps releasing." << endl;
}
