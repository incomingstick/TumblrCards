/*
 * deckBuilder.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: Tumblr
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include "dirent.h"
#include "deckBuilder.h"
#include "utils.h"

using namespace std;

/*
 * Default DeckBuilder constructor
 */
DeckBuilder::DeckBuilder()
    :selected(0) {
	// TODO Auto-generated constructor stub
	load_decklists();
}

/*
 * Default DeckBuilder destructor
 */
DeckBuilder::~DeckBuilder() {
	// TODO Auto-generated destructor stub
}

/*
 * Gets the file names of all .lst files in the
 * ../decklists folder
 */
bool DeckBuilder::load_decklists() {
    DIR* dir;
	struct dirent *ent;

	// proceeds only if direcotry is opened
	if ((dir = opendir ("../decklists/")) != NULL) {
		// gets name of each file
	    while ((ent = readdir (dir)) != NULL) {
	        string name = ent->d_name;

			//checks if the file is a .lst file
	        if (name.find(".lst") != std::string::npos)
                load_deck(ent->d_name);
        }
        return true;
	} else return false;
}

/*
 * Loads the deck in from the given .lst file
 */
bool DeckBuilder::load_deck(std::string file) {
    ifstream deck_file("../decklists/"+file);

	// proceed if file is opened
    if(deck_file.is_open()) {
		
		// creates a deck of the given file name
        Deck* deck = new Deck(file.substr(0, file.find(".lst")));

		// confirms the deck does not already exist
        for(Deck* check : list)
            if(deck->get_name() == check->get_name())
                return true;

		// string to hold each line of the decklist
        string line;

		// loads in each line of the deck list
		// Each line should look as follows:
		// Card Name X [Number of cards to add]
		// i.e: Uninformed Citizen X 2
		// See premade.lst for a full example list
        while(getline(deck_file, line)) {
            int num;
            stringstream ss;

			// Gets the number of cards to add
            ss << line.substr(line.find('X')+1);
            ss >> num;

			// Adds a card of the given name for each num
            for(int i = 0; i < num; i++) {
                Card* card = new Card();
                card->build_card(line.substr(0, line.find('X')-1));
                deck->add_card(card);
            }
        }

		// adds the new deck to the end of the list
        list.push_back(deck);

		// sets the selected deck to the last created deck
		// We should have this be a saved value so the last
		// selected deck is the first selected deck when the
		// game starts
        selected = list.size() - 1;

    } else return false;
	
    return true;
}

/*
 * Saves the passed deck as a .lst file in the ../decklists folder
 */
bool DeckBuilder::save_deck(Deck deck) {
	// opens the file stream to the .lst file with the decks name
    ofstream save("../decklists/"+deck.get_name()+".lst");

	// proceed to write the deck to the file
    if(save.is_open()){
        save << deck.to_file();
    } else return false;

	// Close the file and inform the user of a successful save
    save.close();
    cout << "Deck Saved!" << endl;

    return true;
}

/*
 * This method creates a new deck and then saves it
 */
void DeckBuilder::new_deck() {

	// Prompt user for name of new deck
	print_center("Enter new deck name: ");
	
	string name;
	string in;

	// Need to parse user input here to exclude special characters
	cin >> name;

	// Counter to check when we reach the end of our list of decks
	size_t i = 0;

	// Checks to see if the entered name already matches a deck
	for(Deck* deck : list) {
		// If the deck already exists, we ask to overwrite the deck list
	    if(name == deck->get_name()) {
	        cout << "Deck " << name << " already exists! " << deck->get_name() << endl;
	        cout << "Would you like to overwrite (y or n)? ";
	        cin >> in;

			// Overwrite the deck
	        if(in == "y" || in == "yes") {
	            deck = new Deck(name);
	        	selected = i;
	        	break;
	        }
			// User declined overwrite, so print menu system
			else {
	        	do print_menu("screen_builder");
	            while(!get_input());
	            return;
	        }
	    }

		// Did not find the deck in our list
		// adds deck to list and makes it the
		// selected deck
		else if(i + 1 >= list.size()) {
	        list.push_back(new Deck(name));
	        selected = list.size() - 1;
	    }
	    i++;
	}

	// Generates a testing deck until we have cards working
	// TODO once cards are working this should move us to the
	// deck editor
	cout << "I would do card selection stuff here." << endl;
	cout << "Building you a temp deck for testing." << endl;
	while(list[selected]->size() < 20) {
	    Card* temp = new Card();
	    if(list[selected]->size() % 2 == 0) {
	        temp->build_card("Test1");
		}
	    if(list[selected]->size() % 3 == 0) {
	        temp->build_card("Test2");
		}
	    if(list[selected]->size() % 4 == 0) {
	        temp->build_card("Test3");
		}
		list[selected]->add_card(temp);
	}
	
	// Attempts to save the deck and prints error if failed
	if(!save_deck(*list[selected]))
	    cout << list[selected]->get_name() << " could not be saved." << endl;

	// prints carriage return
	cout << endl;
	
	// prints menu system
	do print_menu("screen_builder");
	while(!get_input());
}

/*
 * Sets the selected deck to be used in games
 */
void DeckBuilder::select_deck() {
	clear_console();
	if(!list.empty()) {
		size_t i = 1;
		for(Deck* deck : list) {
			if(i - 1 == selected) cout << '*';
			else cout << " ";
			cout << i++ << ") " << deck->get_name() << endl;
		}
		cout << "Select your primary deck: ";
		cin >> selected;
		if(selected < 1 || selected > list.size()) {
			selected = 1;
		}
		selected--;
	} else cout << "You don't have any decks!" << endl;

	do print_menu("screen_builder");
	while(!get_input());
}

/*
 * Opens the deck editor on the selected deck
 */
void DeckBuilder::edit_selected() {
	// TODO This should be code for the deck editor
	// this just prints out the deck list for now.
    clear_console();
    if(list[selected] != nullptr)
	    cout << list[selected]->to_file() << endl;
	do print_menu("screen_builder");
	while(!get_input());
}

/*
 * Takes in the players input for the menu system
 */
bool DeckBuilder::get_input() {
	// TODO take in the players selection and call that method.
	int selection = 5;
	stringstream ss;
	string in;
	cin >> in;
	ss << in;
	ss >> selection;
	switch(selection) {
		case 1:
			new_deck();
			break;
		case 2:
			select_deck();
			break;
		case 3:
			edit_selected();
			break;
		case 4:
			// TODO anything need to be done before we exit?
			break;
		default:
			cout << in << " is not a valid option." << endl;
			return false;
	}
	return true;
}

/*
 * Returns a pointer to the selected deck
 */
const Deck* DeckBuilder::get_selected() {
	if(!list.empty())
		return list[selected];
	else
		return nullptr;
}
