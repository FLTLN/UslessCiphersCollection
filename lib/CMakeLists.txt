file(GLOB LIB_SOURCES "sources/*.cpp")

include_directories("${CMAKE_SOURCE_DIR}/lib/include" "${CMAKE_SOURCE_DIR}/lib/include/internal")

set(LIB_HEADERS "${LIB_HEADERS}" PARENT_SCOPE)

add_library(ciph STATIC ${LIB_SOURCES})
