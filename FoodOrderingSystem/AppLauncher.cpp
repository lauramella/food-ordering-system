#include "AppLauncher.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

AppLauncher::AppLauncher()
{
	notQuitting = false;
	items = new Item[150];
	choices = new Item[10]{ *new Item(1, "Margharita", 13.90), *new Item(2, "Funghi", 14.90), *new Item(3, "Quattro Formaggi", 15.90), *new Item(4, "Chevre-Aubergine", 15.90), *new Item(5, "Vegan", 16.90),
		*new Item(6, "Coca-cola", 2.50) ,*new Item(7, "Coca-cola zero", 2.50) ,*new Item(8, "Fanta", 2.50) ,*new Item(9, "Sprite", 2.50) ,*new Item(10, "Vichy", 2.50) };
	itAmount = 100;
	line = "_________________________________________________________";
}

void AppLauncher::Run()
{
	//PrintGeneralAppInfo();
	notQuitting = true;
	int retVal = 0;
	while (notQuitting)
	{
		//PrintMainQuestions();
		//retVal = GetIntAnswer();
		switch (retVal) {
		case 1:
			//PrintMenu();
			break;
		case 2:
			//OrderMenu();
			break;
		case 3:
			//ReviewYourOrder();
			break;
		case 4:
			for (int i = 0; i < itAmount;i++)
			{
				if (!(items[i].GetName() == ""))
				{
					//Checkout();
					break;
				}
				else if (i == itAmount - 1)
				{
					cout << "\nYou haven't order anything." << endl;
				}
			}
			break;
		case 5:
			//QuitProgram();
			break;
		default:
			cout << "You did not give a correct answer! Please try again!" << endl;
		}
	}
}
