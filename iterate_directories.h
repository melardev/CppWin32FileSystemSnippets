#pragma once
#include <Windows.h>
#include <tchar.h>

namespace IterateDirectorySnippet
{
	void main()
	{
		WIN32_FIND_DATA FindFileData;
		// D:\\temp\\*.txt will give you txt files in that dir
		TCHAR path[] = _T("D:\\workspace\\*");

		const HANDLE h_find = FindFirstFile(path, &FindFileData);
		if (h_find == INVALID_HANDLE_VALUE)
		{
			_tprintf(_T("FindFirstFile error. Error code: (%d)\n"), GetLastError());
			return;
		}

		do
		{
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				_tprintf(TEXT("\t%s\t\t\t<Dir>\n"), FindFileData.cFileName);
			else
				_tprintf(TEXT("\t%s\n"), FindFileData.cFileName);
		}
		while (FindNextFile(h_find, &FindFileData) != 0);

		FindClose(h_find);
	}
}
