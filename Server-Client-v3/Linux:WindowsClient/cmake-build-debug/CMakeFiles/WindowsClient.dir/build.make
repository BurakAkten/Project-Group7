# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WindowsClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WindowsClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WindowsClient.dir/flags.make

CMakeFiles/WindowsClient.dir/main.cpp.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WindowsClient.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WindowsClient.dir/main.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/main.cpp

CMakeFiles/WindowsClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WindowsClient.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/main.cpp > CMakeFiles/WindowsClient.dir/main.cpp.i

CMakeFiles/WindowsClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WindowsClient.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/main.cpp -o CMakeFiles/WindowsClient.dir/main.cpp.s

CMakeFiles/WindowsClient.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/main.cpp.o.requires

CMakeFiles/WindowsClient.dir/main.cpp.o.provides: CMakeFiles/WindowsClient.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/main.cpp.o.provides

CMakeFiles/WindowsClient.dir/main.cpp.o.provides.build: CMakeFiles/WindowsClient.dir/main.cpp.o


CMakeFiles/WindowsClient.dir/Client.cpp.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WindowsClient.dir/Client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WindowsClient.dir/Client.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/Client.cpp

CMakeFiles/WindowsClient.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WindowsClient.dir/Client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/Client.cpp > CMakeFiles/WindowsClient.dir/Client.cpp.i

CMakeFiles/WindowsClient.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WindowsClient.dir/Client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/Client.cpp -o CMakeFiles/WindowsClient.dir/Client.cpp.s

CMakeFiles/WindowsClient.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/Client.cpp.o.requires

CMakeFiles/WindowsClient.dir/Client.cpp.o.provides: CMakeFiles/WindowsClient.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/Client.cpp.o.provides

CMakeFiles/WindowsClient.dir/Client.cpp.o.provides.build: CMakeFiles/WindowsClient.dir/Client.cpp.o


CMakeFiles/WindowsClient.dir/MatConverter.cpp.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/MatConverter.cpp.o: ../MatConverter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WindowsClient.dir/MatConverter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WindowsClient.dir/MatConverter.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/MatConverter.cpp

CMakeFiles/WindowsClient.dir/MatConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WindowsClient.dir/MatConverter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/MatConverter.cpp > CMakeFiles/WindowsClient.dir/MatConverter.cpp.i

CMakeFiles/WindowsClient.dir/MatConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WindowsClient.dir/MatConverter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/MatConverter.cpp -o CMakeFiles/WindowsClient.dir/MatConverter.cpp.s

CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.requires

CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.provides: CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.provides

CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.provides.build: CMakeFiles/WindowsClient.dir/MatConverter.cpp.o


CMakeFiles/WindowsClient.dir/Networkable.cpp.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/Networkable.cpp.o: ../Networkable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WindowsClient.dir/Networkable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WindowsClient.dir/Networkable.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/Networkable.cpp

CMakeFiles/WindowsClient.dir/Networkable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WindowsClient.dir/Networkable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/Networkable.cpp > CMakeFiles/WindowsClient.dir/Networkable.cpp.i

CMakeFiles/WindowsClient.dir/Networkable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WindowsClient.dir/Networkable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/Networkable.cpp -o CMakeFiles/WindowsClient.dir/Networkable.cpp.s

CMakeFiles/WindowsClient.dir/Networkable.cpp.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/Networkable.cpp.o.requires

CMakeFiles/WindowsClient.dir/Networkable.cpp.o.provides: CMakeFiles/WindowsClient.dir/Networkable.cpp.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/Networkable.cpp.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/Networkable.cpp.o.provides

CMakeFiles/WindowsClient.dir/Networkable.cpp.o.provides.build: CMakeFiles/WindowsClient.dir/Networkable.cpp.o


CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o: ../supporting/wrestart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/wrestart.cpp

CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/wrestart.cpp > CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.i

CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/wrestart.cpp -o CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.s

CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.requires

CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.provides: CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.provides

CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.provides.build: CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o


CMakeFiles/WindowsClient.dir/supporting/restart.c.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/supporting/restart.c.o: ../supporting/restart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/WindowsClient.dir/supporting/restart.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/WindowsClient.dir/supporting/restart.c.o   -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/restart.c

CMakeFiles/WindowsClient.dir/supporting/restart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/WindowsClient.dir/supporting/restart.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/restart.c > CMakeFiles/WindowsClient.dir/supporting/restart.c.i

CMakeFiles/WindowsClient.dir/supporting/restart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/WindowsClient.dir/supporting/restart.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/restart.c -o CMakeFiles/WindowsClient.dir/supporting/restart.c.s

CMakeFiles/WindowsClient.dir/supporting/restart.c.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/supporting/restart.c.o.requires

CMakeFiles/WindowsClient.dir/supporting/restart.c.o.provides: CMakeFiles/WindowsClient.dir/supporting/restart.c.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/supporting/restart.c.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/supporting/restart.c.o.provides

CMakeFiles/WindowsClient.dir/supporting/restart.c.o.provides.build: CMakeFiles/WindowsClient.dir/supporting/restart.c.o


CMakeFiles/WindowsClient.dir/supporting/uici.c.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/supporting/uici.c.o: ../supporting/uici.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/WindowsClient.dir/supporting/uici.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/WindowsClient.dir/supporting/uici.c.o   -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/uici.c

CMakeFiles/WindowsClient.dir/supporting/uici.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/WindowsClient.dir/supporting/uici.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/uici.c > CMakeFiles/WindowsClient.dir/supporting/uici.c.i

CMakeFiles/WindowsClient.dir/supporting/uici.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/WindowsClient.dir/supporting/uici.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/uici.c -o CMakeFiles/WindowsClient.dir/supporting/uici.c.s

CMakeFiles/WindowsClient.dir/supporting/uici.c.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/supporting/uici.c.o.requires

CMakeFiles/WindowsClient.dir/supporting/uici.c.o.provides: CMakeFiles/WindowsClient.dir/supporting/uici.c.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/supporting/uici.c.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/supporting/uici.c.o.provides

CMakeFiles/WindowsClient.dir/supporting/uici.c.o.provides.build: CMakeFiles/WindowsClient.dir/supporting/uici.c.o


CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o: CMakeFiles/WindowsClient.dir/flags.make
CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o: ../supporting/uiciname.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o   -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/uiciname.c

CMakeFiles/WindowsClient.dir/supporting/uiciname.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/WindowsClient.dir/supporting/uiciname.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/uiciname.c > CMakeFiles/WindowsClient.dir/supporting/uiciname.c.i

CMakeFiles/WindowsClient.dir/supporting/uiciname.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/WindowsClient.dir/supporting/uiciname.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/supporting/uiciname.c -o CMakeFiles/WindowsClient.dir/supporting/uiciname.c.s

CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.requires:

.PHONY : CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.requires

CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.provides: CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.requires
	$(MAKE) -f CMakeFiles/WindowsClient.dir/build.make CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.provides.build
.PHONY : CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.provides

CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.provides.build: CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o


# Object files for target WindowsClient
WindowsClient_OBJECTS = \
"CMakeFiles/WindowsClient.dir/main.cpp.o" \
"CMakeFiles/WindowsClient.dir/Client.cpp.o" \
"CMakeFiles/WindowsClient.dir/MatConverter.cpp.o" \
"CMakeFiles/WindowsClient.dir/Networkable.cpp.o" \
"CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o" \
"CMakeFiles/WindowsClient.dir/supporting/restart.c.o" \
"CMakeFiles/WindowsClient.dir/supporting/uici.c.o" \
"CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o"

# External object files for target WindowsClient
WindowsClient_EXTERNAL_OBJECTS =

WindowsClient: CMakeFiles/WindowsClient.dir/main.cpp.o
WindowsClient: CMakeFiles/WindowsClient.dir/Client.cpp.o
WindowsClient: CMakeFiles/WindowsClient.dir/MatConverter.cpp.o
WindowsClient: CMakeFiles/WindowsClient.dir/Networkable.cpp.o
WindowsClient: CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o
WindowsClient: CMakeFiles/WindowsClient.dir/supporting/restart.c.o
WindowsClient: CMakeFiles/WindowsClient.dir/supporting/uici.c.o
WindowsClient: CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o
WindowsClient: CMakeFiles/WindowsClient.dir/build.make
WindowsClient: /usr/local/lib/libopencv_stitching.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_superres.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_videostab.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_aruco.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_bgsegm.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_bioinspired.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_ccalib.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_dnn_objdetect.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_dpm.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_face.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_fuzzy.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_hfs.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_img_hash.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_line_descriptor.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_optflow.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_reg.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_rgbd.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_saliency.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_stereo.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_structured_light.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_surface_matching.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_tracking.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_xfeatures2d.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_ximgproc.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_xobjdetect.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_xphoto.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_shape.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_photo.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_datasets.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_plot.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_text.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_dnn.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_ml.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_video.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_calib3d.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_features2d.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_highgui.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_videoio.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_phase_unwrapping.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_flann.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_imgcodecs.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_objdetect.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_imgproc.3.4.1.dylib
WindowsClient: /usr/local/lib/libopencv_core.3.4.1.dylib
WindowsClient: CMakeFiles/WindowsClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable WindowsClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WindowsClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WindowsClient.dir/build: WindowsClient

.PHONY : CMakeFiles/WindowsClient.dir/build

CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/main.cpp.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/Client.cpp.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/MatConverter.cpp.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/Networkable.cpp.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/supporting/wrestart.cpp.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/supporting/restart.c.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/supporting/uici.c.o.requires
CMakeFiles/WindowsClient.dir/requires: CMakeFiles/WindowsClient.dir/supporting/uiciname.c.o.requires

.PHONY : CMakeFiles/WindowsClient.dir/requires

CMakeFiles/WindowsClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WindowsClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WindowsClient.dir/clean

CMakeFiles/WindowsClient.dir/depend:
	cd /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Linux:WindowsClient/cmake-build-debug/CMakeFiles/WindowsClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WindowsClient.dir/depend

