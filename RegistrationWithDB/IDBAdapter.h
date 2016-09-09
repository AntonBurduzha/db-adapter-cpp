#ifndef I_BD_ADAPTER_H
#define I_BD_ADAPTER_H

#include <string>

using namespace std;

class IDBAdapter
{
public:
	virtual void save(string, string) = 0;
	virtual void removeUser(string) = 0;
	virtual string *get(string) = 0;
};

#endif // !IBDADAPTER_H
