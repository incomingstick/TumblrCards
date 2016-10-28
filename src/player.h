/*
 * player.h
 *
 *  Created on: Mar 28, 2016
 *      Author: Tumblr
 */

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include "deck.h"

class Player {
private:
	Deck deck;
	Deck hand;
	Deck board;
	Deck discard;
	int life;
	int mana;
public:
	Player();
	virtual ~Player();
	bool select_deck(Deck selected);
	int deck_size() { return hand.size(); }
	int hand_size() { return deck.size(); }
	int get_life() { return life; }
	int get_mana() { return mana; }
	void set_mana(int num) { mana = num; }
	Deck* get_hand() { return &hand; }
	Deck* get_deck() { return &deck; }
	Deck* get_board() { return &board; }
	Deck* get_discard() { return &discard; }
	bool draw_card();
	bool cast(size_t cardIndex);
};

#endif /* SRC_PLAYER_H_ */
