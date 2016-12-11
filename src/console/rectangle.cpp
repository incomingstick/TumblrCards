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
Rectangle::Rectangle() : ImageMap(),
    width(0),
    height(0) {
}

/*
 * Creates a width x height Rectangle at the point (0, 0)
 */
Rectangle::Rectangle(size_t width, size_t height) : ImageMap(),
    width(width),
    height(height) {

}

/*
 * Creates an width x height Rectangle at the Point (x, y)
 */
Rectangle::Rectangle(int x, int y, size_t width, size_t height)
    : ImageMap("", x, y),
      width(width),
      height(height) {

}

/*
 * Creates a 1x1 rect at the given Point pnt
 */
Rectangle::Rectangle(Point pnt)
    : ImageMap("", pnt.get_x(), pnt.get_y()), width(1), height(1) {

}

/*
 * Rectangle clone constructor
 */
Rectangle::Rectangle(const Rectangle &clone)
    : ImageMap(dynamic_cast<const ImageMap&>(clone)),
      width(clone.width),
      height(clone.height) {
}

/*
 * Default Rectangle destructor
 */
Rectangle::~Rectangle() {
    // Does nothing yet
}

/*
 * Returns true if the Point at (x_coord, y_coord) falls within this Rectangle.
 */
bool Rectangle::contains(int x_coord, int y_coord) {
    return (x_coord >= get_x()) && (x_coord <= (get_x() + width))
        && (y_coord >= get_y()) && (y_coord <= (get_y() + height));
}

/*
 * Returns true if the whole Rectangle at (x_coord, y_coord) with the
 * dimensions width x height falls within this Rectangle.
 */
bool Rectangle::contains(int x_coord, int y_coord, size_t width, size_t height) {
    return (x_coord >= get_x())
        && (y_coord >= get_y())
        && ((x_coord + width) <= (get_x() + this->width))
        && ((y_coord + height) <= (get_y() + this->height));
}

/*
 * Returns true if the Point pnt falls within this Rectangle.
 */
bool Rectangle::contains(Point pt) {
    return contains(pt.get_x(), pt.get_y());
}

/*
 * Returns true if the whole Rectangle ret falls within this Rectangle
 */
bool Rectangle::contains(Rectangle rect) {
    return contains(rect.get_x(), rect.get_y(), rect.width, rect.height);
}

/*
 * Returns true if any part of the Rectangle ret falls within this Rectangle
 */
bool Rectangle::intersects(Rectangle rect) {
    return (rect.get_x() <= (get_x() + width))
        && (rect.get_y() <= (get_y() + height))
        && ((rect.get_x() + rect.width) >= get_x())
        && ((rect.get_y() + rect.height) >= get_y());
}

/*
 * Returns true if this Rectangle and the given Rectangle rect are equal in every way.
 */
bool Rectangle::equals(Rectangle rect) {
    return (dynamic_cast<ImageMap&>(*this).equals(static_cast<const ImageMap&>(rect)))
        && (rect.width == width)
        && (rect.height == height);
}

/*
 * Transforms this Rectanle to be dimensions width x height at the
 * Point (x_coord, y_coord)
 */
void Rectangle::set_bounds(int x_coord, int y_coord, size_t width, size_t height) {
    this->width = width;
    this->height = height;
    set_x(x_coord);
	set_y(y_coord);
}

/*
 * Returns a Rectangle representing the intersection between
 * this Rectangle and the given Rectangle rect
 */
Rectangle Rectangle::get_intersection(Rectangle rect) {
    if(!intersects(rect))
        return Rectangle(0, 0, 0, 0);

    int x1, y1, x2, y2;

    x1 = rect.get_x() >= get_x() ? rect.get_x() : get_x();
    y1 = rect.get_y() >= get_x() ? rect.get_y() : get_y();

    x2 = rect.get_x() + rect.width >= get_x() + width ? get_x() + width : rect.get_x() + rect.width;
    y2 = rect.get_y() + rect.height >= get_y() + height ? get_y() + height : rect.get_y() + rect.height;

    return Rectangle(x1, y1, x2-x1, y2-y1);
}

/*
 * Returns a Rectangle representing the union between
 * this Rectangle and the given Rectangle rect
 */
Rectangle Rectangle::get_union(Rectangle rect) {
    int x1, y1, x2, y2;

    x1 = rect.get_x() < get_x() ? rect.get_x() : get_x();
    y1 = rect.get_y() < get_x() ? rect.get_y() : get_y();

    x2 = rect.get_x() + rect.width < get_x() + width ? get_x() + width : rect.get_x() + rect.width;
    y2 = rect.get_y() + rect.height < get_y() + height ? get_y() + height : rect.get_y() + rect.height;

    return Rectangle(x1, y1, x2-x1, y2-y1);
}

/*
 * Returns the (x, y) position of this Rectangle
 */
Point Rectangle::get_location()  {
    Point ret;
    ret.set_location(get_x(), get_y());
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
    set_location(pnt.get_x(), pnt.get_y());
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

/*
 * Returns the height of this Rectangle
 */
size_t Rectangle::get_height() {
    return height;
}

/*
 * Returns the width of this Rectangle
 */
size_t Rectangle::get_width() {
    return width;
}

/*
 * Sets the height of this Rectangle
 */
void Rectangle::set_height(size_t height) {
    this->height = height;
}

/*
 * Sets the width of this Rectangle
 */
void Rectangle::set_width(size_t width) {
    this->width = width;
}

/*
 * Return true if this Rectangle is both the height and the width are zeros
 */
bool Rectangle::is_empty() {
    if (get_height() == 0 && get_width() == 0)
        return true;

    return false;
}

/*
 * Returns true if this Rectangle is not empty
 * and its width is equal to its height
 */
bool Rectangle::is_square() {
    if (!is_empty() && width == height )
        return true;
    
    return false;
}

/*
 * Enlarges this Rectangle in width by the amount dwidth
 * and in height by the amount dheight
 */
void Rectangle::enlarge(int dwidth, int dheight) {
    set_width(get_width() + dwidth);
    set_height(get_height() + dheight);
}

/*
 * Returns true if the width or the height, but not both, of this Rectangle is zero
 */
bool Rectangle::is_line() {
    if(!is_empty() && (width == 0 || height == 0))
        return true;

    return false;
}

/*
 * Returns this Rectangle as a string in the format (x, y) & (width, height).
 */
std::string Rectangle::to_string() {
    std::string ret;

    ret += "(";
    ret += std::to_string(get_x());
    ret += ", ";
    ret += std::to_string(get_y());
    ret += ") & (";
    ret += std::to_string(width);
    ret += ", ";
    ret += std::to_string(height);
    ret += ")";

    return ret;
}