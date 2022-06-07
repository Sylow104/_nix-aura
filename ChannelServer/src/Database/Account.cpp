#include "Database/Account.hpp"
#include <stdexcept>

using namespace db;

Autoban::Autoban()
{
	;
}

Autoban::~Autoban()
{
	;
}

int Autoban::get_Score()
{
	return _Score;
}

bool Autoban::set_Score(int n_Score)
{
	if (n_Score < 0) {
		_Score = 0;
	} else {
		_Score = n_Score;
	}
	return true;
}

int Autoban::get_Count()
{
	return _Count;
}

bool Autoban::set_Count(int n_Count)
{
	if (n_Count < 0) {
		_Count = 0;
	} else {
		_Count = n_Count;
	}
	return true;
}

///////

Account::Account()
{
	Vars = new ScriptVariables;
	Bank = new BankInventory;
	
	LastLogin = time(0x0);
};

Account::~Account()
{
	;
};

PlayerCreature *Account::get_CharacterOrPet(long entityID)
{
	try {
		return (PlayerCreature *) Characters[entityID];
		
	} catch (std::out_of_range err) {
		;
	}
	return (PlayerCreature *) Pets[entityID];
}

PlayerCreature *Account::get_CharacterOrPetSafe(long entityID)
{
	try {
		return get_CharacterOrPet(entityID);
	} catch (std::out_of_range err) {
		/* 
		throw new SevereViolation("Account doesn't contain character 0x{0:X}", entityId);
		*/
		return NULL;
	}
}


Pet *Account::get_Pet(long entityID)
{
	return Pets[entityID];
}

Pet *Account::get_PetSafe(long entityID)
{
	try {
		return get_Pet(entityID);
	} catch (std::out_of_range err) {
		/*
	throw new SevereViolation("Account doesn't contain pet 0x{0:X}", entityId);
	*/
		throw 3;
	}
	return NULL;
}