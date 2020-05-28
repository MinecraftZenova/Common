#ifndef __UTILS_H_
#define __UTILS_H_

#include <iomanip> //std::setfill, std::setw
#include <sstream> //std::stringstream, std::hex
#include <type_traits> //std::enable_if_t, std::is_integral_v

namespace Util {
	/* Converts a C string to a wchar_t* */
	wchar_t* CStrToCWstr(const char* charptr);
	/* Converts a wstring to a C++ string */
	std::string WstrToStr(const std::wstring&);
	/* Converts a standard string to a wide string */
	std::wstring StrToWstr(const std::string&);

	/* FolderUtils */
	bool IsDirectory(const std::string& folder);
	std::wstring GetAppDirectoryW();
	std::string GetAppDirectoryA();

	template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
	std::string HexString(T num) {
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << num;
		return stream.str();
	}
};

#endif // __UTILS_H_
