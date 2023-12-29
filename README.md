
# Qt Quick 2 Plugin Extension Sample

In this project, I created a qml plugin and got the output from it, and I plan to use it in another project.

Cmake is used in this library.

[MyPlugin Project](#myplugin-project) \
[MyPluginTest Project](#myplugintest-project) \
[Usage](#Usage)

# MyPlugin Project

To build an exportable plugin, the following are required.

**CMakeLists.txt**

```
set(PROJECT_NAME "MyPlugin")
set(QML_PLUGIN_DESTDIR "../Release/")
```

```
install(DIRECTORY "${CMAKE_BINARY_DIR}/${PROJECT_NAME}" DESTINATION ${QML_PLUGIN_DESTDIR}
        FILE_PERMISSIONS
            OWNER_READ OWNER_EXECUTE OWNER_WRITE
            GROUP_READ GROUP_EXECUTE
            WORLD_READ WORLD_EXECUTE
        DIRECTORY_PERMISSIONS
            OWNER_READ OWNER_EXECUTE OWNER_WRITE
            GROUP_READ GROUP_EXECUTE GROUP_WRITE
            WORLD_READ WORLD_EXECUTE
        FILES_MATCHING PATTERN "*")
```
# MyPluginTest Project

To build an exportable plugin, the following are required.

**CMakeLists.txt**

```
set(MYPLUGIN_PATH "./MyPlugin")
```

```
qt_add_library(MyPlugin STATIC)
qt_add_qml_module(MyPlugin
    URI MyPlugin
    QML_FILES
        ${MYPLUGIN_PATH}/MyItemControls.qml
)
```

```
target_link_libraries(appMyPluginTest
    PRIVATE Qt6::Quick MyPluginplugin
)
```

**main.cpp**

```
#include <QtQml/qqmlextensionplugin.h>

Q_IMPORT_QML_PLUGIN(MyPluginPlugin)
```
# Usage

## **Step 1**

After building the MyPlugin plugin, you must run the following command in that folder.


```command
cmake --install ./
```

**Note:** That Cmake must be installed on your system before that.

Now you will have a folder called Release in the folder next to "MyPlugin", where the library outputs are placed.

**Release Folder Structure**
```
└── MyPlugin
    ├── MyPlugin.qmltypes
    ├── MyPlugin_qml_module_dir_map.qrc
    ├── MyPluginplugin.lib
    ├── MyRecControls.qml
    └── qmldir
```

## **Step 2**

Now we add "MyPlugin" folder from inside "Release" folder to our example folder.
