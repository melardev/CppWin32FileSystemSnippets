#pragma once

#include <iostream>
#include <memory>
#include <Windows.h>
#include <vector>
#include <string>

// For the Sake of simplicity I used Cpp Strings
// You may want to implement this with C Code and also using unicode
namespace EnumerateLocalDrivesCpp
{
	std::vector<std::string> GetLocicalDrivesA()
	{
		const auto size = ::GetLogicalDriveStringsA(0, nullptr);
		auto buffer = std::make_unique<char[]>(size);

		::GetLogicalDriveStringsA(size, buffer.get());
		std::vector<std::string> drives = std::vector<std::string>();
		std::string current;
		for (auto i = 0; i < size; ++i)
		{
			if (buffer[i])
			{
				current += buffer[i];
			}
			else
			{
				if (!current.empty())
				{
					drives.push_back(current);
					current.clear();
				}
			}
		}

		return drives;
	}


	std::string GetStrDriveType(std::string const& drive)
	{
		const UINT driverType = GetDriveTypeA(drive.c_str());
		std::string message;

		if (DRIVE_REMOVABLE == driverType)
			message = "Removable drive";
		else if (DRIVE_CDROM == driverType)
			message = "CD drive";
		else if (DRIVE_FIXED == driverType)
			message = "Fixed drive";
		else if (DRIVE_RAMDISK == driverType)
			message = "RAM";
		else if (DRIVE_REMOTE == driverType)
			message = "Remote Drive";
		else if (DRIVE_UNKNOWN == driverType)
			message = "Unknown";
		else if (DRIVE_NO_ROOT_DIR == driverType)
			message = "Drive no root directory";

		return message;
	}


	int main()
	{
		auto drives = GetLocicalDrivesA();
		for (auto drive : drives)
		{
			std::cout << drive << " " << GetStrDriveType(drive) << std::endl;
		}
		return 0;
	}
}
