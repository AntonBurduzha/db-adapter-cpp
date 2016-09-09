#ifndef VIEW
#define VIEW

#include "BusinessLogic.h"
#include <string>
#include <iostream>

using namespace std;

class View
{
protected:
	BusinessLogic *cBusinessLogic;
	string cUserLogin;
	string cUserPass;
	int choose;

public:
	View(BusinessLogic *cBusinessLogic);
	~View();
	void UI();

};

#endif