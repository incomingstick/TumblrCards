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
    // TODO
}

/*
 * Creates a width x height Rectangle at the point (0, 0)
 */
Rectangle::Rectangle(size_t width, size_t height){
    // TODO
}

/*
 * Creates an width x height Rectangle at the Point (x, y)
 */
Rectangle::Rectangle(int x, int y, size_t width, size_t height) {
    // TODO
}

/*
 * Creates a 1x1 rect at the given Point pnt
 */
Rectangle::Rectangle(Point pnt) {
    // TODO
}

/*
 * Rectangle clone constructor
 */
Rectangle::Rectangle(const Rectangle &clone) {
    // TODO
}

/*
 * Default Rectangle destructor
 */
Rectangle::~Rectangle() {
    // TODO
}

/*
 * Returns true if the Point at (x_coord, y_coord) falls within this Rectangle.
 */
bool Rectangle::contains(int x_coord, int y_coord) {
    // TODO
    return false;
}

/*
 * Returns true if the whole Rectangle at (x_coord, y_coord) with the
 * dimensions width x height falls within this Rectangle.
 */
bool Rectangle::contains(int x_coord, int y_coord, size_t width, size_t height) {
    // TODO
    return false;
}

/*
 * Returns true if the Point pnt falls within this Rectangle.
 */
bool Rectangle::contains(Point pt) {
    // TODO
    return false;
}

/*
 * Returns true if the whole Rectangle ret falls within this Rectangle
 */
bool Rectangle::contains(Rectangle rect) {
    // TODO
    return false;
}

/*
 * Returns true if any part of the Rectangle ret falls within this Rectangle
 */
bool Rectangle::intersects(Rectangle rect) {
    // TODO
    return false;
}

/*
 * Returns true if this Rectangle and the given Rectangle rect are equal in every way.
 */
bool Rectangle::equals(Rectangle rect) {
    // TODO
    return false;
}

/*
 * Transforms this Rectanle to be dimensions width x height at the
 * Point (x_coord, y_coord)
 */
void Rectangle::set_bounds(int x_coord, int y_coord, size_t width, size_t height) {
    // TODO
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
    // TODO
    return ret;
}

/*
 * Sets the position of this Rectangle to the Point (x_coord, y_coord)
 */
void Rectangle::set_location(int x_coord, int y_coord) {
    // TODO
}

/*
 * Sets the position of this Rectangle to the Point pnt
 */
void Rectangle::set_location(Point pnt) {
    // TODO
}

/*
 * Sets the dimensions of this Rectangle to width x height
 */
void Rectangle::set_size(size_t width, size_t height) {
    // TODO
}

/*
 * Moves this Rectangle by dx in the x direction and dy in the
 * y direction. The position of this Rectangle becomes the
 * Point (x + dx, y + dy).
 */
void Rectangle::translate(int dx, int dy) {
    // TODO
}
