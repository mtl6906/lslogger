#include "ls/DefaultLogger.h"
#include "string"

using std::string;
using ls::endl;
using ls::logger;

int main()
{
	LOGGER(ls::INFO) << "abc: " << 2 << endl;
	LOGGER(ls::WARNING) << 1 << endl;
	LOGGER(ls::ERROR) << string("123") << endl;
	return 0;
}
