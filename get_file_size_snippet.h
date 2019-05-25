#pragma once
#include <Windows.h>
#include <tchar.h>

namespace GetFileSizeDemo
{
	int main()
	{
		TCHAR path[] = _T("C:\\Windows\\System32\\calc.exe");
		const bool is_dir = false;
		const HANDLE h_file = CreateFile(path, GENERIC_READ,
		                                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
		                                NULL, OPEN_EXISTING, is_dir ? FILE_FLAG_BACKUP_SEMANTICS : 0, NULL);
		if (h_file != INVALID_HANDLE_VALUE)
		{
			LARGE_INTEGER size;
			if (GetFileSizeEx(h_file, &size) != 0)
			{
				// If you want in KB then size.QuadPart/1024; for megabytes then /(1024*1024)
				_tprintf(_T("File size (in bytes) for %s: %llu"), path, size.QuadPart);
				CloseHandle(h_file);
				return -1;
			}
			else
			{
				_tprintf(_T("Failed to retrieve the file size for %s"), path);
			}
		}
		else
		{
			_tprintf(_T("Failed to open the file at %s"), path);
		}
	}
}
