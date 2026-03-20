cmake_minimum_required(VERSION 3.20)

project(ContactManager LANGUAGES CXX)

add_executable(contact_manager
    src/ContactBook.cpp
    src/ContactMenu.cpp
    src/InputHelper.cpp
    src/main.cpp
)

target_include_directories(contact_manager
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(contact_manager PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(contact_manager PRIVATE /W3 /permissive-)
else()
    target_compile_options(contact_manager PRIVATE -Wall -Wextra -pedantic)
endif()
