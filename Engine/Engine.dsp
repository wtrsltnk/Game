# Microsoft Developer Studio Project File - Name="Engine" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Engine - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Engine.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Engine.mak" CFG="Engine - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Engine - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Engine - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Engine - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ENGINE_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ENGINE_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "Engine - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ENGINE_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../../_shared" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ENGINE_EXPORTS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib glaux.lib winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"../Applicatie/Engine.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Engine - Win32 Release"
# Name "Engine - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Keys.cpp
# End Source File
# Begin Source File

SOURCE=.\wiskunde.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrBaseBsp.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrBox.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrConsole.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrEntry.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrHLBsp.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrLight.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrMaterial.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrObject.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrQBsp.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrTextureManager.cpp
# End Source File
# Begin Source File

SOURCE=.\WtrWorld.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BitSet.h
# End Source File
# Begin Source File

SOURCE=.\BspTypes.h
# End Source File
# Begin Source File

SOURCE=".\Copy of bspfile.h"
# End Source File
# Begin Source File

SOURCE=.\HLBspFile.h
# End Source File
# Begin Source File

SOURCE=.\Keys.h
# End Source File
# Begin Source File

SOURCE=.\QBspFile.h
# End Source File
# Begin Source File

SOURCE=.\wiskunde.h
# End Source File
# Begin Source File

SOURCE=.\WtrBaseBsp.h
# End Source File
# Begin Source File

SOURCE=.\WtrBox.h
# End Source File
# Begin Source File

SOURCE=.\WtrCamera.h
# End Source File
# Begin Source File

SOURCE=.\WtrConsole.h
# End Source File
# Begin Source File

SOURCE=.\WtrEngine.h
# End Source File
# Begin Source File

SOURCE=.\WtrEntry.h
# End Source File
# Begin Source File

SOURCE=.\WtrFrame.h
# End Source File
# Begin Source File

SOURCE=.\WtrHLBsp.h
# End Source File
# Begin Source File

SOURCE=.\WtrLight.h
# End Source File
# Begin Source File

SOURCE=.\WtrMaterial.h
# End Source File
# Begin Source File

SOURCE=.\WtrObject.h
# End Source File
# Begin Source File

SOURCE=.\WtrQBsp.h
# End Source File
# Begin Source File

SOURCE=.\WtrTextureManager.h
# End Source File
# Begin Source File

SOURCE=.\WtrWorld.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
