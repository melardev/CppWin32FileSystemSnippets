#pragma once
#include <Windows.h>

namespace CreateTempFile
{
	bool CreateTempFile(PTCHAR tempFilePath)
	{
		// Will receive the temporary directory path
		TCHAR tempPath[MAX_PATH + 1];
		// MAX_PATH is number of characters, make sure the Win API knows the correct buffer size
		const DWORD tempPathLength = GetTempPath(MAX_PATH, tempPath);

		if (tempPathLength > 0 && tempPathLength <= MAX_PATH)
		{
			if (GetTempFileName(tempPath, NULL, 0, tempFilePath) > 0)
				return true;
		}

		return false;
	}


	int main()
	{
		// Will receive the temporary file path
		TCHAR tempFilePath[MAX_PATH + 1];
		CreateTempFile(tempFilePath);

		_tprintf(_T("File created in %s\n\n"), tempFilePath);
		return 0;
	}
}
