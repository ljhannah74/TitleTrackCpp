cmake_minimum_required(VERSION 3.10)
project(TitleTrack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WIN32_EXECUTABLE TRUE)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Find all .cpp and .h files in src/ and include/ (or root)
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.h"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.h"
    "${CMAKE_SOURCE_DIR}/gui/*.cpp"
    "${CMAKE_SOURCE_DIR}/gui/*.h"
    "${CMAKE_SOURCE_DIR}/include/*.h"
)

# Find SQLite3 (CMake will locate system or vcpkg version)
find_package(SQLite3 REQUIRED)

add_executable(TitleTrack ${SRC_FILES})
target_include_directories(TitleTrack PRIVATE include gui src)
target_link_libraries(TitleTrack ${wxWidgets_LIBRARIES} SQLite::SQLite3)

add_executable(
    DALTests
    src/TitleAbstractDAL.cpp
    src/SQLiteHelper.cpp
    tests/test_TitleAbstractDAL.cpp
)
target_include_directories(DALTests PRIVATE include)
target_link_libraries(DALTests SQLite::SQLite3)
set_target_properties(DALTests PROPERTIES
    WIN32_EXECUTABLE FALSE
)