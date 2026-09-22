add_executable(Game
    main.cpp
    game_loop.cpp
 )

target_link_libraries(Game PRIVATE Engine SFML::Graphics SFML::Window)
target_compile_features(Game PRIVATE cxx_std_20)