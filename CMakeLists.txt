cmake_minimum_required(VERSION 3.16)
project(BoostHUD)

# Include the BakkesMod SDK CMake helpers
add_subdirectory(bakkesmodsdk EXCLUDE_FROM_ALL)

# Create the plugin library
bakkesmod_plugin(BoostHUD BoostHUD.cpp)
