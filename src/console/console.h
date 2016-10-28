/*
 * console.h
 *
 *  Created on: May 2, 2016
 *      Author: Tumblr
 */

#ifndef SRC_CONSOLE_H_
#define SRC_CONSOLE_H_

#include "utils.h"
#include "imageMap.h"

class Console {
private:
    std::vector<std::vector<char>> console;
    std::vector<ImageMap*> images;
public:
	Console();
	virtual ~Console();
    bool add_image(ImageMap* image);
    bool add_image(std::string image_str);
    bool add_image(std::string image_str, int x, int y);
    bool contains(ImageMap* image);
    void print();
    void update();
    void clear();
    size_t get_width() const { return get_console_width(); }
    size_t get_height() const { return get_console_height(); }
};

#endif /* SRC_CONSOLE_H_ */
