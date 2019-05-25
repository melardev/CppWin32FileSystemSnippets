#pragma once
#include "file_exists.h"
#include "copy_file.h"
#include "create_temp_file.h"
#include "create_temp_file_prefix.h"
#include "enumerate_local_drives.h"
#include "dir_exists_demo.h"
#include "print_driver_type.h"
#include "change_file_attrs.h"
#include "path_canonicalize_usage.h"
#include "path_combine_snippet.h"
#include "get_full_path_name_snippet.h"
#include "get_file_size_snippet.h"
#include "get_filesystem_type.h"
#include "get_user_profile_dir.h"
#include "not_ready/iterate_dir_official.h"
#include "iterate_directories.h"


namespace FileSystemSnippetsLauncher
{
	int main()
	{
		// GetCurrentWorkingDirectory::main();
		// GetUserProfileDirectorySnippet::main();
		// PrintDriveType::main();
		// DirectoryExists::main();
		// GetFileSizeDemo::main();
		// GetFileSystemName::main();

		// EnumerateLocalDrivesCpp::main();
		// EnumerateDriversPath::main(); // This snippet was moved to CppWin32SystemSnippets

		// FileExists::main();
		// CopyFileDemo::main();
		// IterateDirectorySnippet::main();

		// CreateTempFile::main();
		// CreateTempFileWithPrefix::main();

		// PathCanonicalizeSnippet::main();
		// PathCombineSnippet::main();
		// GetFullPathNameSnippet::main();

		// ChangeFileAttributesDemo::main();

		return 0;
	}
}
