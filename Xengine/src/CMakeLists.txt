set(SOURCE_FILES)
foreach( DIR ${CMAKE_CURRENT_LIST_DIR} )
    file(GLOB_RECURSE TEMP_FILES ${DIR}/*.mm ${DIR}/*.m ${DIR}/*.cpp ${DIR}/*.h ${DIR}/*.hpp)
    list(APPEND SOURCE_FILES ${TEMP_FILES})
endforeach()

target_sources(${EXE_NAME} PRIVATE ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
        ../thirdparty/spdlog/include
        ../thirdparty/glfw/include
        ../thirdparty/glad/include
        ../thirdparty/imgui
        ../thirdparty/glm
        ../thirdparty/stb_image
        ../thirdparty/entt
        ../thirdparty/yaml-cpp
        ../thirdparty/portable-file-dialogs
        ../thirdparty/ImGuizmo
        ../thirdparty/box2d/include
        )

target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARY} glfw)

target_link_libraries(${PROJECT_NAME} "-framework OpenGL")

target_link_libraries(${PROJECT_NAME} ${IMGUI_LIBRARY} imgui)

target_link_libraries(${PROJECT_NAME} ${GLM_LIBRARY} glm)

target_link_libraries(${PROJECT_NAME} ${Yaml_LIBRARY} yaml-cpp)

target_link_libraries(${PROJECT_NAME} ${Box2d_LIBRARY} box2d)

#配置 vulkan 环境
find_package(Vulkan REQUIRED FATAL_ERROR)
target_include_directories(${PROJECT_NAME} PRIVATE /Users/user/VulkanSDK/1.3.231.1/macOS/include) #路径改变的时候需要重新设置

set(VULKAN_LIB_FILES_LIST)
foreach(DIR /Users/user/VulkanSDK/1.3.231.1/macOS/lib)
    message(STATUS ${CMAKE_CURRENT_LIST_DIR})
    file(GLOB_RECURSE TEMP_FILES ${DIR}/*.a)
    list(APPEND VULKAN_LIB_FILES_LIST ${TEMP_FILES})
endforeach()
target_link_libraries(${PROJECT_NAME}  ${VULKAN_LIB_FILES_LIST})