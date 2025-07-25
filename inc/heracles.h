#ifndef HERACLES_H
#define HERACLES_H

#include <map>
#include <functional>
#include <cstdint>
#include <string>
#include <expected>
#include <chrono>

#include "pythia.h"

namespace oracle
{

	// Instructions for running a test
	struct Labor
	{
		using expectation_t = std::expected<int, std::string>;
		using labor_f = std::function<expectation_t(void*)>;
		
		uint8_t id;
		std::string name;
		labor_f labor;
		void* instructions;

		const expectation_t operator()()
		{
			expectation_t result = labor(instructions);

			return result;
		}

		bool operator==(const Labor& l) const
		{
			return id == l.id;
		}
		
		bool operator<(const Labor& l) const
		{
			return id < l.id;
		}
	};
	
	class Heracles
	{    
		private:
			std::map<uint8_t, Labor> labors_; ///< The labors of Heracles
		public:
			Heracles() = default;
			virtual ~Heracles() = default;
			
			bool 
			add_labor(uint8_t id, const std::string& name, Labor::labor_f labor, void* instructions = nullptr)
			{
				auto [it, inserted] = labors_.try_emplace(id, 
					Labor{id, name, labor, instructions});
				return inserted;
			}
						
			void
			perform_labors()
			{
				for (auto& [id, labor] : labors_)
					Pythia::judge(labor.name.c_str(), labor());
			}
	};
	
} // namespace oracle

#endif // HERACLES_H