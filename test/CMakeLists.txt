include(GoogleTest)

enable_testing()
add_executable(Test main.cpp Labyrinthe.cpp Porte.cpp Piece.cpp ../src/Labyrinthe.cpp ../src/Porte.cpp ../src/Piece.cpp)
target_link_libraries(Test gtest gtest_main pthread)

gtest_add_tests(Test "" AUTO)