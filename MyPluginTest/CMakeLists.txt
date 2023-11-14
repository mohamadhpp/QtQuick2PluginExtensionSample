cmake_minimum_required(VERSION 3.16)

project(MyPluginTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(MYPLUGIN_PATH "./MyPlugin")

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appMyPluginTest
    main.cpp
)

qt_add_qml_module(appMyPluginTest
    URI MyPluginTest
    VERSION 1.0
    QML_FILES Main.qml
)

qt_add_library(MyPlugin STATIC)
qt_add_qml_module(MyPlugin
    URI MyPlugin
    QML_FILES
        ${MYPLUGIN_PATH}/MyItemControls.qml
)

set_target_properties(appMyPluginTest PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMyPluginTest
    PRIVATE Qt6::Quick MyPluginplugin
)

include(GNUInstallDirs)
install(TARGETS appMyPluginTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
