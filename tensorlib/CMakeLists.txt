cmake_minimum_required( VERSION 3.16 )
project( modules CXX )
add_subdirectory( tensor )
add_executable( tensorlib1 tensorlib1.cpp )
target_link_libraries( tensorlib1 tensor )
