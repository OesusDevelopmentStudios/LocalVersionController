add_subdirectory(enums)
add_subdirectory(input)

add_executable(lvc
    main.cpp
)

target_link_libraries(lvc
    PRIVATE
        lvc-input
)
