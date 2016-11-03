/*
 * deck.h
 *
 *  Created on: Mar 13, 2016
 *      Author: Tumblr
 */

#ifndef SRC_DECK_H_
#define SRC_DECK_H_

#include <vector>
#include "card.h"

class Deck {
private:
	std::vector<Card*> deck;
	std::string deckName;
	size_t* count;
	bool well_formed();
	bool print_err(std::string err);
public:
	Deck();
	Deck(std::string name);
	Deck(const Deck &clone);
	virtual ~Deck();
	Card* draw_card();
	Card* get_card(size_t index);
	Deck draw_cards(int num);
	Deck* operator=(const Deck *clone);
	Deck& operator=(const Deck &clone);
	std::string get_name() const;
	void shuffle();
	bool add_card(Card* card);
	bool add_card(Card* card, size_t index);
	size_t size() const { return *count; }
	std::string to_file();
	std::string to_string() const;
	std::vector<Card*> get_vector() const { return deck; }
};

#endif /* SRC_DECK_H_ */
