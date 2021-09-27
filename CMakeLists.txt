cmake_minimum_required(VERSION 3.17)
project(Coordinate)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/Qt5.12.11/5.12.11/msvc2017_64")
else ()
    set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu")
endif ()

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME} main.cpp
        Element/Element.cpp Element/Element.h
        Element/Triangle.cpp Element/Triangle.h
        Util/Point.cpp Util/Point.h
        Util/Plane.cpp Util/Plane.h
        Element/Quadrilateral.cpp Element/Quadrilateral.h
        Element/Tetrahedron.cpp Element/Tetrahedron.h
        Element/Hexahedron.cpp Element/Hexahedron.h
        UI/MainWindow.cpp UI/MainWindow.h
        UI/InputDialog.cpp UI/InputDialog.h
        UI/Canvas.cpp UI/Canvas.h
        Util/Axis.cpp Util/Axis.h
        IO/ElementInfoReader.cpp IO/ElementInfoReader.h
        UI/MainWindow.cpp UI/MainWindow.h
        Enum/InputType.h Enum/SetAxisMethod.h
        Core/CalcAxis.cpp Core/CalcAxis.h
        Core/SetAxis.cpp Core/SetAxis.h
        IO/AxisInfoWriter.cpp IO/AxisInfoWriter.h)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})