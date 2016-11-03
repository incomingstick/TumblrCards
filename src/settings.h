/*
 * settings.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Tumblr
 */

#ifndef SRC_SETTINGS_H_
#define SRC_SETTINGS_H_

/*
 * TODO This will only be a temporary way of handling the
 * game settings. After doing some research we may want
 * to look at using LUA for a number of things. Including
 * a settings config file. Until someone decides to make
 * that upgrade this will be what is used for now.
 */
class Settings {
private:
    int dispHeight;
    int dispWidth;

    std::string tempIPVar; /* TODO This variable is a teporary.The
                              IP of the multiplayer sever will
                              go here. */

    std::string keyboard;

	bool load_settings();
	bool save_settings();
public:
	Settings();
	virtual ~Settings();
	bool get_input();
};

#endif /* SRC_SETTINGS_H_ */
