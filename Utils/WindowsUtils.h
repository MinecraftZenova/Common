#pragma once

#include <shtypes.h>
#include <string>

namespace Util {
	/* Get the path to the Minecraft local AppData path */
	std::wstring GetMinecraftAppDataPath();

	std::wstring GetCommonFolder(KNOWNFOLDERID folderId);
}