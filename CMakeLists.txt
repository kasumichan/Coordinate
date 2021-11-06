cmake_minimum_required(VERSION 3.17)
project(Coordinate)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CURRENT_SOURCE_DIR ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/Qt5.12.3/5.12.3/mingw73_64")
else ()
    set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu")
endif ()

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

file(GLOB SOURCES Element/*.cpp Util/*.cpp Core/*.cpp UI/*.cpp IO/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp )


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})