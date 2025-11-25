cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(CMAKE_ERROR_DEPRECATED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SHARED_LIBRARY_ENABLE_EXPORTS ON)
set(CMAKE_AUTORCC ON)
if(APPLE)
    set(CMAKE_BUILD_RPATH "@loader_path")
elseif(UNIX)
    set(CMAKE_BUILD_RPATH "$ORIGIN")
endif()
set(CMAKE_BUILD_RPATH_USE_ORIGIN ON)
set(CMAKE_INCLUDE_CURRENT_DIR OFF)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE OFF)
set(CMAKE_OPTIMIZE_DEPENDENCIES ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(DIRECTORY . PROPERTY GLOBAL_DEPENDS_NO_CYCLES ON)
set_property(DIRECTORY . PROPERTY REPORT_UNDEFINED_PROPERTIES ON)
set_property(DIRECTORY . PROPERTY TARGET_SUPPORTS_SHARED_LIBS ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("building in DEBUG mode, this should NOT be released")
endif()

project(ColoursPlusPlus
    VERSION 2.0.0
    LANGUAGES CXX
)

add_executable(ColoursPlusPlus_app WIN32)
target_include_directories(ColoursPlusPlus_app
    PRIVATE "include"
)
target_sources(ColoursPlusPlus_app
    PRIVATE "src/main.cpp"
    PRIVATE "src/SGCLPIntroductionPage.cpp"
)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2 GuiPrivate)
find_package(SGEXTN REQUIRED COMPONENTS SG_Containers SG_Math SG_Core SG_FileSystem SG_Widgets SG_RI EntryPoint_SG)
target_link_libraries(ColoursPlusPlus_app
    PRIVATE SGEXTN::SG_Containers
    PRIVATE SGEXTN::SG_Math
    PRIVATE SGEXTN::SG_Core
    PRIVATE SGEXTN::SG_FileSystem
    PRIVATE SGEXTN::SG_Widgets
    PRIVATE SGEXTN::SG_RI
    PRIVATE SGEXTN::EntryPoint_SG
)
