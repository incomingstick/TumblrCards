/*
 * imageMap.cpp
 *
 *  Created on: May 2, 2016
 *      Author: Tumblr
 */

#include <string>
#include <vector>
#include <iostream>
#include "imageMap.h"
#include "utils.h"

using namespace std;

/*
 * Default ImageMap constructor with a blank image
 */
ImageMap::ImageMap()
    :x { 0 },
     y { 0 } {
	// TODO Auto-generated constructor stub
	set_image("");
}

/*
 * Creates an ImageMap object with the given image string
 * at the (0, 0) position
 */
ImageMap::ImageMap(string image)
    :x { 0 },
     y { 0 } {
	// TODO Auto-generated constructor stub
	set_image(image);
}

/*
 * Creates an image map object with the given image string
 * at the given (x_pos, y_pos) psoition
 */
ImageMap::ImageMap(string image, int x_pos, int y_pos)
    :x { x_pos },
     y { y_pos } {
	// TODO Auto-generated constructor stub
	set_image(image);
}

/*
 * ImageMap clone constructor
 */
ImageMap::ImageMap(const ImageMap &clone)
    :map { clone.get_map() },
     x { clone.get_x() },
     y { clone.get_y() } {
	// TODO Auto-generated constructor stub
}

/*
 * Defaut ImageMap destructor
 */
ImageMap::~ImageMap() {
	// TODO Auto-generated destructor stub
}

/*
 * Replaces the current image with the given image
 * string.
 */
void ImageMap::set_image(string image) {
    map.clear();
    map.push_back(vector<char>());
    int curr_row = 0;
    for(char& c : image) {
        // TODO parse string in to 2D vector
        if(c == '\n') {
            map.push_back(vector<char>());
            curr_row++;
            continue;
        } else if ((int)c == 13) continue;
        map[curr_row].push_back(c);
    }
}

/*
 * Sets the position of this ImageMap to the Point pnt
 */
void ImageMap::set_pos(Point pnt) {
    x = pnt.get_x();
    y = pnt.get_y();
}

/*
 * Returns true if the rectangle of dimensions width x height and the
 * Point (x_coord, y_coord) intersects this ImageMap object
 */
bool ImageMap::intersects(int x_coord, int y_coord, size_t width, size_t height) {
    // If the given rectangle's point falls within our ImageMap then
    // we must intersect.
    if(x_coord > x && x_coord <= (int)(x + get_width())) return true;
    if(y_coord > y && y_coord <= (int)(y + get_height())) return true;

    // If out upper left corner falls within the given rectangle then
    // we must intersect.
    if(x > x_coord && x <= (int)(x_coord + width)) return true;
    if(y > y_coord && y <= (int)(y_coord + height)) return true;

    // None of the conditions where met so return false.
    return false;
}

/*
 * Returns true if the given ImageMap intersects with this
 * ImageMap object
 */
bool ImageMap::intersects(ImageMap img) {
    return  intersects(img.get_x(), img.get_y(), img.get_width(), img.get_height());
}

/*
 * Replases the flag in the ImageMap with the given
 * text and alignment
 */
void ImageMap::parse_flag(string flag, string text, string align) {
    size_t found = to_string().find(flag);

    // flag string not found
    if(found == string::npos) return;

    int found_y = found / (get_width() + 1);
    int found_x = found - (found_y * (get_width() + 1));

    // Something went wrong???
    //if(map[found_y][found_x] != flag.at(0)) return;

	if(align == "center") {
        // TODO Align the text centered on the flag

        // do left-pad here if smaller than flag
        text = leftpad(text, flag.size());

        found_x = found_x - (text.size() / 2) + (flag.size() / 2);

        for(size_t i = 0; i < text.size(); i++) {
            if(i > map[found_y].size()) break;
            if(found_x + i < 0) continue;

            map[found_y][found_x + i] = text[i];
        }
    } else if(align == "left-pad") {
        // TODO Align the the last char of text with
        // the '}' of the flag adding spaces as needed

        // do left-pad here if smaller than flag
        text = leftpad(text, flag.size());

        for(size_t i = 0; i < text.size(); i++) {
            if(i > map[found_y].size()) break;
            map[found_y][found_x + i] = text[i];
        }
    } else if(align == "right-pad") {
        // TODO Align the the first char of text with
        // the '{' of the flag adding spaces as needed

        // do right-pad here if smaller than flag
        text = rightpad(text, flag.size());

        found_x += flag.size() - 1;

        for(size_t i = 0; i < text.size(); i++) {
            map[found_y][found_x - i] = text[text.size() - i - 1];
        }
    }
}

/*
 * Converts the ImageMap back to a string
 */
string ImageMap::to_string() {
	string ret = "";
	for(vector<char> row : map) {
		for(char& col : row)
			ret = ret + col;
		ret = ret + "\n";
	}
    ret.pop_back();
	return ret;
}

/*
 * Returns true if this ImageMap and the given ImageMap rect are equal in every
 * way.
 */
bool ImageMap::equals(const ImageMap& imagemap)
{
    if(map.size() != imagemap.map.size())
        return false;
    for(vector< vector<char> >::size_type i = 0; i < map.size(); i++)
    {
        if(map[i].size() != imagemap.map[i].size())
            return false;
        for(vector<char>::size_type j = 0; j < map[i].size(); j++)
        {
            if(map[i][j] != imagemap.map[i][j])
                return false;
        }
    }
    return (x == imagemap.x) && (y == imagemap.y);
}
