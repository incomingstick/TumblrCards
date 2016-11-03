/*
 * card.h
 *
 *  Created on: Mar 7, 2016
 *      Author: Tumblr
 */

#ifndef SRC_CARD_H_
#define SRC_CARD_H_

#include <string>
#include "imageMap.h"

class Card {
private:
	int attack;
	int health;
	int currHP;
	int cost;
	std::string name;
	std::string ability;
	ImageMap image;
public:
	Card();
	virtual ~Card();

	// build card base on input from file
	void build_card(std::string arg);

	// should return true if the trigger goes off
	// false if it does not
	bool trigger();

	// prints the card in the form:
	// Name
	// Description
	// Atk / HP
	std::string to_string();

	// these will need to be edited later
	// to handle effects from other cards
	// as well as during combat
	int get_atk() { return attack; }
	int get_hp() { return currHP; }
	int get_cost() { return cost; };
	std::string get_name() { return name; }
	ImageMap* get_image() { return &image; };
};

#endif /* SRC_CARD_H_ */
