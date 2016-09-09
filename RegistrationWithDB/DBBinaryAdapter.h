#ifndef DB_BINARY_ADAPTER
#define DB_BINARY_ADAPTER

#include "IDBAdapter.h"
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

struct UserInfo
{
	string cQueriedLogin;
	string cQueriedPassword;
	bool cDelFlag;
};

class DBBinaryAdapter : public IDBAdapter
{
protected:
	UserInfo *userinfo[50];
	fstream *binfile;
	int counter;

public:
	DBBinaryAdapter(string aFilename);
	~DBBinaryAdapter();
	virtual void save(string aQueriedLogin, string aQueriedPassword);
	virtual void removeUser(string aQueriedLogin);
	virtual string *get(string aQueriedLogin);
};

#endif