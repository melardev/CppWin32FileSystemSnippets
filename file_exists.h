#pragma once
#include <Windows.h>
#include <tchar.h>

namespace FileExists
{
	bool file_exists(TCHAR* file_path)
	{
		const DWORD result = ::GetFileAttributes(file_path);
		return result != INVALID_FILE_ATTRIBUTES;
	}

	int main()
	{
		TCHAR file_path[] = TEXT("C:\\Windows\\System32\\calc.exe");
		bool exists = file_exists(file_path);

		if (exists)
			_tprintf(_T("%s Exists!"), file_path);
		else
			_tprintf(_T("%s Does not exist!"), file_path);

		_tprintf(_T("\n\n"));

		TCHAR nonexistent_file[] = TEXT("C:\\Windows\\System32\\nononono.exe");
		exists = file_exists(nonexistent_file);

		if (exists)
			_tprintf(_T("%s Exists!"), nonexistent_file);
		else
			_tprintf(_T("%s Does not exist!"), nonexistent_file);


		return 0;
	}
}
