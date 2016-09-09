#include "DBTextFileAdapter.h"

using namespace std;

DBTextFileAdapter::DBTextFileAdapter(string aFilename)
{
	file = new fstream(aFilename, ios::in | ios::out | ios::app);
}

DBTextFileAdapter::~DBTextFileAdapter()
{
	file->close();
}

void DBTextFileAdapter::save(string aQueriedLogin, string aPassword)
{
	file->clear();
	file->seekp(0, ios_base::end);
	*file << aQueriedLogin << " " << aPassword << endl;
}

string *DBTextFileAdapter::get(string aQueriedLogin)
{
	file->clear();
	User *user = new User;
	file->seekg(ios_base::beg);
	while (*file >> user->cQueriedLogin >> user->cQueriedPassword)
	{
		if (user->cQueriedLogin == aQueriedLogin)
		{
			return &(user->cQueriedPassword);
		}
	}
	return nullptr;
}

void DBTextFileAdapter::removeUser(string aQueriedLogin)
{
	User user;
	file->clear();
	file->seekg(0);
	fstream *current = new fstream("userdata1.txt", ios::in | ios::out | ios::app);
	while (*file >> user.cQueriedLogin >> user.cQueriedPassword)
	{
		if (user.cQueriedLogin != aQueriedLogin)
		{
			*current << user.cQueriedLogin << " " << user.cQueriedPassword << endl;
		}
	}
	
	current->close();
	delete current;
	file->close();
	delete file;
	remove("userdata.txt");
	rename("userdata1.txt", "userdata.txt");
	file = new fstream("userdata.txt", ios::in | ios::out | ios::app);
}