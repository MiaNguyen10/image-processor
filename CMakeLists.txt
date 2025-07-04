cmake_minimum_required(VERSION 3.10)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR "C:/opencv/build")

find_package(OpenCV REQUIRED)
find_package(OpenMP REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_Alignof=alignof")
endif()

set(SOURCES
    src/main.cpp
    src/ImageProcessor.cpp
    src/ImageEnhancer.cpp
)

add_executable(ImageProcessor ${SOURCES})

if (OpenMP_CXX_FOUND)
    target_link_libraries(ImageProcessor
    ${OpenCV_LIBS}
    OpenMP::OpenMP_CXX
)
endif()

add_custom_command(TARGET ImageProcessor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_world4110d.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_videoio_ffmpeg4110_64.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_videoio_msmf4110_64.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_videoio_msmf4110_64d.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_world4110.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
)