/*
 * rectangle.cpp
 *
 *  Created on: June 12, 2016
 *      Author: Tumblr
 */

#include "rectangle.h"

/*
 * Default Rectangle constructor
 */
Rectangle::Rectangle(){
    height = 0;
    width = 0;  
}

/*
 * Creates a width x height Rectangle at the point (0, 0)
 */
Rectangle::Rectangle(size_t width, size_t height){
    this->width = width;
    this->height = height;
}

/*
 * Creates an width x height Rectangle at the Point (x, y)
 */
Rectangle::Rectangle(int x, int y, size_t width, size_t height) {
    set_pos(x,y);
    this->width = width;
    this->height = height;
}

/*
 * Creates a 1x1 rect at the given Point pnt
 */
Rectangle::Rectangle(Point pnt) {
    set_pos(pnt);
    width = 1;
    height = 1;
}

/*
 * Rectangle clone constructor
 */ 
Rectangle::Rectangle(const Rectangle &clone) {
    width = clone.width;
    height = clone.height;
    set_x(clone.get_x());
    set_y(clone.get_y());
    // TODO Clone Map
}

/*
 * Default Rectangle destructor
 */
Rectangle::~Rectangle() {
    
}

/*
 * Returns true if the Point at (x_coord, y_coord) falls within this Rectangle.
 */
bool Rectangle::contains(int x_coord, int y_coord) {
    if ((get_x() < x_coord && x_coord <= (int)(get_x() + width)) && (get_y() < y_coord && y_coord <= (int)(get_y() + height))) return true;

    return false;
}

/*
 * Returns true if the whole Rectangle at (x_coord, y_coord) with the
 * dimensions width x height falls within this Rectangle.
 */
bool Rectangle::contains(int x_coord, int y_coord, size_t width, size_t height) {
    if ((get_x() < x_coord && x_coord <= (int)(get_x() + this->width)) && (get_y() < y_coord && y_coord <= (int)(get_y() + this->height)))
    {
        if ((get_x() < x_coord + width && x_coord + width <= (int)(get_x() + this->width)) && (get_y() < y_coord + height && y_coord + height <= (int)(get_y() + this->height))) return true;
        else return false;
    }    
    return false;
}

/*
 * Returns true if the Point pnt falls within this Rectangle.
 */
bool Rectangle::contains(Point pt) {
    if ((get_x() < pt.get_x() && pt.get_x() <= (int)(get_x() + width)) && (get_y() < pt.get_y() && pt.get_y() <= (int)(get_y() + height))) return true;
    return false;
}

/*
 * Returns true if the whole Rectangle ret falls within this Rectangle
 */
bool Rectangle::contains(Rectangle rect) {
    if ((get_x() < rect.get_x() && rect.get_x() <= (int)(get_x() + this->width)) && (get_y() < rect.get_y() && rect.get_y() <= (int)(get_y() + this->height)))
    {
        if ((get_x() < rect.get_x() + rect.width && rect.get_x() + rect.width <= (int)(get_x() + this->width)) && (get_y() < rect.get_y() + rect.height && rect.get_y() + rect.height <= (int)(get_y() + this->height))) return true;
        else return false;
    }    
    return false;
}

/*
 * Returns true if any part of the Rectangle ret falls within this Rectangle
 */
bool Rectangle::intersects(Rectangle rect) {
    if((get_x() + width >= rect.get_x() && get_x() < rect.get_x() + rect.width) || (rect.get_x() + rect.width > get_x() && rect.get_x() <= get_x() + width))
    {
        if((get_y() + height >= rect.get_y() && get_y() < rect.get_y() + rect.height) || (rect.get_y() + rect.width > get_y() && rect.get_y() <= get_y() + width)) return true;
        return false;
    }
    return false;
}

/*
 * Returns true if this Rectangle and the given Rectangle rect are equal in every way.
 */
bool Rectangle::equals(Rectangle rect) {
    if(get_x() == rect.get_x() && get_y() == rect.get_y() && this->width == rect.width && this->height == rect.height) return true;
    return false;
}

/*
 * Transforms this Rectanle to be dimensions width x height at the
 * Point (x_coord, y_coord)
 */
void Rectangle::set_bounds(int x_coord, int y_coord, size_t width, size_t height) {
    set_x(x_coord);
    set_y(y_coord);
    this->width = width;
    this->height = height;
}

/*
 * Returns a Rectangle representing the intersection between
 * this Rectangle and the given Rectangle rect
 */
Rectangle Rectangle::get_intersection(Rectangle rect) {
    Rectangle ret;
    // TODO
    return ret;
}

/*
 * Returns a Rectangle representing the union between
 * this Rectangle and the given Rectangle rect
 */
Rectangle Rectangle::get_union(Rectangle rect) {
    Rectangle ret;
    // TODO
    return ret;
}

/*
 * Returns the (x, y) position of this Rectangle
 */
Point Rectangle::get_location()  {
    Point ret;
    ret.set_location(get_x() , get_y());
    return ret;
}

/*
 * Sets the position of this Rectangle to the Point (x_coord, y_coord)
 */
void Rectangle::set_location(int x_coord, int y_coord) {
    set_x(x_coord);
    set_y(y_coord);
}

/*
 * Sets the position of this Rectangle to the Point pnt
 */
void Rectangle::set_location(Point pnt) {
    set_x(pnt.get_x());
    set_y(pnt.get_y());
}

/*
 * Sets the dimensions of this Rectangle to width x height
 */
void Rectangle::set_size(size_t width, size_t height) {
    this->width = width;
    this->height = height;
}

/*
 * Moves this Rectangle by dx in the x direction and dy in the
 * y direction. The position of this Rectangle becomes the
 * Point (x + dx, y + dy).
 */
void Rectangle::translate(int dx, int dy) {
    set_x(get_x() + dx);
    set_y(get_y() + dy);
}