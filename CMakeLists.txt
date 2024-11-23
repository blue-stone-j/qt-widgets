cmake_minimum_required(VERSION 3.10)
project(qt_widgets)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

include(FindPkgConfig)
find_package(PkgConfig)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Svg X11Extras REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

EXECUTE_PROCESS(
  COMMAND pkg-config --variable=host_bins Qt5Core
  OUTPUT_VARIABLE Qt5BIN
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}
)

qt5_wrap_cpp(MOC_FILES include/mainwindow.h)

file(GLOB_RECURSE WIDGETS_SRCS "widgets/*.cpp")

# qt_widgets
add_executable(widgets_browser src/widgets_browser_app.cpp
  src/mainwindow.cpp

  form/QsfTitleBar.cpp
  form/QsfMainWindow.cpp
  form/QsrRibbonCore.cpp
  form/QsfToolButton.cpp
  form/uiOffice2016.cpp

  # src/add_widgets.cpp
  ${WIDGETS_SRCS}

  ${MOC_FILES}
)

target_link_libraries(widgets_browser PRIVATE

  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::OpenGL
  Qt5::Svg
  Qt5::X11Extras)
