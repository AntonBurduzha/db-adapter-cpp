#include "BusinessLogic.h"

BusinessLogic::BusinessLogic(IDBAdapter *adapter)
{
	this->adapter = adapter;
}

BusinessLogic::~BusinessLogic()
{
}

bool BusinessLogic::createUser(string aInputedLogin, string aInputedPassword)
{
	if (!adapter->get(aInputedLogin))
	{
		string hashedPass = md5(aInputedPassword);
		adapter->save(aInputedLogin, hashedPass);
		return true;
	}
	return false;
}

bool BusinessLogic::checkLogin(string aInputedLogin, string aInputedPassword)
{
	return (adapter->get(aInputedLogin)->c_str() == md5(aInputedPassword));
}

bool BusinessLogic::deleteUser(string aInputedLogin, string aInputedPassword)
{
	if (checkLogin(aInputedLogin, aInputedPassword))
	{
		adapter->removeUser(aInputedLogin);
		return true;
	}
	return false;
}

