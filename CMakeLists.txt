# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (" SAE921-GRP4100-LabyrintheDeLaMort")

# Include sub-projects.
set(EXECUTABLE_CUSTOM_NAME "LabyrintheDeLaMort")
add_subdirectory ("LabyrintheDeLaMort")
