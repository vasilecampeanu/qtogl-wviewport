cmake_minimum_required(VERSION 3.5)
set(This wviewport)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TS_FILES miscellaneous/wviewport_en_US.ts)
set(UI_FILES miscellaneous/mainwindow.ui)

set(PHEADER_FILES
    include/wviewport/MainWindow.h
    include/wviewport/ViewportWidget.h
)

set(PSOURCE_FILES
    src/main.cpp
    src/MainWindow.cpp
    src/ViewportWidget.cpp
)

# Create code from a list of Qt designer ui files. 
# Options may be given to uic, such as those found when executing "uic -help"
# You also need to: set(CMAKE_AUTOUIC OFF)
qt6_wrap_ui(UI_HEADERS ${UI_FILES})

set(PROJECT_SOURCES
    ${PSOURCE_FILES}
    ${PHEADER_FILES}
    ${UI_HEADERS}
    ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${This}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(${This} SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(${This}
            ${PROJECT_SOURCES}
        )
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(${This} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${This} PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
target_link_libraries(${This} PUBLIC ${OPENGL_LIBRARY})

target_include_directories(${This} PUBLIC include)

set_target_properties(${This} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${This})
endif()
