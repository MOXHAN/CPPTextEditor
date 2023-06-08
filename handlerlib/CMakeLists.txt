add_library(handlerlib FileHandler.cpp ToolHandler.cpp DocumentHandler.cpp TableHandler.cpp)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(handlerlib
        PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )