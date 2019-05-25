#pragma once
#include <windows.h>
#include "Shlwapi.h"
#include <tchar.h>

#pragma comment(lib, "Shlwapi.lib")

namespace PathCanonicalizeSnippet
{
	int main(void)
	{
		// For your app you would have a TCHAR your_path[MAX_PATH] = _T("C:/My/Some/../Path")
		TCHAR paths[][MAX_PATH] = {
			_T("C:\\Windows\\.\\System32"),
			_T("C:\\Users/Melardev\\..\\..\\Users\\lahra/Documents"),
			_T("D:\\Temp\\..\\Images\\"),

			_T("C://Users/Melardev/../lahra/Documents"),
			_T("D:/.\\./Temp/../Images/././\\"),

		};

		// Path_1 destination buffer.
		TCHAR destination_buffer[MAX_PATH];

		const int elements_count = 5;
		for (int i = 0; i < elements_count; i++)
		{
			if (PathCanonicalize(destination_buffer, paths[i]))
				_tprintf(_T("Original path: %s\nCanonicalized path: %s\n\n"), paths[i], destination_buffer);
			else
				_tprintf(_T("An error occured, You can get more details with GetLastError()"));
		}

		return 0;
	}
}
