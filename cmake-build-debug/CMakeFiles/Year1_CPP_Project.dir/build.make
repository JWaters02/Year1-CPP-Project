# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\Github Projects\University\Year1-CPP-Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Year1_CPP_Project.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Year1_CPP_Project.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Year1_CPP_Project.dir\flags.make

CMakeFiles\Year1_CPP_Project.dir\main.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\main.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\main.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\main.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\main.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\main.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.obj: ..\Commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/Commands.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\Commands.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\Commands.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/Commands.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\Commands.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/Commands.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\Commands.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\Commands.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.obj: ..\Stock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/Stock.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\Stock.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\Stock.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/Stock.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\Stock.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/Stock.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\Stock.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\Stock.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.obj: ..\FileHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/FileHandler.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\FileHandler.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/FileHandler.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\FileHandler.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/FileHandler.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\FileHandler.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Order.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\Order.cpp.obj: ..\Order.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/Order.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\Order.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\Order.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/Order.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\Order.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\Order.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/Order.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\Order.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\Order.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.obj: ..\Logs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/Logs.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\Logs.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\Logs.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/Logs.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\Logs.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/Logs.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\Logs.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\Logs.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.obj: ..\Shopper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/Shopper.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\Shopper.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/Shopper.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\Shopper.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/Shopper.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\Shopper.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Item.cpp.obj: CMakeFiles\Year1_CPP_Project.dir\flags.make
CMakeFiles\Year1_CPP_Project.dir\Item.cpp.obj: ..\Item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Year1_CPP_Project.dir/Item.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Year1_CPP_Project.dir\Item.cpp.obj /FdCMakeFiles\Year1_CPP_Project.dir\ /FS -c "F:\Github Projects\University\Year1-CPP-Project\Item.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Year1_CPP_Project.dir/Item.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Year1_CPP_Project.dir\Item.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Github Projects\University\Year1-CPP-Project\Item.cpp"
<<

CMakeFiles\Year1_CPP_Project.dir\Item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Year1_CPP_Project.dir/Item.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Year1_CPP_Project.dir\Item.cpp.s /c "F:\Github Projects\University\Year1-CPP-Project\Item.cpp"
<<

# Object files for target Year1_CPP_Project
Year1_CPP_Project_OBJECTS = \
"CMakeFiles\Year1_CPP_Project.dir\main.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\Order.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.obj" \
"CMakeFiles\Year1_CPP_Project.dir\Item.cpp.obj"

# External object files for target Year1_CPP_Project
Year1_CPP_Project_EXTERNAL_OBJECTS =

Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\main.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\Commands.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\Stock.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\FileHandler.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\Order.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\Logs.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\Shopper.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\Item.cpp.obj
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\build.make
Year1_CPP_Project.exe: CMakeFiles\Year1_CPP_Project.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Year1_CPP_Project.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Year1_CPP_Project.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.18362.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.18362.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Year1_CPP_Project.dir\objects1.rsp @<<
 /out:Year1_CPP_Project.exe /implib:Year1_CPP_Project.lib /pdb:"F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\Year1_CPP_Project.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Year1_CPP_Project.dir\build: Year1_CPP_Project.exe

.PHONY : CMakeFiles\Year1_CPP_Project.dir\build

CMakeFiles\Year1_CPP_Project.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Year1_CPP_Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Year1_CPP_Project.dir\clean

CMakeFiles\Year1_CPP_Project.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "F:\Github Projects\University\Year1-CPP-Project" "F:\Github Projects\University\Year1-CPP-Project" "F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug" "F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug" "F:\Github Projects\University\Year1-CPP-Project\cmake-build-debug\CMakeFiles\Year1_CPP_Project.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Year1_CPP_Project.dir\depend

