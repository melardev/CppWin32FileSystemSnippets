#pragma once
#include <Windows.h>
#include <tchar.h>

namespace CopyFileDemo
{
	int main()
	{
		TCHAR srcPath[] = _T("C:\\Windows\\system32\\calc.exe");
		TCHAR destinationPath[] = _T(".\\calc");

		BOOL success = CopyFile(srcPath, destinationPath, FALSE);
		if (success)
			_tprintf(_T("File copied successfully\n"));

		return 0;
	}
}
