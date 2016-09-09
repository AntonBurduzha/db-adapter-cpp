#include "DBBinaryAdapter.h"

DBBinaryAdapter::DBBinaryAdapter(string aFilename)
{
	binfile = new fstream(aFilename, ios::binary | ios::in | ios::out | ios::app);
	counter = 0;
}

DBBinaryAdapter::~DBBinaryAdapter()
{
	binfile->close();
}

void DBBinaryAdapter::save(string aQueriedLogin, string aQueriedPassword)
{
	binfile->clear();
	userinfo[counter]->cQueriedLogin = aQueriedLogin;
	userinfo[counter]->cQueriedPassword = aQueriedPassword;
	userinfo[counter]->cDelFlag = false;
	binfile->write((char*)&userinfo, sizeof(userinfo));
	counter++;
}

string *DBBinaryAdapter::get(string aQueriedLogin)
{
	binfile->clear();
	binfile->seekg(0, ios_base::beg);
	binfile->read((char*)&userinfo, sizeof(userinfo));

	for (int i = 0; i < 50; i++)
	{
		if (userinfo[i]->cQueriedLogin == aQueriedLogin)
		{
			return &userinfo[i]->cQueriedPassword;
		}
	}
	return NULL;
}

void DBBinaryAdapter::removeUser(string aQueriedLogin)
{
	binfile->clear();
	binfile->seekg(0);
	binfile->read((char*)&userinfo, sizeof(userinfo));

	for (int i = 0; i < 50; i++)
	{
		if (userinfo[i]->cQueriedLogin == aQueriedLogin)
		{
			userinfo[i]->cDelFlag = true;
			break;
		}
	}
	fstream *current = new fstream("userdatabin1.txt", ios::binary | ios::in | ios::out | ios::app);
	current->seekp(0);
	current->write((char*)&userinfo, sizeof(userinfo));

	current->close();
	delete current;
	binfile->close();
	delete binfile;
	remove("userdatabin.txt");
	rename("userdatabin1.txt", "userdatabin.txt");
	binfile = new fstream("userdatabin.txt", ios::binary | ios::in | ios::out | ios::app);
}
