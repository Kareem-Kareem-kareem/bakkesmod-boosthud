cmake_minimum_required(VERSION 3.16)
project(BoostHUD)

# Path to the BakkesMod SDK (cloned by GitHub Actions)
set(BAKKESMOD_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bakkesmodsdk)

# Include the helper script that provides bakkesmod_plugin()
include(${BAKKESMOD_SDK_PATH}/cmake/bakkesmod_plugin.cmake)

# Build the plugin DLL
bakkesmod_plugin(BoostHUD BoostHUD.cpp)
