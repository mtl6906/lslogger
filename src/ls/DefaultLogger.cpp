#include "ls/DefaultLogger.h"
#include "ls/time/API.h"
#include "cstdio"

using namespace std;

namespace ls
{
	void DefaultLogger::log(const std::string &message)
	{
		log(message.c_str());
	}

	void DefaultLogger::log(const char *message)
	{
		printf("%s", message);
	}

	void DefaultLogger::log(int message)
	{
		printf("%d", message);
	}

	void DefaultLogger::log(double message)
	{
		printf("%lf", message);
	}

	void DefaultLogger::log(long long message)
	{
		printf("%lld", message);
	}

	void DefaultLogger::lock()
	{
		logMutex.lock();
	}

	void DefaultLogger::unlock()
	{
		logMutex.unlock();
	}

	string DefaultLogger::logTime()
	{
		return time::api.getStandardTime();
	}

	DefaultLogger logger;
}
