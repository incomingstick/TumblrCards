/*
 * player.h
 *
 *  Created on: Mar 28, 2016
 *      Author: Tumblr
 */

#ifndef SRC_IMAGEMAP_H_
#define SRC_IMAGEMAP_H_

#include <vector>
#include <string>
#include "point.h"

class ImageMap {
private:
    std::vector<std::vector<char>> map;
    int x;
    int y;
public:
	ImageMap();
    ImageMap(std::string image);
    ImageMap(std::string image, int x_pos, int y_pos);
    ImageMap(std::string image, Point pnt);
    ImageMap(const ImageMap &clone);
    virtual ~ImageMap();
    std::vector<std::vector<char>> get_map() const { return map; }
    void set_image(std::string image);
    int get_x() const { return x; }
    int get_y() const { return y; }
    size_t get_height() const { return map.size(); }
    size_t get_width() const { return map[0].size(); }
    void set_x(int new_x = 0) { x = new_x; }
    void set_y(int new_y = 0) { y = new_y; }
    void set_pos(int new_x, int new_y) { set_x(new_x); set_y(new_y); }
    void set_pos(Point pnt);
    bool intersects(int x_coord, int y_coord, size_t width, size_t height);
    bool intersects(ImageMap img);
    std::string to_string();
	void parse_flag(std::string flag = "{0}",
                    std::string text = "",
                    std::string align = "center");
};

#endif /* SRC_IMAGEMAP_H_ */

