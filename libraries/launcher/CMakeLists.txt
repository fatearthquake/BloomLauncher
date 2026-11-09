cmake_minimum_required(VERSION 3.15)
project(launcher Java)
find_package(Java 1.7 REQUIRED COMPONENTS Development)

include(UseJava)
set(CMAKE_JAVA_JAR_ENTRY_POINT org.bloomlauncher.EntryPoint)
set(CMAKE_JAVA_COMPILE_FLAGS -target 7 -source 7)

set(SRC
    org/bloomlauncher/EntryPoint.java
    org/bloomlauncher/launcher/Launcher.java
    org/bloomlauncher/launcher/impl/AbstractLauncher.java
    org/bloomlauncher/launcher/impl/StandardLauncher.java
    org/bloomlauncher/exception/ParameterNotFoundException.java
    org/bloomlauncher/exception/ParseException.java
    org/bloomlauncher/utils/Parameters.java
    org/bloomlauncher/utils/ReflectionUtils.java
    org/bloomlauncher/utils/logging/Level.java
    org/bloomlauncher/utils/logging/Log.java
    org/bloomlauncher/legacy/LegacyProxy.java
)

set(LEGACY_SRC
    legacy/org/bloomlauncher/legacy/LegacyFrame.java
    legacy/org/bloomlauncher/legacy/LegacyLauncher.java
    legacy/org/bloomlauncher/legacy/fix/online/Handler.java
    legacy/org/bloomlauncher/legacy/fix/online/OnlineFixes.java
    legacy/org/bloomlauncher/legacy/fix/online/OnlineModeFix.java
    legacy/org/bloomlauncher/legacy/fix/online/SkinFix.java
    legacy/org/bloomlauncher/legacy/utils/Base64.java
    legacy/org/bloomlauncher/legacy/utils/api/MojangApi.java
    legacy/org/bloomlauncher/legacy/utils/api/Texture.java
    legacy/org/bloomlauncher/legacy/utils/json/JsonParseException.java
    legacy/org/bloomlauncher/legacy/utils/json/JsonParser.java
    legacy/org/bloomlauncher/legacy/utils/url/ByteArrayUrlConnection.java
    legacy/org/bloomlauncher/legacy/utils/url/UrlUtils.java
    legacy/net/minecraft/Launcher.java
    legacy/org/bloomlauncher/legacy/LegacyProxy.java
)

add_jar(NewLaunch ${SRC})
add_jar(NewLaunchLegacy ${LEGACY_SRC} INCLUDE_JARS NewLaunch)
install_jar(NewLaunch "${JARS_DEST_DIR}")
install_jar(NewLaunchLegacy "${JARS_DEST_DIR}")
