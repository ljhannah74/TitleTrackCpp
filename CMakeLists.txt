cmake_minimum_required(VERSION 3.10)
project(TitleTrackCpp)

set(CMAKE_CXX_STANDARD 17)

# Find wxWidgets (optional, remove if not needed)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add your source files here
add_executable(TitleTrackCpp
  App.cpp
  gui/MyFrame.cpp
  MyFrameDerived.cpp
  )

# Link wxWidgets (remove this line if not using wxWidgets)
target_link_libraries(TitleTrackCpp ${wxWidgets_LIBRARIES})

# Link SQLite if needed
find_package(SQLite3 REQUIRED)
target_link_libraries(TitleTrackCpp SQLite::SQLite3)
