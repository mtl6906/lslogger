#ifndef LS_DEFAULTLOGGER_H
#define LS_DEFAULTLOGGER_H

#include "ls/Logger.h"
#include "mutex"
#include "cstdlib"

#define LOGGER(type) if(type == ls::ERROR || getenv("ENABLE_LOGGER"))logger(type, __FILE__, __LINE__)

namespace ls
{
	class DefaultLogger : public Logger
	{
		public:
			DefaultLogger() = default;
			void log(const std::string &message) override;
			void log(const char *message) override;
			void log(int message) override;
			void log(double message) override;
			std::string logTime() override;
			void lock() override;
			void unlock() override;
		protected:
			std::mutex logMutex;
	};
	extern DefaultLogger logger;
}

#endif
