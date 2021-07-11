#include "ls/Logger.h"
#include "vector"

using namespace std;

vector<string> loggerType({
	"I", "W", "E"
});

namespace ls
{
	Logger::Logger()
	{

	}

	Logger &Logger::operator<<(Logger &(*pf)(Logger &))
	{
		return pf(*this);
	}

	Logger &endl(Logger &logger)
	{
		logger.log("\n");
		logger.unlock();
		return logger;
	}

	Logger &Logger::operator()(LOGGER_TYPE type, const char *filename, int line)
	{
		lock();
		*this << logTime() << " " << filename << " / line " << line
		<< " / [" << loggerType[type] << "] ";
		return *this;
	}
}
