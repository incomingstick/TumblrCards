/*
 * mainMenu.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: Tumblr
 */
#include <iostream>
#include "mainMenu.h"
#include "console.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc > 1) {
        // TODO we should have cla's for testing purposes
    }

	// Creates the main menu to start the game
	MainMenu menu;
	
	// Displays main menu
	do    print_menu_clr("screen_main");
	while (!menu.get_input());

	return 0;
}
