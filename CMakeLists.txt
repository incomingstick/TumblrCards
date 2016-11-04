cmake_minimum_required(VERSION 3.0)
# Project info
project(tumblrcards)
set(tumblrcards_VERSION_MAJOR 0)
set(tumblrcards_VERSION_MINOR 0)
set(tumblrcards_VERSION_TWEAK 5)
set(tumblrcards_VERSION_SUFFIX "dev")
add_definitions(-DVERSION_STR="v${tumblrcards_VERSION_MAJOR}.${tumblrcards_VERSION_MINOR}.${tumblrcards_VERSION_TWEAK}-${tumblrcards_VERSION_SUFFIX}")

set(USE_GIT_VERSIONING true CACHE BOOL "Determines whether to use git versioning if available.")
# Git build options
find_package(Git)
if(${GIT_FOUND} AND ${USE_GIT_VERSIONING})
		add_definitions(-DWITH_GIT_INFO=1)
		# The following execute_process stolen from http://xit0.org/2013/04/cmake-use-git-branch-and-commit-details-in-project/
		# thanks, bud.
		# Get the latest abbreviated commit hash of the working branch
		execute_process(
			COMMAND git log -1 --format=%h
			WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
			OUTPUT_VARIABLE GIT_COMMIT_HASH
			OUTPUT_STRIP_TRAILING_WHITESPACE
		)

		add_definitions(-DGIT_COMMIT_STR="${GIT_COMMIT_HASH}")
endif(${GIT_FOUND} AND ${USE_GIT_VERSIONING})

include_directories("src" "src/console")
set(CMAKE_CXX_FLAGS "-g -Wall --std=c++14")

set(TC_SOURCES 
		${CMAKE_SOURCE_DIR}/src/card.cpp
		${CMAKE_SOURCE_DIR}/src/deck.cpp
		${CMAKE_SOURCE_DIR}/src/game.cpp
		${CMAKE_SOURCE_DIR}/src/mainMenu.cpp
		${CMAKE_SOURCE_DIR}/src/player.cpp
		${CMAKE_SOURCE_DIR}/src/main.cpp
		${CMAKE_SOURCE_DIR}/src/deckBuilder.cpp
		${CMAKE_SOURCE_DIR}/src/settings.cpp
		${CMAKE_SOURCE_DIR}/src/console/console.cpp
		${CMAKE_SOURCE_DIR}/src/console/imageMap.cpp
		${CMAKE_SOURCE_DIR}/src/console/utils.cpp
		${CMAKE_SOURCE_DIR}/src/console/point.cpp
		${CMAKE_SOURCE_DIR}/src/console/rectangle.cpp
)

add_executable(tumblrcards ${TC_SOURCES})
