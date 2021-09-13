cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_BUILD_TYPE Debug)
project(SnakeGame)

set(TARGET ${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

include_directories(inc interfaces)
file(GLOB SOURCES src/*.cpp)

add_executable(${TARGET} ${SOURCES})
# target_link_libraries(${TARGET} ${LIBS})

install(
  TARGETS ${TARGET}
  RUNTIME DESTINATION bin ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})