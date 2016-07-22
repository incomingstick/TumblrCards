/*
 * game.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Tumblr
 */
#include <string>
#include <iostream>
#include <sstream>
#include "game.h"
#include "utils.h"

using namespace std;

/*
 * Default Game constructor
 */
Game::Game(string type) {
	players = type;
	if(players != "single" || players != "mutli")
		// Throw custruction error here
	cont = true;
	myTurn = false;
}

/*
 * Default Game Destructor
 */
Game::~Game() {
	// TODO
}

/*
 * Load needed game content here
 * This should always load before the game begins
 */
void Game::load_content(const Deck selected) {
	 // loads in the selected deck for the player
	player.select_deck(selected);

	// sets the players starting mana and shuffles the deck
	player.set_mana(opponent.get_life());
	player.get_deck()->shuffle();

	// draws the players starting hand
	while(player.get_hand()->size() < START_HAND) player.draw_card();

	// gets the images of the cards in the players hand
	for(Card* card : player.get_hand()->get_vector()) {
		display.add_image(card->get_image());
	}

	// Game mode specific content loading
	if(players == "single") {
		/*
		 * TODO loads AI's deck here
		 * For now it will just be
		 * a copy of the players deck.
		 */
		opponent.select_deck(selected);
		while(opponent.get_hand()->size() < START_HAND) opponent.draw_card();
		opponent.set_mana(player.get_life());
		opponent.get_deck()->shuffle();
	}
	else if(players == "mutli") {
		// TODO loads opponenets deck here
	}
	else { /* TODO Something went wrong??? */ }
	
	
	update();
}

/*
 * Unload game data here
 * this should be called at the end of the game
 * to prep us for deconstruction
 */
void Game::unload_content() {
	// TODO
}

void Game::update() {
	/*
	 * TODO This is the running function of the game.
	 * This will be where the player takes their turn.
	 */

    // Multiplayer should not play yet
	if(players == "multi") return;
	
	// prints the game to the console
	draw();
	myTurn = true;
	
	// takes in the players input
	string in;
	cin >> in;
	size_t choice = 0;
	if(in == "exit") {
		unload_content();
		return;
	}
	else istringstream(in) >> choice;
	
	// parses out the players input
    if(player.get_mana() > 0 && choice != 0) {
        player.cast(choice - 1);
    	update();
		return;
    } else {
        /* "Combat phase" */
		// TODO
		
        /* "Draw phase" */
		// if at starting hand only draw one card
		if(player.get_hand()->size() > START_HAND)
			player.draw_card();
		
		// draw cards until you are back to starting limit
		while(player.get_hand()->size() < START_HAND)
			player.draw_card();

		for(Card* card : player.get_hand()->get_vector()) {
			// TODO Only adds to the display console if it is not already
			if(!display.contains(card->get_image()))
				display.add_image(card->get_image());
		}

		/* "End Turn" */
	    opponent.set_mana(player.get_life());
		
		// start AI's turn
		if(players == "single")
			sp_update();
		
		// start opponenets turn
		else if(players == "multi")
			mp_update();
    }
}

/*
 * TODO Single player logic here
 * This will be where the AI takes their turn
 */
void Game::sp_update() {
	myTurn = false;
    draw();

	// This is where the AI takes their turn
	if(opponent.get_mana() > 0 && opponent.get_hand()->size() > 0) {
        opponent.cast(/* TODO Opponent casts card here */ 0);
    	sp_update();
    } else {
        /* "Combat phase" */
		// TODO

        /* "Draw phase" */
		// if at starting hand only draw one card
        if(opponent.get_hand()->size() > START_HAND)
			opponent.draw_card();
		// draw cards until you are back to starting limit
        while(opponent.get_hand()->size() < START_HAND)
			opponent.draw_card();
    }
    
	/* "End Turn" */
	player.set_mana(opponent.get_life());
	
	// start the players turn
	update();
}

/*
 * Multiplayer game works here
 * This will be where the opponent takes their turn
 */
void Game::mp_update() {
	myTurn = false;
	draw();

	/* "Start Turn" */
	// TODO

	/* "Combat phase" */
	// TODO

    /* "Draw phase" */
	// TODO

	/* "End Turn" */
	player.set_mana(opponent.get_life());
	
	// start the players turn
	update();
}

/*
 * TODO Draw the board state and players hand here.
 * any animations should happen here, as this method
 * is called at the start of every update call.
 */
void Game::draw() {
	 display.print();
}
