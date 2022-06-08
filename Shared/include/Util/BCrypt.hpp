#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class BCrypt
{
	public:
	BCrypt();
	~BCrypt();
	
	/* TODO: finish these implementations */

	string HashPassword(string password, string salt);
	string GenerateSalt(int logRounds);
	string GenerateSalt();
	bool CheckPassword();

	protected:

	private:
	vector<uint32_t> p, s;
	
	vector<char> EncodeBase64(vector<char> d, int length);
	vector<char> DecodeBase64(string d, int maximumLength);
	void Encipher(vector<uint32_t> block, int offset);
	uint32_t StreamToWord(vector<char> data, int *offset);
	void InitKey();
	void Key(vector<char> key);
	void EksKey(vector<char> data, vector<char> key);
	vector<char> CryptRaw(vector<char> password, vector<char> salt,
		int logRounds);
	
};