#ifndef DB_TEXT_FILE_ADAPTER
#define DB_TEXT_FILE_ADAPTER

#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

#include "IDBAdapter.h"

using namespace std;

struct User
{
	string cQueriedLogin;   
	string cQueriedPassword;
};

class DBTextFileAdapter : public IDBAdapter
{
protected:  
	fstream *file;
public:
	DBTextFileAdapter(string aFilename);
	~DBTextFileAdapter();
	virtual void save(string aQueriedLogin, string aQueriedPassword);
	virtual void removeUser(string aQueriedLogin);
	virtual string *get(string aQueriedLogin);
};

#endif