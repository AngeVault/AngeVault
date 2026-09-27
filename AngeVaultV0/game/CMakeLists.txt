add_executable(Game
    main.cpp
    game_loop.cpp
 )

target_link_libraries(Game PRIVATE Engine SFML::Graphics SFML::Window)
target_compile_features(Game PRIVATE cxx_std_20)

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets 
    $<TARGET_FILE_DIR:Game>/assets)