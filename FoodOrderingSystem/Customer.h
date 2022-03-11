#pragma once
#include <iostream>

using namespace std;
class Customer
{
private:
	string name;
	string phoneNumber;
	bool delivery;
	string address;
	string payment;
	string paymentsArray[3]{ "Credit card", "Mobile pay", "Smartum" };

public:
	Customer();
	Customer(string pName, string pPhoneNumber, bool pDelivery, string pAddress, string pPayment);
	~Customer();
	void PrintDelivery();
	void PrintPickUp();
};

