#pragma once
#include <Windows.h>
#include <tchar.h>

namespace GetFileSystemName
{

	void main()
	{
		TCHAR volume[] = _T("C:\\");
		TCHAR file_system_name[MAX_PATH + 1];
		if (GetVolumeInformation(volume,
		                         NULL,
		                         NULL,
		                         NULL,NULL,
		                         NULL,
		                         file_system_name,
		                         sizeof(file_system_name)) == TRUE)
		{
			_tprintf(_T("FileSystem Name: %s\n"), file_system_name);
		}
		else
		{
			_tprintf(_T("Error retrieving volume information"));
		}
	}
}
