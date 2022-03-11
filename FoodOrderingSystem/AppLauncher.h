#pragma once
#include "Item.h"
#include "Customer.h"

class AppLauncher
{
private:
	bool notQuitting;
	Item* items; 
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
	void GetOrderMenu();
	bool AddItem(int pRetVal);
	void ReviewTheOrder();
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

