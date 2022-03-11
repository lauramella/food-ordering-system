#pragma once
#include "Item.h"
#include "Customer.h"

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

private:
	void PrintGeneralAppInfo();
	void PrintMenu();
	void PrintMainQuestions();
	void OrderMenu();
	bool AddItem(int pRetVal);
	void ReviewYourOrder();
	void PrintOrder();
	void EditOrder();
	void DeleteOrder();
	void Checkout();
	void GetCustomerData();
	void FinalChoice();
	void QuitProgram();
	int GetIntAnswer();
	string GetStringAnswer();
};

