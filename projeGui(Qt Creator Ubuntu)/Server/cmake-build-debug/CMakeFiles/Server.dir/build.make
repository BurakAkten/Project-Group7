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
CMAKE_COMMAND = /home/safa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5087.36/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/safa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5087.36/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/safa/Documents/SC/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/safa/Documents/SC/Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/main.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/main.cpp.o -c /home/safa/Documents/SC/Server/main.cpp

CMakeFiles/Server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/main.cpp > CMakeFiles/Server.dir/main.cpp.i

CMakeFiles/Server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/main.cpp -o CMakeFiles/Server.dir/main.cpp.s

CMakeFiles/Server.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/main.cpp.o.requires

CMakeFiles/Server.dir/main.cpp.o.provides: CMakeFiles/Server.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/main.cpp.o.provides

CMakeFiles/Server.dir/main.cpp.o.provides.build: CMakeFiles/Server.dir/main.cpp.o


CMakeFiles/Server.dir/supporting/restart.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/supporting/restart.c.o: ../supporting/restart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Server.dir/supporting/restart.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/supporting/restart.c.o   -c /home/safa/Documents/SC/Server/supporting/restart.c

CMakeFiles/Server.dir/supporting/restart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/supporting/restart.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/safa/Documents/SC/Server/supporting/restart.c > CMakeFiles/Server.dir/supporting/restart.c.i

CMakeFiles/Server.dir/supporting/restart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/supporting/restart.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/safa/Documents/SC/Server/supporting/restart.c -o CMakeFiles/Server.dir/supporting/restart.c.s

CMakeFiles/Server.dir/supporting/restart.c.o.requires:

.PHONY : CMakeFiles/Server.dir/supporting/restart.c.o.requires

CMakeFiles/Server.dir/supporting/restart.c.o.provides: CMakeFiles/Server.dir/supporting/restart.c.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/supporting/restart.c.o.provides.build
.PHONY : CMakeFiles/Server.dir/supporting/restart.c.o.provides

CMakeFiles/Server.dir/supporting/restart.c.o.provides.build: CMakeFiles/Server.dir/supporting/restart.c.o


CMakeFiles/Server.dir/supporting/uici.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/supporting/uici.c.o: ../supporting/uici.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Server.dir/supporting/uici.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/supporting/uici.c.o   -c /home/safa/Documents/SC/Server/supporting/uici.c

CMakeFiles/Server.dir/supporting/uici.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/supporting/uici.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/safa/Documents/SC/Server/supporting/uici.c > CMakeFiles/Server.dir/supporting/uici.c.i

CMakeFiles/Server.dir/supporting/uici.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/supporting/uici.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/safa/Documents/SC/Server/supporting/uici.c -o CMakeFiles/Server.dir/supporting/uici.c.s

CMakeFiles/Server.dir/supporting/uici.c.o.requires:

.PHONY : CMakeFiles/Server.dir/supporting/uici.c.o.requires

CMakeFiles/Server.dir/supporting/uici.c.o.provides: CMakeFiles/Server.dir/supporting/uici.c.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/supporting/uici.c.o.provides.build
.PHONY : CMakeFiles/Server.dir/supporting/uici.c.o.provides

CMakeFiles/Server.dir/supporting/uici.c.o.provides.build: CMakeFiles/Server.dir/supporting/uici.c.o


CMakeFiles/Server.dir/supporting/uiciname.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/supporting/uiciname.c.o: ../supporting/uiciname.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Server.dir/supporting/uiciname.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/supporting/uiciname.c.o   -c /home/safa/Documents/SC/Server/supporting/uiciname.c

CMakeFiles/Server.dir/supporting/uiciname.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/supporting/uiciname.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/safa/Documents/SC/Server/supporting/uiciname.c > CMakeFiles/Server.dir/supporting/uiciname.c.i

CMakeFiles/Server.dir/supporting/uiciname.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/supporting/uiciname.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/safa/Documents/SC/Server/supporting/uiciname.c -o CMakeFiles/Server.dir/supporting/uiciname.c.s

CMakeFiles/Server.dir/supporting/uiciname.c.o.requires:

.PHONY : CMakeFiles/Server.dir/supporting/uiciname.c.o.requires

CMakeFiles/Server.dir/supporting/uiciname.c.o.provides: CMakeFiles/Server.dir/supporting/uiciname.c.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/supporting/uiciname.c.o.provides.build
.PHONY : CMakeFiles/Server.dir/supporting/uiciname.c.o.provides

CMakeFiles/Server.dir/supporting/uiciname.c.o.provides.build: CMakeFiles/Server.dir/supporting/uiciname.c.o


CMakeFiles/Server.dir/MatConverter.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/MatConverter.cpp.o: ../MatConverter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server.dir/MatConverter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/MatConverter.cpp.o -c /home/safa/Documents/SC/Server/MatConverter.cpp

CMakeFiles/Server.dir/MatConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/MatConverter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/MatConverter.cpp > CMakeFiles/Server.dir/MatConverter.cpp.i

CMakeFiles/Server.dir/MatConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/MatConverter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/MatConverter.cpp -o CMakeFiles/Server.dir/MatConverter.cpp.s

CMakeFiles/Server.dir/MatConverter.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/MatConverter.cpp.o.requires

CMakeFiles/Server.dir/MatConverter.cpp.o.provides: CMakeFiles/Server.dir/MatConverter.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/MatConverter.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/MatConverter.cpp.o.provides

CMakeFiles/Server.dir/MatConverter.cpp.o.provides.build: CMakeFiles/Server.dir/MatConverter.cpp.o


CMakeFiles/Server.dir/Server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Server.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Server.cpp.o -c /home/safa/Documents/SC/Server/Server.cpp

CMakeFiles/Server.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/Server.cpp > CMakeFiles/Server.dir/Server.cpp.i

CMakeFiles/Server.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/Server.cpp -o CMakeFiles/Server.dir/Server.cpp.s

CMakeFiles/Server.dir/Server.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/Server.cpp.o.requires

CMakeFiles/Server.dir/Server.cpp.o.provides: CMakeFiles/Server.dir/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Server.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/Server.cpp.o.provides

CMakeFiles/Server.dir/Server.cpp.o.provides.build: CMakeFiles/Server.dir/Server.cpp.o


CMakeFiles/Server.dir/Networkable.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Networkable.cpp.o: ../Networkable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Server.dir/Networkable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Networkable.cpp.o -c /home/safa/Documents/SC/Server/Networkable.cpp

CMakeFiles/Server.dir/Networkable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Networkable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/Networkable.cpp > CMakeFiles/Server.dir/Networkable.cpp.i

CMakeFiles/Server.dir/Networkable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Networkable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/Networkable.cpp -o CMakeFiles/Server.dir/Networkable.cpp.s

CMakeFiles/Server.dir/Networkable.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/Networkable.cpp.o.requires

CMakeFiles/Server.dir/Networkable.cpp.o.provides: CMakeFiles/Server.dir/Networkable.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Networkable.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/Networkable.cpp.o.provides

CMakeFiles/Server.dir/Networkable.cpp.o.provides.build: CMakeFiles/Server.dir/Networkable.cpp.o


CMakeFiles/Server.dir/motor/Motor.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/motor/Motor.cpp.o: ../motor/Motor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Server.dir/motor/Motor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/motor/Motor.cpp.o -c /home/safa/Documents/SC/Server/motor/Motor.cpp

CMakeFiles/Server.dir/motor/Motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/motor/Motor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/motor/Motor.cpp > CMakeFiles/Server.dir/motor/Motor.cpp.i

CMakeFiles/Server.dir/motor/Motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/motor/Motor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/motor/Motor.cpp -o CMakeFiles/Server.dir/motor/Motor.cpp.s

CMakeFiles/Server.dir/motor/Motor.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/motor/Motor.cpp.o.requires

CMakeFiles/Server.dir/motor/Motor.cpp.o.provides: CMakeFiles/Server.dir/motor/Motor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/motor/Motor.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/motor/Motor.cpp.o.provides

CMakeFiles/Server.dir/motor/Motor.cpp.o.provides.build: CMakeFiles/Server.dir/motor/Motor.cpp.o


CMakeFiles/Server.dir/image/Detected.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/image/Detected.cpp.o: ../image/Detected.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Server.dir/image/Detected.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/image/Detected.cpp.o -c /home/safa/Documents/SC/Server/image/Detected.cpp

CMakeFiles/Server.dir/image/Detected.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/image/Detected.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/image/Detected.cpp > CMakeFiles/Server.dir/image/Detected.cpp.i

CMakeFiles/Server.dir/image/Detected.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/image/Detected.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/image/Detected.cpp -o CMakeFiles/Server.dir/image/Detected.cpp.s

CMakeFiles/Server.dir/image/Detected.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/image/Detected.cpp.o.requires

CMakeFiles/Server.dir/image/Detected.cpp.o.provides: CMakeFiles/Server.dir/image/Detected.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/image/Detected.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/image/Detected.cpp.o.provides

CMakeFiles/Server.dir/image/Detected.cpp.o.provides.build: CMakeFiles/Server.dir/image/Detected.cpp.o


CMakeFiles/Server.dir/image/Recognation.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/image/Recognation.cpp.o: ../image/Recognation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Server.dir/image/Recognation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/image/Recognation.cpp.o -c /home/safa/Documents/SC/Server/image/Recognation.cpp

CMakeFiles/Server.dir/image/Recognation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/image/Recognation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safa/Documents/SC/Server/image/Recognation.cpp > CMakeFiles/Server.dir/image/Recognation.cpp.i

CMakeFiles/Server.dir/image/Recognation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/image/Recognation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safa/Documents/SC/Server/image/Recognation.cpp -o CMakeFiles/Server.dir/image/Recognation.cpp.s

CMakeFiles/Server.dir/image/Recognation.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/image/Recognation.cpp.o.requires

CMakeFiles/Server.dir/image/Recognation.cpp.o.provides: CMakeFiles/Server.dir/image/Recognation.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/image/Recognation.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/image/Recognation.cpp.o.provides

CMakeFiles/Server.dir/image/Recognation.cpp.o.provides.build: CMakeFiles/Server.dir/image/Recognation.cpp.o


# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/main.cpp.o" \
"CMakeFiles/Server.dir/supporting/restart.c.o" \
"CMakeFiles/Server.dir/supporting/uici.c.o" \
"CMakeFiles/Server.dir/supporting/uiciname.c.o" \
"CMakeFiles/Server.dir/MatConverter.cpp.o" \
"CMakeFiles/Server.dir/Server.cpp.o" \
"CMakeFiles/Server.dir/Networkable.cpp.o" \
"CMakeFiles/Server.dir/motor/Motor.cpp.o" \
"CMakeFiles/Server.dir/image/Detected.cpp.o" \
"CMakeFiles/Server.dir/image/Recognation.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/main.cpp.o
Server: CMakeFiles/Server.dir/supporting/restart.c.o
Server: CMakeFiles/Server.dir/supporting/uici.c.o
Server: CMakeFiles/Server.dir/supporting/uiciname.c.o
Server: CMakeFiles/Server.dir/MatConverter.cpp.o
Server: CMakeFiles/Server.dir/Server.cpp.o
Server: CMakeFiles/Server.dir/Networkable.cpp.o
Server: CMakeFiles/Server.dir/motor/Motor.cpp.o
Server: CMakeFiles/Server.dir/image/Detected.cpp.o
Server: CMakeFiles/Server.dir/image/Recognation.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: /usr/local/lib/libopencv_stitching.so.3.4.1
Server: /usr/local/lib/libopencv_objdetect.so.3.4.1
Server: /usr/local/lib/libopencv_ml.so.3.4.1
Server: /usr/local/lib/libopencv_superres.so.3.4.1
Server: /usr/local/lib/libopencv_shape.so.3.4.1
Server: /usr/local/lib/libopencv_dnn.so.3.4.1
Server: /usr/local/lib/libopencv_videostab.so.3.4.1
Server: /usr/local/lib/libopencv_photo.so.3.4.1
Server: /usr/local/lib/libopencv_calib3d.so.3.4.1
Server: /usr/local/lib/libopencv_features2d.so.3.4.1
Server: /usr/local/lib/libopencv_video.so.3.4.1
Server: /usr/local/lib/libopencv_flann.so.3.4.1
Server: /usr/local/lib/libopencv_highgui.so.3.4.1
Server: /usr/local/lib/libopencv_videoio.so.3.4.1
Server: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
Server: /usr/local/lib/libopencv_imgproc.so.3.4.1
Server: /usr/local/lib/libopencv_core.so.3.4.1
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/main.cpp.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/supporting/restart.c.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/supporting/uici.c.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/supporting/uiciname.c.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/MatConverter.cpp.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/Server.cpp.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/Networkable.cpp.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/motor/Motor.cpp.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/image/Detected.cpp.o.requires
CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/image/Recognation.cpp.o.requires

.PHONY : CMakeFiles/Server.dir/requires

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/safa/Documents/SC/Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/safa/Documents/SC/Server /home/safa/Documents/SC/Server /home/safa/Documents/SC/Server/cmake-build-debug /home/safa/Documents/SC/Server/cmake-build-debug /home/safa/Documents/SC/Server/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

