#include <ls.hpp>

#include <iostream>

#include <kdb.hpp>

using namespace kdb;
using namespace std;

LsCommand::LsCommand()
{}

int LsCommand::execute(int argc, char** argv)
{
	if (argc != 3)
	{
		cerr << "Please provide a name" << endl;
		cerr << "Usage: ls <name>" << endl;
		return 1;
	}

	Key root (argv[2], KEY_END);
	if (!root.isValid())
	{
		cerr << "Not a valid name supplied" << endl;
		return 1;
	}

	kdb.get(ks, root);

	KeySet part (ks.cut(root));
	part.rewind();
	Key k;
	while (k=part.next())
	{
		cout << k << endl;
	}

	printWarnings(root);

	return 0;
}

LsCommand::~LsCommand()
{}
