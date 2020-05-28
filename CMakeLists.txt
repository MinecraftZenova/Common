ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set(SOURCE_LIST
    "Utils/Utils.h"
    "Utils/Utils.cpp"
)

if(WIN32)
    list(APPEND SOURCE_LIST
        "Utils/WindowsUtils.h"
        "Utils/WindowsUtils.cpp"
    )
endif()

add_library(Common STATIC
    ${SOURCE_LIST}
)

target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})