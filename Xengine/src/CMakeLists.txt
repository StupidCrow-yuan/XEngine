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
        ../thirdparty/portable-file-dialogs)

target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARY} glfw)

target_link_libraries(${PROJECT_NAME} "-framework OpenGL")

target_link_libraries(${PROJECT_NAME} ${IMGUI_LIBRARY} imgui)

target_link_libraries(${PROJECT_NAME} ${GLM_LIBRARY} glm)

target_link_libraries(${PROJECT_NAME} ${Yaml_LIBRARY} yaml-cpp)