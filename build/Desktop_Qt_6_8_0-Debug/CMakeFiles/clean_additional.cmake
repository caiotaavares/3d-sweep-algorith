# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/sweep3_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/sweep3_autogen.dir/ParseCache.txt"
  "sweep3_autogen"
  )
endif()
