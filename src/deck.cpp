/*
 * deck.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: Tumblr
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "deck.h"

using namespace std;

/*
 * Default Deck constructor
 */
Deck::Deck()
	:deckName{ "Test" },
	 count{ new size_t(0) } {
	// TODO Auto-generated constructor stuff
	well_formed();
}

/*
 * Create a new Deck with the given name
 */
Deck::Deck(string name)
	:deckName{ name },
	 count{ new size_t(0) } {
	// TODO Auto-generated constructor stuff
	well_formed();
}

/*
 * Default Deck destructor
 */
Deck::~Deck() {
	// TODO Auto-generated destructor stuff
}

/*
 * Clone constructore Sets all attributes of this
 * Deck to the clone
 */
Deck::Deck(const Deck &clone)
	:deck{ clone.deck },
	 deckName { clone.deckName },
	 count{ new size_t(clone.size()) } {
	// TODO cloning stuff here
	// passes clone's data to here
	well_formed();
}

/*
 * Sets all attriubutes of this Deck to the clone
 * at the given Deck pointer
 */
Deck* Deck::operator=(const Deck* clone) {
	// do set equals operations here
	// set this equal to the clone
	count = new size_t(clone->size());
	deck = clone->deck;
	well_formed();
	return this;
}

/*
 * Sets all attriubutes of this Deck to the clone
 */
Deck& Deck::operator=(const Deck &clone) {
	// do set equals operations here
	// set this equal to the clone
	count = new size_t(clone.size());
	deck = clone.deck;
	well_formed();
	return *this;
}

/*
 * Returns the name of the deck as a string
 */
string Deck::get_name() const {
	return deckName;
}

/* 
 * Removes the top card of the deck and returns it
 * shifting all the cards up one
 */
Card* Deck::draw_card(){
	well_formed();
	if(*count == 0) return nullptr;
	Card* ret = deck[0];
	for(size_t i = 1; i < *count; i++)
		deck[i-1] = deck[i];
	deck.pop_back();
	*count -= 1;
	well_formed();
	return ret;
}

// remove the card at the given index and returns it
// shifting all the cards up one
Card* Deck::get_card(size_t index) {
	well_formed();
	if(*count == 0 || index < 0 || index > *count) return nullptr;
	Card* ret = deck[index];
	for(size_t i = index + 1; i < *count; i++)
		deck[i-1] = deck[i];
	deck.pop_back();
	*count -= 1;
	well_formed();
	return ret;
}

/*
 * remove the top num cards from the deck and returns
 * a "Deck" as the drawn cards. shifts all
 * the cards up num
 */
Deck Deck::draw_cards(int num) {
    Deck ret;
	if(!well_formed()) return ret;

    // draws a card from our deck to add
    // to the return deck;
    for(int i = 0; i < num; i++) {
        ret.add_card(draw_card());
	}
	
	well_formed();
	return ret;
}

/*
 * Simulates the act of shuffling a deck
 */
void Deck::shuffle() {
	if(!well_formed()) return;

	// Traverses through the array swapping each index with a random other index
	for(size_t i = 0; i < *count; i++) {
		size_t r = rand() % *count;
		Card* temp;
		temp = deck[i];
		deck[i] = deck[r];
		deck[r] = temp;
	}
	
	well_formed();
}

/* 
 * Adds a card to the deck and then shuffles the deck
 */
bool Deck::add_card(Card* card) {
	if(!well_formed()) return false;

	// no room to add the card
	if(*count == 20) return print_err("No more room to add a card.");

	// adds the card and increments count
	deck.push_back(card);
	*count += 1;

	return well_formed();
}

/*
 * Adds a card at the specified index. i.e 0 for the top
 */
bool Deck::add_card(Card* card, size_t index) {
	if(!well_formed()) return false;
	
	// index can not be larger than count
	if(index >= *count - 1) return print_err("Index is out of bounds.");

	// no room to add the card
	if(*count == 20) return false;

	// moves all the cards after index down one
	for(size_t i = *count - 1; i > index; i--) {
		deck[i + 1] = deck[i];
	}

	// puts the deck in at index and increments count
	deck[index] = card;
	*count += 1;
	
	well_formed();
	return true;
}

/*
 * checks the integrity of the deck and returns false with an error message
 * if something is wrong. Returns true otherwise.
 * Rules:
 *		A Deck may not be larger than 20 cards
 *		A deck may not have any nullptr between 0 and count
 */
bool Deck::well_formed() {
	// may not be larger than 60 cards
	if(*count > deck.size()) return print_err("Count is larger than 20");
	for(size_t i = 0; i < *count; i++) {
		// checks to make sure count is not larger than the size of the deck
		if(deck[i] == nullptr) return print_err("Count is larger than size of deck");
		
		// COMENTED OUT FOR TESTING
		//int cardCount = 1;
		//for(size_t j = i + 1; j < *count; j++) {
			// adding it here checks the integrity of the array on our first pass
			//if(deck[i] == nullptr) return print_err("Count is larger than size of deck");
			//Card c1 = *deck[i];
			//Card c2 = *deck[j];
			//if(c1.get_name() == c2.get_name()) cardCount++;

			// you may not have more than 2 of any card in a deck
			//if(cardCount > 2) return print_err("You may not have more than 2 of any card");
		//}
	}

	// if the integrity of this data structure is held, returns true
	return true;
}

// prints the error message passed and returns false
bool Deck::print_err(string err) {
	cout << err << endl;
	return false;
}

/*
 * Compares the given cards to check for equlaity
 */
bool equals(Card* a, Card* b) { return (a->get_name() < b->get_name()); }

/*
 * Convers the deck to a deck list file saved in the ../decklists folder 
 */
string Deck::to_file() {
    string ret;
    int num = 1;
    sort(deck.begin(), deck.begin() + *count, equals);
    for(size_t i = 0; i < *count - 1; i++) {
        // case if we are looking at the last 2 cards of the deck
        // this will need to be edited slightly when we enforce
        // card limits
        if(i + 1 >= *count - 1) {
            ret += deck[i]->get_name();
            ret += " X ";
            ret += std::to_string(num+1);
            ret += "\n";
            num = 1;
        }
        // case for if we are looking at the same card as befor
        else if(deck[i]->get_name() == deck[i+1]->get_name()) num++;
        // case for when we have found a new card name
        else {
            ret += deck[i]->get_name();
            ret += " X ";
            ret += std::to_string(num);
            ret += "\n";
            num = 1;
        }
    }
    shuffle();
    return ret;
}

/*
 * Converts the Deck to a string 
 */
string Deck::to_string() const {
    string ret;
	for(size_t i = 0; i < *count; i++) {
		ret += std::to_string(i+1);
		ret += ") ";
		ret += deck[i]->get_name();
		ret += " - ";
		ret += std::to_string(deck[i]->get_cost());
		ret += " ";
	}
	return ret;
}
