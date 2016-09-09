#ifndef BUSINESS_LOGIC
#define BUSINESS_LOGIC

#include "IDBAdapter.h"
#include "md5.h"
#include <string>

using namespace std;

class BusinessLogic
{
protected:
	IDBAdapter *adapter;

public:
	BusinessLogic(IDBAdapter *adapter);
	~BusinessLogic();
	bool createUser(string aInputedLogin, string aInputedPassword);
	bool checkLogin(string aInputedLogin, string aInputedPassword);
	bool deleteUser(string aInputedLogin, string aInputedPassword);
};

#endif