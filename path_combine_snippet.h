#pragma once
#include <windows.h>
#include "Shlwapi.h"
#include <tchar.h>

namespace PathCombineSnippet
{
	void main(void)
	{
		TCHAR paths[][MAX_PATH] = {
			_T("Users\\MelarDev\\Images\\selfie.png"),
			_T(".\\Windows\\System32\\..\\"),
			_T(".\\Windows\\System32\\..\\"),
		};

		TCHAR destination[MAX_PATH];
		TCHAR first_segment[] = _T("C:");


		for (int i = 0; i < 3; i++)
		{
			const LPTSTR combined = PathCombine(destination, first_segment, paths[i]);
			if (combined != NULL)
			{
				_tprintf(_T("First part: \"%s\"; Second part: \"%s\"\nCombined:\t\t%s\n\n"),
				         first_segment, paths[i],
				         combined);
			}
			else
			{
				_tprintf(_T("An error occurred with %s"), paths[i]);
			}
		}
	}
}
