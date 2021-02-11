include(GoogleTest)

enable_testing()
add_executable(LabyrintheTest Labyrinthe.cpp ../src/Labyrinthe.cpp ../src/Porte.cpp ../src/Piece.cpp)
target_link_libraries(LabyrintheTest gtest gtest_main pthread)
gtest_add_tests(LabyrintheTest "" AUTO)