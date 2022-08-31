#include "string"

/*
	设置
		-写入方式
		-锁模式
		-时间格式
*/

namespace ls
{
	enum LOGGER_TYPE {
		INFO = 0, WARNING, ERROR
	 };
	class Logger
	{
		public:
			Logger();
			Logger &operator<<(Logger&(*pf)(Logger &));
			template<class T> Logger &operator<<(const T &message)
			{
				log(message);
				return *this;
			}
			friend Logger &endl(Logger &logger);
			Logger &operator()(LOGGER_TYPE type, const char *filename, int line);
			virtual void lock() = 0;
			virtual void unlock() = 0;
			virtual std::string logTime() = 0;
			virtual void log(int val) = 0;
			virtual void log(const std::string &val) = 0;
			virtual void log(const char *val) = 0;
			virtual void log(double val) = 0;
			virtual void log(long long val) = 0;
	};
	Logger& endl(Logger &logger);
}
