# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Gestiondestaches_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Gestiondestaches_autogen.dir\\ParseCache.txt"
  "Gestiondestaches_autogen"
  )
endif()
