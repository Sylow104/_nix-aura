#pragma once
#include <string>

class CliUtil
{
	public:

	/* TODO: Windows only platform? port to unix when possible */

	static void WriteHeader(string title, int consoleColor);
	static void LoadingTitle();
	static void RunningTitle();
	static void Exit(int exitCode, bool wait = true);
	static bool CheckAdmin();

	protected:

	private:
};