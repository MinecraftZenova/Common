#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <locale>
#include <codecvt>
#include <filesystem>

#include "Utils.h"

/* Converts a C string to a wchar_t* */
namespace Util {
	wchar_t* CStrToCWstr(const char* charptr) {
		size_t size = strlen(charptr) + 1;
		size_t output;
		wchar_t* wa = new wchar_t[size];
		mbstowcs_s(&output, wa, size, charptr, size);
		return wa;
	}

	/* Converts a wstring to a C++ string */
	std::string WstrToStr(const std::wstring& oldstr) {
		return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(oldstr);
	}

	/* Converts a standard string to a wide string */
	std::wstring StrToWstr(const std::string& oldstr) {
		return std::wstring(oldstr.begin(), oldstr.end());
	}

	bool IsDirectory(const std::string& folder) {
		return std::filesystem::is_directory(std::filesystem::status(folder));
	}

	std::wstring GetAppDirectoryW() {
		return std::filesystem::current_path().wstring();
	}

	std::string GetAppDirectoryA() {
		return std::filesystem::current_path().string();
	}
}