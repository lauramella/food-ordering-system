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
	PrintGeneralAppInfo();
	notQuitting = true;
	int retVal = 0;
	while (notQuitting)
	{
		PrintMainQuestions();
		retVal = GetIntAnswer();
		switch (retVal) {
		case 1:
			PrintMenu();
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

void AppLauncher::PrintGeneralAppInfo()
{
	cout << line << endl;
	cout << "\n\t\t FOOD ORDERING APP      " << endl;
	cout << "\t    Welcome to Pizza restaurant" << endl;;
}

void AppLauncher::PrintMainQuestions()
{
	cout << line << endl;
	cout << "\nWhat would you like to do?" << endl;
	cout << "\n1) Print the menu" << endl;
	cout << "2) Place an order" << endl;
	cout << "3) Review your order" << endl;
	cout << "4) Check out" << endl;
	cout << "5) Exit" << endl;
	cout << "> ";
}

void AppLauncher::PrintMenu()
{
	cout << line << endl;
	cout << "\nPIZZAS" << endl;
	cout << "\n1. MARGHARITA                                  13,90e" << endl;
	cout << "- mozzarella, parmesan, tomato, basil" << endl;
	cout << "2. FUNGHI                                      14,90e" << endl;
	cout << "- mushroom, mozzarella, rucola, olive oil" << endl;
	cout << "3. QUATTRO FORMAGGI                            15,90e" << endl;
	cout << "- mozzarella, gorgonzola, parmesan, chevre" << endl;
	cout << "4. CHEVRE - AUBERGINE                          15,90e" << endl;
	cout << "- chevre, aubergine, mozzarella, tomato, rucola" << endl;
	cout << "5. VEGAN                                       16,90e" << endl;
	cout << "- beanit, tomato, soya-pesto cream, jalopenos," << endl;
	cout << "beer yeast flakes, rucola" << endl;
	cout << "\nDRINKS              2,50e" << endl;
	cout << "\n 6. Coca-cola" << endl;
	cout << " 7. Coca-cola zero" << endl;
	cout << " 8. Fanta" << endl;
	cout << " 9. Sprite" << endl;
	cout << "10. Vichy" << endl;
}

int AppLauncher::GetIntAnswer()
{
	//Default negative for the signaling purposes
	int retVal = -1;
	string userInput = "";
	getline(cin, userInput);
	try {
		retVal = stoi(userInput);
		cout << retVal << endl;
	}
	catch (invalid_argument const&) {
		//cout << "Bad input: std::invalid_argument thrown" << endl;
	}
	catch (out_of_range const&) {
		//cout << "Integer overflow: std::out_of_range thrown" << endl;
	}
	return retVal;
}

string AppLauncher::GetStringAnswer()
{
	string userInput = "";
	do {
		getline(cin, userInput);
	} while (userInput.empty());
	return userInput;
}

AppLauncher::~AppLauncher()
{
	//cout << "Destroying the memory.. or perhaps releasing." << endl;
	delete[] items;
	delete[] choices;
}
