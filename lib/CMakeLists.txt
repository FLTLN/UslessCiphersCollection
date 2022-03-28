file(GLOB LIB_SOURCES "sources/*.cpp")
file(GLOB LIB_HEADERS "include/*.h")
file(GLOB INTERNAL_LIB_HEADERS "include/internal/*.h")

set(LIB_HEADERS "${LIB_HEADERS}" PARENT_SCOPE)

add_library(ciph STATIC ${LIB_SOURCES} ${LIB_HEADERS} ${INTERNAL_LIB_HEADERS})
