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
CMAKE_SOURCE_DIR = /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/main.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/main.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/main.cpp

CMakeFiles/Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/main.cpp > CMakeFiles/Client.dir/main.cpp.i

CMakeFiles/Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/main.cpp -o CMakeFiles/Client.dir/main.cpp.s

CMakeFiles/Client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/main.cpp.o.requires

CMakeFiles/Client.dir/main.cpp.o.provides: CMakeFiles/Client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/main.cpp.o.provides

CMakeFiles/Client.dir/main.cpp.o.provides.build: CMakeFiles/Client.dir/main.cpp.o


CMakeFiles/Client.dir/supporting/restart.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/supporting/restart.c.o: ../supporting/restart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Client.dir/supporting/restart.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/supporting/restart.c.o   -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/restart.c

CMakeFiles/Client.dir/supporting/restart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/supporting/restart.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/restart.c > CMakeFiles/Client.dir/supporting/restart.c.i

CMakeFiles/Client.dir/supporting/restart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/supporting/restart.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/restart.c -o CMakeFiles/Client.dir/supporting/restart.c.s

CMakeFiles/Client.dir/supporting/restart.c.o.requires:

.PHONY : CMakeFiles/Client.dir/supporting/restart.c.o.requires

CMakeFiles/Client.dir/supporting/restart.c.o.provides: CMakeFiles/Client.dir/supporting/restart.c.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/supporting/restart.c.o.provides.build
.PHONY : CMakeFiles/Client.dir/supporting/restart.c.o.provides

CMakeFiles/Client.dir/supporting/restart.c.o.provides.build: CMakeFiles/Client.dir/supporting/restart.c.o


CMakeFiles/Client.dir/supporting/uici.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/supporting/uici.c.o: ../supporting/uici.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Client.dir/supporting/uici.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/supporting/uici.c.o   -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/uici.c

CMakeFiles/Client.dir/supporting/uici.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/supporting/uici.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/uici.c > CMakeFiles/Client.dir/supporting/uici.c.i

CMakeFiles/Client.dir/supporting/uici.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/supporting/uici.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/uici.c -o CMakeFiles/Client.dir/supporting/uici.c.s

CMakeFiles/Client.dir/supporting/uici.c.o.requires:

.PHONY : CMakeFiles/Client.dir/supporting/uici.c.o.requires

CMakeFiles/Client.dir/supporting/uici.c.o.provides: CMakeFiles/Client.dir/supporting/uici.c.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/supporting/uici.c.o.provides.build
.PHONY : CMakeFiles/Client.dir/supporting/uici.c.o.provides

CMakeFiles/Client.dir/supporting/uici.c.o.provides.build: CMakeFiles/Client.dir/supporting/uici.c.o


CMakeFiles/Client.dir/supporting/uiciname.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/supporting/uiciname.c.o: ../supporting/uiciname.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Client.dir/supporting/uiciname.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/supporting/uiciname.c.o   -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/uiciname.c

CMakeFiles/Client.dir/supporting/uiciname.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/supporting/uiciname.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/uiciname.c > CMakeFiles/Client.dir/supporting/uiciname.c.i

CMakeFiles/Client.dir/supporting/uiciname.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/supporting/uiciname.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/supporting/uiciname.c -o CMakeFiles/Client.dir/supporting/uiciname.c.s

CMakeFiles/Client.dir/supporting/uiciname.c.o.requires:

.PHONY : CMakeFiles/Client.dir/supporting/uiciname.c.o.requires

CMakeFiles/Client.dir/supporting/uiciname.c.o.provides: CMakeFiles/Client.dir/supporting/uiciname.c.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/supporting/uiciname.c.o.provides.build
.PHONY : CMakeFiles/Client.dir/supporting/uiciname.c.o.provides

CMakeFiles/Client.dir/supporting/uiciname.c.o.provides.build: CMakeFiles/Client.dir/supporting/uiciname.c.o


CMakeFiles/Client.dir/MatConverter.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/MatConverter.cpp.o: ../MatConverter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/MatConverter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/MatConverter.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/MatConverter.cpp

CMakeFiles/Client.dir/MatConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/MatConverter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/MatConverter.cpp > CMakeFiles/Client.dir/MatConverter.cpp.i

CMakeFiles/Client.dir/MatConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/MatConverter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/MatConverter.cpp -o CMakeFiles/Client.dir/MatConverter.cpp.s

CMakeFiles/Client.dir/MatConverter.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/MatConverter.cpp.o.requires

CMakeFiles/Client.dir/MatConverter.cpp.o.provides: CMakeFiles/Client.dir/MatConverter.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/MatConverter.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/MatConverter.cpp.o.provides

CMakeFiles/Client.dir/MatConverter.cpp.o.provides.build: CMakeFiles/Client.dir/MatConverter.cpp.o


CMakeFiles/Client.dir/Networkable.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Networkable.cpp.o: ../Networkable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/Networkable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Networkable.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/Networkable.cpp

CMakeFiles/Client.dir/Networkable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Networkable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/Networkable.cpp > CMakeFiles/Client.dir/Networkable.cpp.i

CMakeFiles/Client.dir/Networkable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Networkable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/Networkable.cpp -o CMakeFiles/Client.dir/Networkable.cpp.s

CMakeFiles/Client.dir/Networkable.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Networkable.cpp.o.requires

CMakeFiles/Client.dir/Networkable.cpp.o.provides: CMakeFiles/Client.dir/Networkable.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Networkable.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Networkable.cpp.o.provides

CMakeFiles/Client.dir/Networkable.cpp.o.provides.build: CMakeFiles/Client.dir/Networkable.cpp.o


CMakeFiles/Client.dir/Client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/Client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Client.cpp.o -c /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/Client.cpp

CMakeFiles/Client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/Client.cpp > CMakeFiles/Client.dir/Client.cpp.i

CMakeFiles/Client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/Client.cpp -o CMakeFiles/Client.dir/Client.cpp.s

CMakeFiles/Client.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/Client.dir/Client.cpp.o.requires

CMakeFiles/Client.dir/Client.cpp.o.provides: CMakeFiles/Client.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/Client.dir/Client.cpp.o.provides

CMakeFiles/Client.dir/Client.cpp.o.provides.build: CMakeFiles/Client.dir/Client.cpp.o


# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/main.cpp.o" \
"CMakeFiles/Client.dir/supporting/restart.c.o" \
"CMakeFiles/Client.dir/supporting/uici.c.o" \
"CMakeFiles/Client.dir/supporting/uiciname.c.o" \
"CMakeFiles/Client.dir/MatConverter.cpp.o" \
"CMakeFiles/Client.dir/Networkable.cpp.o" \
"CMakeFiles/Client.dir/Client.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/main.cpp.o
Client: CMakeFiles/Client.dir/supporting/restart.c.o
Client: CMakeFiles/Client.dir/supporting/uici.c.o
Client: CMakeFiles/Client.dir/supporting/uiciname.c.o
Client: CMakeFiles/Client.dir/MatConverter.cpp.o
Client: CMakeFiles/Client.dir/Networkable.cpp.o
Client: CMakeFiles/Client.dir/Client.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: /usr/local/lib/libopencv_stitching.3.4.1.dylib
Client: /usr/local/lib/libopencv_superres.3.4.1.dylib
Client: /usr/local/lib/libopencv_videostab.3.4.1.dylib
Client: /usr/local/lib/libopencv_aruco.3.4.1.dylib
Client: /usr/local/lib/libopencv_bgsegm.3.4.1.dylib
Client: /usr/local/lib/libopencv_bioinspired.3.4.1.dylib
Client: /usr/local/lib/libopencv_ccalib.3.4.1.dylib
Client: /usr/local/lib/libopencv_dnn_objdetect.3.4.1.dylib
Client: /usr/local/lib/libopencv_dpm.3.4.1.dylib
Client: /usr/local/lib/libopencv_face.3.4.1.dylib
Client: /usr/local/lib/libopencv_fuzzy.3.4.1.dylib
Client: /usr/local/lib/libopencv_hfs.3.4.1.dylib
Client: /usr/local/lib/libopencv_img_hash.3.4.1.dylib
Client: /usr/local/lib/libopencv_line_descriptor.3.4.1.dylib
Client: /usr/local/lib/libopencv_optflow.3.4.1.dylib
Client: /usr/local/lib/libopencv_reg.3.4.1.dylib
Client: /usr/local/lib/libopencv_rgbd.3.4.1.dylib
Client: /usr/local/lib/libopencv_saliency.3.4.1.dylib
Client: /usr/local/lib/libopencv_stereo.3.4.1.dylib
Client: /usr/local/lib/libopencv_structured_light.3.4.1.dylib
Client: /usr/local/lib/libopencv_surface_matching.3.4.1.dylib
Client: /usr/local/lib/libopencv_tracking.3.4.1.dylib
Client: /usr/local/lib/libopencv_xfeatures2d.3.4.1.dylib
Client: /usr/local/lib/libopencv_ximgproc.3.4.1.dylib
Client: /usr/local/lib/libopencv_xobjdetect.3.4.1.dylib
Client: /usr/local/lib/libopencv_xphoto.3.4.1.dylib
Client: /usr/local/lib/libopencv_shape.3.4.1.dylib
Client: /usr/local/lib/libopencv_photo.3.4.1.dylib
Client: /usr/local/lib/libopencv_datasets.3.4.1.dylib
Client: /usr/local/lib/libopencv_plot.3.4.1.dylib
Client: /usr/local/lib/libopencv_text.3.4.1.dylib
Client: /usr/local/lib/libopencv_dnn.3.4.1.dylib
Client: /usr/local/lib/libopencv_ml.3.4.1.dylib
Client: /usr/local/lib/libopencv_video.3.4.1.dylib
Client: /usr/local/lib/libopencv_calib3d.3.4.1.dylib
Client: /usr/local/lib/libopencv_features2d.3.4.1.dylib
Client: /usr/local/lib/libopencv_highgui.3.4.1.dylib
Client: /usr/local/lib/libopencv_videoio.3.4.1.dylib
Client: /usr/local/lib/libopencv_phase_unwrapping.3.4.1.dylib
Client: /usr/local/lib/libopencv_flann.3.4.1.dylib
Client: /usr/local/lib/libopencv_imgcodecs.3.4.1.dylib
Client: /usr/local/lib/libopencv_objdetect.3.4.1.dylib
Client: /usr/local/lib/libopencv_imgproc.3.4.1.dylib
Client: /usr/local/lib/libopencv_core.3.4.1.dylib
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/main.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/supporting/restart.c.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/supporting/uici.c.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/supporting/uiciname.c.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/MatConverter.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Networkable.cpp.o.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Client.cpp.o.requires

.PHONY : CMakeFiles/Client.dir/requires

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug /Users/vakhidbetrakhmadov/Desktop/Project/Project-Group7/Server-Client-v3/Client/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

