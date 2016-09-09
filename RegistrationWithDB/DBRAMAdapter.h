#ifndef DB_RAM_ADAPTER
#define DB_RAM_ADAPTER

#include <string>
#include <vector>
#include "IDBAdapter.h"

using namespace std;

struct Info
{
	string cQueriedLogin;
	string cQueriedPassword;
};

class DBRAMAdapter : public IDBAdapter
{
protected:
	vector<Info>ram;

public:
	~DBRAMAdapter();
	virtual void save(string aQueriedLogin, string aQueriedPassword);
	virtual void removeUser(string aQueriedLogin);
	virtual string *get(string aQueriedLogin);
};

#endif