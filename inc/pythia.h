#ifndef PYTHIA_H
#define PYTHIA_H

#include <expected>
#include "oracle.h"

namespace oracle
{
	class Pythia 
	{
		public:
			template<typename T, typename E>
			static void 
			judge(const char* event, const std::expected<T, E>& result) 
			{
				if (result.has_value()) 
				{
					LOG(LOG_INFO, "[ OK ] %s: ", event);
				} 
				else 
				{
					const char* reason;
					if constexpr (std::is_same_v<E, std::string>) 
					{
						reason = result.error().c_str();
					} 
					else if constexpr (std::is_same_v<E, const char*>) 
					{
						reason = result.error();
					} 
					else 
					{
						reason = "unspecified failure";
					}
					LOG(LOG_ERR, "[ FAIL ] %s: %s", event, reason);
				}
			}
	};
}//namespace oracle

#endif //PYTHIA_H