#ifndef ORACLE_H
#define ORACLE_H

#include <cstdio>
#include <syslog.h>
#include <iostream>

namespace oracle
{
	extern bool use_syslog;
	extern int log_level;

	#define LOG(PRIO, ...) 					\
		if (use_syslog)						\
		{									\
			syslog((PRIO), __VA_ARGS__);	\
		}									\
		else if ((PRIO) <= log_level)		\
		{									\
			printf(__VA_ARGS__);			\
			printf("\n");					\
		}

	//fuzzy logic interpretation
	template<typename T, T tol = static_cast<T>(1e-4)>
	struct Divinate 
	{
		T truth;

		inline bool 
		operator==(const T& meas) const 
		{
			return std::abs(truth - meas) <= tol;
		}

		inline bool
		operator!=(const T& meas) const 
		{
			return not (*this == meas);
		}
		
	};

} // namespace oracle

#endif //ORACLE_H