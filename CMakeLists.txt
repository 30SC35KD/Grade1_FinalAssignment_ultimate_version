cmake_minimum_required(VERSION 3.5)

project(SoccerGoal VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core GUI Multimedia)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SoccerGoal
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resource.qrc

        selectbutton1.h selectbutton1.cpp
        prescene.h prescene.cpp
        kickoff.h kickoff.cpp
        game.h game.cpp

        selectdialog1.h selectdialog1.cpp
        selectdialog2.h selectdialog2.cpp
        playerbutton.h playerbutton.cpp
        player.h player.cpp
        ball.h ball.cpp
        aftergoal.h aftergoal.cpp
        button.h button.cpp
        win1.h win1.cpp
        win2.h win2.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SoccerGoal APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SoccerGoal SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SoccerGoal
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SoccerGoal PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(SoccerGoal PRIVATE Qt6::Core)
#target_link_libraries(SoccerGoal PRIVATE Qt6::GUI)
target_link_libraries(SoccerGoal PRIVATE Qt6::Multimedia)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SoccerGoal)
endif()
set_target_properties(SoccerGoal PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SoccerGoal
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SoccerGoal)
endif()
