# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Bookshop_autogen"
  "CMakeFiles\\Bookshop_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Bookshop_autogen.dir\\ParseCache.txt"
  )
endif()
