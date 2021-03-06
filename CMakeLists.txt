# Project Needs a name ofcourse
project(framebook)

# Find the required Libaries

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
find_package(QJSON REQUIRED)
find_package(ImageMagick COMPONENTS Magick++ REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ${KDE4_ENABLE_EXCEPTIONS}")

add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   ${QJSON_INCLUDES}   
   ${ImageMagick_INCLUDES}
   /usr/include/ImageMagick/magick/
   /usr/include/ImageMagick/
   )

# We add our source code here
set(framebook_SRCS framebook.cpp fbApi.cpp framebookconfig.cpp framebookSettings.cpp)

# Now make sure all files get to the right place
kde4_add_plugin(plasma_applet_framebook ${framebook_SRCS})
target_link_libraries(plasma_applet_framebook
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS} ${QT_QTNETWORK_LIBRARY} ${QT_QTWEBKIT_LIBRARY} ${QJSON_LIBRARIES} ${ImageMagick_LIBRARIES})

install(TARGETS plasma_applet_framebook
        DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES framebook-applet.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
