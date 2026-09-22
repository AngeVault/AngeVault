add_library(Engine STATIC
    # vide pour l'instant si tout est header-only (templates)
    src/temp.cpp
)

target_include_directories(Engine PUBLIC include)
target_compile_features(Engine PUBLIC cxx_std_20)

# Engine n'a besoin QUE de System (math), jamais de Graphics/Window
target_link_libraries(Engine PUBLIC SFML::System glm::glm)

add_executable(EngineTests tests/test_component_pool.cpp)
target_link_libraries(EngineTests PRIVATE Engine)