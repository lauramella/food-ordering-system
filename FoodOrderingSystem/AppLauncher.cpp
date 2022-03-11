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
			OrderMenu();
			break;
		case 3:
			ReviewYourOrder();
			break;
		case 4:
			for (int i = 0; i < itAmount;i++)
			{
				if (!(items[i].GetName() == ""))
				{
					Checkout();
					break;
				}
				else if (i == itAmount - 1)
				{
					cout << "\nYou haven't order anything." << endl;
				}
			}
			break;
		case 5:
			QuitProgram();
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

void AppLauncher::OrderMenu()
{
	cout << line << endl;
	cout << "\nChoose number you would like to add to your order    (Press 0 to go back)" << endl;
	cout << "\n1. Margharita               13,90e    6. Coca-cola       2,50e" << endl;
	cout << "2. Funghi                   14,90e    7. Coca-cola zero  2,50e" << endl;
	cout << "3. Quattro Formaggi         15,90e    8. Fanta           2,50e" << endl;
	cout << "4. Chevre - Aubergine       15,90e    9. Sprite          2,50e" << endl;
	cout << "5. Vegan                    16,90e   10. Vichy           2,50e" << endl;
	cout << "> ";
	int retVal = GetIntAnswer();
	bool itemAdded = false;
	if (retVal > 0 && retVal <= 10)
	{
		string orderMore = "";
		cout << "How many would you like to add?" << endl;
		cout << "> ";
		int amount = GetIntAnswer();
		for (int i = 0; i < amount; i++)
		{
			itemAdded = AddItem(retVal);
		}
		if (itemAdded == true)
		{
			cout << "***Item/Items added***" << endl;
			cout << "Do you want to continue the order (y/n)?" << endl;
			cout << "> ";
			orderMore = GetStringAnswer();
			if (orderMore == "y")
			{
				OrderMenu();
			}
		}
		else
		{
			cout << "Couldn't add item. Your order is already full!" << endl;
		}
	}
	else if (retVal != 0)
	{
		cout << "You didn't give right number. Try again." << endl;
		OrderMenu();
	}
}

bool AppLauncher::AddItem(int pRetVal)
{
	bool retVal = false;
	for (int i = 0; i < itAmount; i++)
	{
		if (items[i].GetName() == "")
		{
			items[i] = choices[pRetVal - 1];
			retVal = true;
			break;
		}
	}
	return retVal;
}

void AppLauncher::ReviewYourOrder()
{
	PrintOrder();
	cout << "\nChoose an option(1=edit your order, 2=delete your order 3=check out 4=menu)" << endl;
	cout << "> ";
	int retVal = GetIntAnswer();
	switch (retVal)
	{
	case 1:
		PrintOrder();
		EditOrder();
		ReviewYourOrder();
		break;
	case 2:
		DeleteOrder();
		break;
	case 3:
		for (int i = 0; i < itAmount;i++)
		{
			if (!(items[i].GetName() == ""))
			{
				Checkout();
				break;
			}
			else if (i == itAmount - 1)
			{
				cout << "\nYou haven't order anything." << endl;
			}
		}
		break;
	default:
		cout << "";
	}
}

void AppLauncher::PrintOrder()
{
	int printList[10]{ 0 };
	bool empty = true;
	double price{ 0.0 };
	cout << line << endl;
	cout << "\nYOUR ORDER:\n" << endl;
	for (int i = 0; i < itAmount; i++)
	{
		if (items[i].GetName() != "")
		{
			int id = items[i].GetId();
			printList[id - 1] += 1;
			price += items[i].GetPrice();
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (printList[i] > 0)
		{
			cout << choices[i].GetId() << ".  " << printList[i] << "kpl " << choices[i].GetName() << endl;
			empty = false;
		}
	}
	if (empty == false)
	{
		if (fmod(price, 1) == 0)
		{
			cout << "\nTotal price: " << price << ".00e" << endl;
		}
		else
		{
			cout << "\nTotal price: " << price << "0e" << endl;
		}
	}
	else
	{
		cout << "You haven't order anything." << endl;
	}
}

void AppLauncher::EditOrder()
{
	cout << "\nChoose number you want to delete" << endl;
	cout << "> ";
	int retVal = GetIntAnswer();
	for (int i = 0; i < itAmount; i++)
	{
		if (items[i].GetId() == retVal)
		{
			items[i] = *new Item();
			cout << "\n***Item deleted!***" << endl;
			break;
		}
	}
}

void AppLauncher::DeleteOrder()
{
	cout << "Are you sure you want to delete your order? (y/n)" << endl;
	cout << "> ";
	string retVal = GetStringAnswer();
	if (retVal == "y")
	{
		items = new Item[150];
		itAmount = 150;
		cout << "\n***Your order is deleted.***" << endl;
	}
}

void AppLauncher::Checkout()
{
	PrintOrder();
	cout << "\nIs your order ready? (y/n)" << endl;
	cout << "> ";
	string retVal = GetStringAnswer();
	if (retVal == "y")
	{
		GetCustomerData();
	}
	else
	{
		Run();
	}
}

void AppLauncher::GetCustomerData()
{
	bool cDelivery = false;
	string cPayment, cAnswer;
	cout << line << endl;
	cout << "\nDELIVERY DETAILS" << endl;
	cout << "\nName: ";
	string cName = GetStringAnswer();
	cout << "Phone number: ";
	string cPhoneNumber = GetStringAnswer();
	cout << "Do you want delivery? (y/n) > ";
	do {
		cAnswer = GetStringAnswer();
	} while ((cAnswer != "n") && (cAnswer != "y"));
	cout << "How would you like to pay? (1.credit card 2.mobile pay 3.smartum) > ";
	do {
		cPayment = GetStringAnswer();
	} while ((cPayment != "1") && (cPayment != "2") && (cPayment != "3"));
	if (cAnswer == "y")
	{
		cDelivery = true;
		cout << "Address: ";
		string cAddress = GetStringAnswer();
		Customer customer = Customer(cName, cPhoneNumber, cDelivery, cAddress, cPayment);
		cout << line << endl;
		customer.PrintDelivery();
	}
	else
	{
		cout << line << endl;
		Customer customer = Customer(cName, cPhoneNumber, cDelivery, "", cPayment);
		customer.PrintPickUp();
	}
	cout << "> ";
	string answer = GetStringAnswer();
	if (answer == "y")
	{
		FinalChoice();
	}
	else
	{
		GetCustomerData();
	}
}

void AppLauncher::FinalChoice()
{
	cout << line << endl;
	cout << "\nTHANK YOU FOR YOUR ORDER! Your order will be ready in 30min." << endl;
	cout << "\n1. Place new order" << endl;
	cout << "2. Quit the app" << endl;
	int retVal = GetIntAnswer();
	if (retVal == 2)
	{
		QuitProgram();
	}
	else
	{
		items = new Item[150];
		itAmount = 150;
		Run();
	}
}

void AppLauncher::QuitProgram()
{
	notQuitting = false;
	cout << line << endl;
	cout << "\t\tQuitting the app" << endl;
	cout << line << endl;
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
