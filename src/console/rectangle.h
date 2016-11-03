
/*
 * rectangle.h
 *
 *  Created on: June 12, 2016
 *      Author: Tumblr
 */

#ifndef SRC_RECTANGLE_H_
#define SRC_RECTANGLE_H_

#include "imageMap.h"

class Rectangle: public ImageMap {
private:
    size_t height;
    size_t width;
public:
    Rectangle();
    Rectangle(size_t width, size_t height);
    Rectangle(int x, int y, size_t width, size_t height);
    Rectangle(Point pnt);
    Rectangle(const Rectangle &clone);
    virtual ~Rectangle();
    bool contains(int x_coord, int y_coord);
    bool contains(int x_coord, int y_coord, size_t width, size_t height);
    bool contains(Point pt);
    bool contains(Rectangle rect);
    bool intersects(Rectangle rect);
    virtual bool equals(Rectangle rect);
    void set_bounds(int x_coord, int y_coord, size_t width, size_t height);
    Rectangle get_intersection(Rectangle rect);
    Rectangle get_union(Rectangle rect);
    Point get_location();
    void set_location(int x_coord, int y_coord);
    void set_location(Point pnt);
    void set_size(size_t width, size_t height);
    void translate(int dx, int dy);
};

#endif /* SRC_RECTANGLE_H_ */
