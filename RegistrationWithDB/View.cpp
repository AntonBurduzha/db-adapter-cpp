#include "View.h"

View::View(BusinessLogic *cBusinessLogic)
{
	this->cBusinessLogic = cBusinessLogic;
}

View::~View()
{
}

void View::UI()
{
	cout << "Choose operation.\n\n"
		<< "1 - create account\n"
		<< "2 - log in\n"
		<< "3 - delete account\n"
		<< "0 - exit\n";
	int choose = 9;
	while (choose != 0)
	{
		cin >> choose;
		switch (choose)
		{
		case 1:
			do
			{
				cout << "Input new login: ";
				cin >> cUserLogin;
				cout << "Input new password: " << endl;
				cin >> cUserPass;
				if (cBusinessLogic->createUser(cUserLogin, cUserPass))
				{
					cout << "Succesfull! Created" << endl;
					break;
				}
				else
				{
					cout << "Failed! Select another username" << endl;
				}
			} while (!cBusinessLogic->createUser(cUserLogin, cUserPass));
			break;
		case 2:
			do
			{
				cout << "Input your login: ";
				cin >> cUserLogin;
				cout << "Input your password: " << endl;
				cin >> cUserPass;
				if (cBusinessLogic->checkLogin(cUserLogin, cUserPass))
				{
					cout << "Succesfull! You log in" << endl;
					break;
				}
				else
				{
					cout << "Failed! Input another login or password" << endl;
				}
			} while (!cBusinessLogic->checkLogin(cUserLogin, cUserPass));
			break;
		case 3:
			do
			{
				cout << "Input your login: ";
				cin >> cUserLogin;
				cout << "Input your password: " << endl;
				cin >> cUserPass;
				if (cBusinessLogic->deleteUser(cUserLogin, cUserPass))
				{
					cout << "Succesfull! Deleted" << endl;
					break;
				}
				else
				{
					cout << "Failed! Input another login or password" << endl;
				}
			} while (!cBusinessLogic->deleteUser(cUserLogin, cUserPass));
			break;
		}
	}
}