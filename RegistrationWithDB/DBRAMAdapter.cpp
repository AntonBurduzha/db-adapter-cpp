#include "DBRAMAdapter.h"

DBRAMAdapter::~DBRAMAdapter()
{
}

void DBRAMAdapter::save(string login, string password)
{
	Info info;
	info.cQueriedLogin = login;
	info.cQueriedPassword = password;
	ram.push_back(info);
}

void DBRAMAdapter::removeUser(string aQueriedLogin)
{
	for (auto it = ram.begin(); it != ram.end(); ++it)
	{
		if (it->cQueriedLogin == aQueriedLogin)
		{
			ram.erase(it);
			break;
		}
	}
}

string *DBRAMAdapter::get(string login)
{
	for (auto cur = ram.begin(); cur != ram.end(); ++cur)
	{
		if (cur->cQueriedLogin == login)
		{
			return &cur->cQueriedPassword;
		}
	}
	return NULL;
}
