#include <set.hpp>

#include <kdb.hpp>

#include <iostream>

using namespace std;
using namespace kdb;

SetCommand::SetCommand()
{}

int SetCommand::execute(int argc, char**argv)
{
	if (argc != 3 && argc != 4)
	{
		cerr << "Please provide a name and a value to set" << endl;
		cerr << "Usage: set <name> [<value>]" << endl;
		cerr << "If no value is given, it will be set to a null-value" << endl;
		cerr << "To get an empty value you need to quote like \"\" (depending on shell)" << endl;
		return 1;
	}

	std::string name = argv[2];

	bool nullValue = false;
	if (argc == 3) nullValue = true;

	std::string value;

	if (!nullValue) value = argv[3];

	KeySet conf;
	Key k(name, KEY_END);

	// do not resume on any get errors
	// otherwise the user might break
	// the config
	kdb.get(conf, k);
	printWarnings(k);

	Key key = conf.lookup(name);

	if (!key)
	{
		cout << "create a new key " << name;
		key = Key(name, KEY_END);
		if (!nullValue)
		{
			cout << " with string " << value << endl;
			key.setString(value);
		} else {
			cout << " with null value" << endl;
			key.setBinary(0, 0);
		}
		if (!key.isValid())
		{
			cerr << "no valid name supplied" << endl;
			return 1;
		}
		conf.append(key);
	} else {
		if (!nullValue)
		{
			cout << "Set string to " << value << endl;
			key.setString(value);
		} else {
			cout << "Set null value" << endl;
			key.setBinary(0, 0);
		}
	}
	Key n;
	kdb.set(conf, n);
	printWarnings(n);

	return 0;
}

SetCommand::~SetCommand()
{}
