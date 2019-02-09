cmake_minimum_required(VERSION 2.8.11)
project(HvildTomato)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(hvildtomato_SRC
  src/main.cpp
  src/hvildtomato.cpp
)

# Create code from a list of Qt designer ui files.
#set(CMAKE_AUTOUIC ON) # use this if you have CMake 3.x instead of the following
qt5_wrap_ui(hvildtomato_SRC src/hvildtomato.ui)

# Tell CMake to create the helloworld executable
add_executable(hvildtomato ${hvildtomato_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(hvildtomato Qt5::Widgets)

# Install the executable
install(TARGETS hvildtomato DESTINATION bin)