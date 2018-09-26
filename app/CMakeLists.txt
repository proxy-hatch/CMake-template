# Define an executable
add_executable(${PROJECT_NAME}
    src/main.cpp)

# Define the libraries this project depends upon
target_link_libraries(${PROJECT_NAME}
    PRIVATE rs232)