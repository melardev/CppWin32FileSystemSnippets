#pragma once
#include <Windows.h>
#include <tchar.h>

namespace ChangeFileAttributesDemo
{
	int main()
	{
		TCHAR path[] = _T("D:\\temp\\path.txt");
		SetFileAttributes(path, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
		_tprintf(_T("Go ahead and check the %s it should be hidden now\n"), path);
		return EXIT_SUCCESS;
	}
}
