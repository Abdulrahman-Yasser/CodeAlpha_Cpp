# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build

# Include any dependencies generated for this target.
include CMakeFiles/ToDo_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ToDo_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ToDo_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ToDo_list.dir/flags.make

CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o: CMakeFiles/ToDo_list.dir/flags.make
CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o: /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/DS/LinkedList.cpp
CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o: CMakeFiles/ToDo_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o -MF CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o.d -o CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o -c /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/DS/LinkedList.cpp

CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/DS/LinkedList.cpp > CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.i

CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/DS/LinkedList.cpp -o CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.s

CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o: CMakeFiles/ToDo_list.dir/flags.make
CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o: /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element/to-do_Element_.cpp
CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o: CMakeFiles/ToDo_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o -MF CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o.d -o CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o -c /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element/to-do_Element_.cpp

CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element/to-do_Element_.cpp > CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.i

CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element/to-do_Element_.cpp -o CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.s

CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o: CMakeFiles/ToDo_list.dir/flags.make
CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o: /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element_with_wrapper/to-do_Element.cpp
CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o: CMakeFiles/ToDo_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o -MF CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o.d -o CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o -c /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element_with_wrapper/to-do_Element.cpp

CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element_with_wrapper/to-do_Element.cpp > CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.i

CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Element_with_wrapper/to-do_Element.cpp -o CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.s

CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o: CMakeFiles/ToDo_list.dir/flags.make
CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o: /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Group/to-do_group.cpp
CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o: CMakeFiles/ToDo_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o -MF CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o.d -o CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o -c /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Group/to-do_group.cpp

CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Group/to-do_group.cpp > CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.i

CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/ToDo_Group/to-do_group.cpp -o CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.s

CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o: CMakeFiles/ToDo_list.dir/flags.make
CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o: /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/chrono_wrapper/chrono_wrapper.cpp
CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o: CMakeFiles/ToDo_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o -MF CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o.d -o CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o -c /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/chrono_wrapper/chrono_wrapper.cpp

CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/chrono_wrapper/chrono_wrapper.cpp > CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.i

CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/chrono_wrapper/chrono_wrapper.cpp -o CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.s

CMakeFiles/ToDo_list.dir/main.cpp.o: CMakeFiles/ToDo_list.dir/flags.make
CMakeFiles/ToDo_list.dir/main.cpp.o: /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/main.cpp
CMakeFiles/ToDo_list.dir/main.cpp.o: CMakeFiles/ToDo_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ToDo_list.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ToDo_list.dir/main.cpp.o -MF CMakeFiles/ToDo_list.dir/main.cpp.o.d -o CMakeFiles/ToDo_list.dir/main.cpp.o -c /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/main.cpp

CMakeFiles/ToDo_list.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ToDo_list.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/main.cpp > CMakeFiles/ToDo_list.dir/main.cpp.i

CMakeFiles/ToDo_list.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ToDo_list.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/main.cpp -o CMakeFiles/ToDo_list.dir/main.cpp.s

# Object files for target ToDo_list
ToDo_list_OBJECTS = \
"CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o" \
"CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o" \
"CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o" \
"CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o" \
"CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o" \
"CMakeFiles/ToDo_list.dir/main.cpp.o"

# External object files for target ToDo_list
ToDo_list_EXTERNAL_OBJECTS =

ToDo_list: CMakeFiles/ToDo_list.dir/DS/LinkedList.cpp.o
ToDo_list: CMakeFiles/ToDo_list.dir/ToDo_Element/to-do_Element_.cpp.o
ToDo_list: CMakeFiles/ToDo_list.dir/ToDo_Element_with_wrapper/to-do_Element.cpp.o
ToDo_list: CMakeFiles/ToDo_list.dir/ToDo_Group/to-do_group.cpp.o
ToDo_list: CMakeFiles/ToDo_list.dir/chrono_wrapper/chrono_wrapper.cpp.o
ToDo_list: CMakeFiles/ToDo_list.dir/main.cpp.o
ToDo_list: CMakeFiles/ToDo_list.dir/build.make
ToDo_list: CMakeFiles/ToDo_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ToDo_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ToDo_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ToDo_list.dir/build: ToDo_list
.PHONY : CMakeFiles/ToDo_list.dir/build

CMakeFiles/ToDo_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ToDo_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ToDo_list.dir/clean

CMakeFiles/ToDo_list.dir/depend:
	cd /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build /home/abdu/Study/CodeAlpha_Cpp/To-Do_List_WithoutChrono/build/CMakeFiles/ToDo_list.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ToDo_list.dir/depend

