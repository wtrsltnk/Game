cmake_minimum_required(VERSION 3.1)

project(Engine)

add_library(Engine
    BitSet.h
    BspTypes.h
    HLBspFile.h
    Keys.cpp
    Keys.h
    QBspFile.h
    stb.cpp
    stb_image.h
    wiskunde.cpp
    wiskunde.h
    WtrBaseBsp.cpp
    WtrBaseBsp.h
    WtrBox.cpp
    WtrBox.h
    WtrCamera.cpp
    WtrCamera.h
    WtrConsole.cpp
    WtrConsole.h
    WtrEngine.cpp
    WtrEngine.h
    WtrEntry.cpp
    WtrEntry.h
    WtrFrame.cpp
    WtrFrame.h
    WtrHLBsp.cpp
    WtrHLBsp.h
    WtrLight.cpp
    WtrLight.h
    WtrMaterial.cpp
    WtrMaterial.h
    WtrObject.cpp
    WtrObject.h
    WtrQBsp.cpp
    WtrQBsp.h
    WtrTextureManager.cpp
    WtrTextureManager.h
    WtrWorld.cpp
    WtrWorld.h
    )

target_compile_features(Engine
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_link_libraries(Engine
    ${OPENGL_LIBRARIES}
    winmm
    )
