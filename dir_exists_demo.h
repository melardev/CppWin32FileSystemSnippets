#pragma once
#include <Windows.h>

namespace DirectoryExists
{
	bool dir_exists(const PTCHAR dir_to_check)
	{
		const DWORD attributes = GetFileAttributes(dir_to_check);
		return ((attributes != 0xFFFFFFFF) && ((attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY));
	}

	int main()
	{
		TCHAR windows_path[] = _T("C:\\Windows");
		TCHAR nonexistent_path[] = _T("C:\\inexistent");

		_tprintf(_T("%s exists? %s\n"), windows_path, dir_exists(windows_path) ? _T("Yes") : _T("No"));
		_tprintf(_T("%s exists? %s\n"), nonexistent_path, dir_exists(nonexistent_path) ? _T("Yes") : _T("No"));

		return 0;
	}
}
