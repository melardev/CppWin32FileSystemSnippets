#pragma once
#include <Windows.h>
#include <iostream>
#include <UserEnv.h>
#include <tchar.h>

#pragma comment(lib, "userenv.lib")

namespace GetUserProfileDirectorySnippet
{
	void main()
	{
		HANDLE h_token;
		TCHAR home_dir[MAX_PATH + 1];
		DWORD homeDirLen = MAX_PATH + 1;

		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_READ, &h_token))
			std::cout << "Failed to open process token" << std::endl;;

		// Obviously the recommended version is the unicode (GetUserProfileDirectoryW), do not use GetUserProfileDirectoryA
		if (!GetUserProfileDirectory(h_token, home_dir, &homeDirLen))
		{
			CloseHandle(h_token);
			_tprintf(_T("Failed to get home directory\n"));
		}
		else
			_tprintf(_T("User directory %s"), home_dir);

		CloseHandle(h_token);
	}
}
