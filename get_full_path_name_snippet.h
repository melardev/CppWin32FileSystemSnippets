#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

namespace GetFullPathNameSnippet
{
	void main()
	{
		// You really should know that GetFullPathName does noes not
		// check if the file exists or not it just returns a full path
		// based on the current drive(if a relative path is provided)
		// or if the input was already full path then it returns the path normalized
		TCHAR paths[][MAX_PATH] = {
			_T(".\\file.txt"),
			_T("..\\image.png"),
			_T("C:\\Windows\\System32\\calc.exe"),
			_T("C:\\Users\\MelarDev\\..\\lahra\\Images\\selfie.png"),
			_T("/Debug/symbols.pdb"),
			_T("C:\\Windows")
		};

		TCHAR buffer[BUFFER_SIZE] = TEXT("");
		TCHAR** lppPart = {};

		for (int i = 0; i < 6; i++)
		{
			TCHAR* path = paths[i];
			const DWORD result = GetFullPathName(path, BUFFER_SIZE, buffer, lppPart);
			if (result > 0)
			{
				_tprintf(_T("Input: %s;\nOutput: %s"), path, buffer);
				if (lppPart != NULL)
					_tprintf(_T("\nFileName: %s"), *lppPart);
				_tprintf(_T("\n\n"));
			}
			else
				_tprintf(_T("Something went wrong with input: %s"), path);
		}
	}
}
