cmake_minimum_required(VERSION 3.5)
# Aggiungi GoogleTest
add_subdirectory(./lib/googletest-main)
set(gtest_SORCE_DIR, ./lib/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# File sorgenti dei test
set(TEST_SOURCE_FILES TestMain.cpp ToDoTest.cpp ToDoListTest.cpp DateTest.cpp)

# Crea l'eseguibile per i test
add_executable(runTest ${TEST_SOURCE_FILES})

# Collega le librerie necessarie
target_link_libraries(runTest PRIVATE gtest gtest_main core)

# Specifica le directory di include manualmente, se necessario
target_include_directories(runTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/include)