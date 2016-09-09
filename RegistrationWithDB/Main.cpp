#include <iostream>
#include <conio.h>
#include "IDBAdapter.h"
#include "DBTextFileAdapter.h"
#include "BusinessLogic.h"
#include "View.h"
#include "DBRAMAdapter.h"
#include "DBBinaryAdapter.h"

using namespace std;

int main()
{
	IDBAdapter *txtAdapter = new DBTextFileAdapter("userdata.txt");
	BusinessLogic *businessLogic = new BusinessLogic(txtAdapter);
	View *view = new View(businessLogic);
	view->UI();

	delete txtAdapter;
	delete businessLogic;
	delete view; 

	_getch();
	return 0;
}