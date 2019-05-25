#pragma once
#include <Windows.h>
#include <tchar.h>

namespace PrintDriveType
{
	static void print_drive_status(LPCTSTR drive)
	{
		const UINT driverType = GetDriveType(drive);

		if (DRIVE_UNKNOWN == driverType)
			_tprintf(_T("Unknown print Driver Type"));
		else if (DRIVE_NO_ROOT_DIR == driverType)
			_tprintf(_T("Invalid, is there a volume mounted ?"));
		else if (DRIVE_REMOVABLE == driverType)
			_tprintf(_T("Removable drive"));
		else if (DRIVE_FIXED == driverType)
			_tprintf(_T("Fixed drive"));
		else if (DRIVE_REMOTE == driverType)
			_tprintf(_T("Remote Network Drive"));
		else if (DRIVE_CDROM == driverType)
			_tprintf(_T("CD ROM drive"));
		else if (DRIVE_RAMDISK == driverType)
			_tprintf(_T("RAM"));;
	}

	static int main()
	{
		const LPCTSTR drive = _T("E:\\");
		print_drive_status(drive); // For me it is a removable drive, "E" will not work. E: or E:\\ will work
		return 0;
	}
}
