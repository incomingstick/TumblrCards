/*
 * mainMenu.h
 *
 *  Created on: Mar 8, 2016
 *      Author: Tumblr
 */

#ifndef SRC_MAINMENU_H_
#define SRC_MAINMENU_H_

#include <string>
#include "deckBuilder.h"
#include "settings.h"

class MainMenu {
private:
	// starts a single player game
	void single_player();

	// starts a multi-player game
	void multi_player();

	// moves to the deck list menu
	void deck_builder();

	// moves to the settings menu
	void settings_menu();

	// quits the game
	void quit();

	DeckBuilder builder;
	Settings settings;
public:
	MainMenu();
	virtual ~MainMenu();

	bool get_input();
};

#endif /* SRC_MAINMENU_H_ */
