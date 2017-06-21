cmake_minimum_required(VERSION 3.1)

project(Game)

find_package(OpenGL REQUIRED)

add_subdirectory(Engine)

add_executable(Game WIN32
    README.md
    Applicatie/Applicatie.rc
    Applicatie/CApplicatie.cpp
    Applicatie/CApplicatie.h
    Applicatie/CWin.cpp
    Applicatie/CWin.h
    Applicatie/resource.h
    Applicatie/snowflake.ico
    Applicatie/WinMain.cpp
	)

target_include_directories(Game
    PRIVATE Engine
    )

target_link_libraries(Game
    ${OPENGL_LIBRARIES}
    Engine
    )

target_compile_features(Game
	PRIVATE cxx_auto_type
	PRIVATE cxx_nullptr
	PRIVATE cxx_range_for
	)
