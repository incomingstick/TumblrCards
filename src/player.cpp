/*
 * player.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: Tumblr
 */

#include "player.h"
#include "utils.h"

/*
 * Default Player constructor
 */
Player::Player()
	:life { 10 },
	 mana { 0 } {
	// TODO Auto-generated constructor stub

}

/*
 * Default Player destructor
 */
Player::~Player() {
	// TODO Auto-generated destructor stub
}

/*
 * Sets the players deck to the selected deck
 */
bool Player::select_deck(Deck selected) {
	deck = selected;
	return true;
}

/*
 * Moves a card from the players deck to the players
 * hand.
 */
bool Player::draw_card() {
    if(deck.size() <= 0) {
        while(discard.size() > 0) {
            deck.add_card(discard.draw_card());
		}
        deck.shuffle();
    }

	Card* temp = deck.draw_card();
	if(temp == nullptr) return false;

	int hand_x = hand.size() * temp->get_image()->get_width();
	int hand_y = get_console_height() - temp->get_image()->get_height();

	temp->get_image()->set_pos(hand_x, hand_y);
	hand.add_card(temp);

    return true;
}

/* 
 * Move the card in the players
 * hand at the given index into the board
 * deck.
 */
bool Player::cast(size_t cardIndex) {
	if(cardIndex >= hand.size()) return false;
	Card* temp = hand.get_card(cardIndex);
	if(temp == nullptr) return false;
	mana -= temp->get_cost();
	board.add_card(temp);
    return true;
}
