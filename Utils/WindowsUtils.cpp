#include <Windows.h>
#include <ShlObj.h>

#include "WindowsUtils.h"

namespace Util {
    /* Get the path to the Minecraft local AppData path */
	std::wstring GetMinecraftAppDataPath() {
		wchar_t szPath[MAX_PATH];
		if(SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath))) {
			std::wstring appData(szPath);
			appData += L"\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\LocalState\\games\\com.mojang\\";

			//std::cout << "Found Minecraft AppData folder at: " << WSTRING_TO_STRING(appData).c_str() << "\n";

			return appData;
		}
		return L"";
	}

	std::wstring GetCommonFolder(KNOWNFOLDERID folderId) {
		LPWSTR wszPath = NULL;

		if(SUCCEEDED(SHGetKnownFolderPath(folderId, KF_FLAG_DEFAULT_PATH, NULL, &wszPath))) {
			return wszPath;
		}
		return L"";
	}
}