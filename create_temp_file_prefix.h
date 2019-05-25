#pragma once
#include <Windows.h>
#include <tchar.h>

namespace CreateTempFileWithPrefix
{
#define APP_TEMP_PREFIX _T("APP")

	bool CreateTempFile(const PTCHAR prefix, PTCHAR tempFilePath)
	{
		// MAX_PATH is number of characters, make sure the Win API knows the correct buffer size
		TCHAR tempPath[MAX_PATH + 1];
		const DWORD tempPathLength = GetTempPath(MAX_PATH - _tcslen(APP_TEMP_PREFIX), tempPath);

		if (tempPathLength > 0 && tempPathLength <= MAX_PATH - _tcslen(APP_TEMP_PREFIX))
		{
			if (GetTempFileName(tempPath, prefix == NULL ? APP_TEMP_PREFIX : prefix, 0, tempFilePath) > 0)
				return true;
		}

		return false;
	}


	int main()
	{
		TCHAR tempFilePath[MAX_PATH + 1];
		// Notice the prefix exceeds 3 characters, only the first 3 characters will be taken into account
		TCHAR prefix[] = _T("WinFsSnippets_");
		CreateTempFile(prefix, tempFilePath);

		_tprintf(_T("File created in %s\n\n"), tempFilePath);
		return 0;
	}
}
