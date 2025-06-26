cmake_minimum_required(VERSION 3.10)
project(MyApp)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(MyApp main.cpp MyFrame.cpp)
target_link_libraries(MyApp ${wxWidgets_LIBRARIES})
