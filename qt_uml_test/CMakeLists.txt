cmake_minimum_required(VERSION 3.16)
project(qt_uml_test)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(qt_uml_test main_qt_1.cpp)
target_link_libraries(qt_uml_test PRIVATE Qt6::Widgets)

if (WIN32)
    add_custom_command(TARGET qt_uml_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:qt_uml_test>/platforms"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${VCPKG_INSTALLED_DIR}/x64-windows/Qt6/plugins/platforms/qwindows.dll"
            "$<TARGET_FILE_DIR:qt_uml_test>/platforms/qwindows.dll"
        # Copy core Qt DLLs next to the exe
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${VCPKG_INSTALLED_DIR}/x64-windows/bin/Qt6Widgets.dll"
            "$<TARGET_FILE_DIR:qt_uml_test>/"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${VCPKG_INSTALLED_DIR}/x64-windows/bin/Qt6Gui.dll"
            "$<TARGET_FILE_DIR:qt_uml_test>/"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${VCPKG_INSTALLED_DIR}/x64-windows/bin/Qt6Core.dll"
            "$<TARGET_FILE_DIR:qt_uml_test>/"
    )
endif()