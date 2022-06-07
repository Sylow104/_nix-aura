#pragma once
#include <string>
#include <map>
#include <time.h>
#include "Database/Account.hpp"

namespace db
{
	using std::string;
	using std::map;
	
	class ChannelDb /* : public AuraDb */
	{
		public:
		ChannelDb();
		~ChannelDb();

		Account get_Account(string accountID);
		

		protected:

		private:
	};
};