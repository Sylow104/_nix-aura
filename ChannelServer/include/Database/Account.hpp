#pragma once
#include <string>
#include <map>
#include <time.h>


class ScriptVariables {};
class Character {};
class Pet {};
class BankInventory {};
class PlayerCreature {};

namespace db
{
	using std::string;
	using std::map;

	class Autoban
	{
		public:
		Autoban();
		~Autoban();

		string Reason;
		time_t Expiration;
		time_t LastReduction;

		int get_Score();
		bool set_Score(int n_Score);

		int get_Count();
		bool set_Count(int n_Count);

		protected:

		private:
		int _Score;
		int _Count;
	};

	class Account
	{	
		public:
		Account();
		~Account();

		long SessionKey;
		int Authority;
		time_t LastLogin;
		map<long, Character* > Characters;
		map<long, Pet* > Pets;
		ScriptVariables *Vars;
		BankInventory *Bank;
		Autoban Ban;

		PlayerCreature *get_CharacterOrPet(long entityID);
		PlayerCreature *get_CharacterOrPetSafe(long entityID);
		Pet *get_Pet(long entityID);
		Pet *get_PetSafe(long entityID);
		
		protected:

		private:
	};
};