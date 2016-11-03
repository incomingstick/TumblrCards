/*
 * point.cpp
 *
 *  Created on: June 12, 2016
 *      Author: Tumblr
 */

#include <string>
#include <sstream>
#include "point.h"

using namespace std;

/*
 * Default Point constructor
 */
Point::Point() {
    x = 0;
    y = 0;
}

/*
 * Creates a Point with the given coordinates (x_coord, y_coord)
 */
Point::Point(int x_coord, int y_coord) {
    x = x_coord;
    y = y_coord;
}

/*
 * Point clone constructor 
 */
Point::Point(const Point& clone) {
    x = clone.x;
    y = clone.y;
}

/*
 * Default Point destructor
 */
Point::~Point() {
    // nothing to do
}

/*
 * Checks if this point is equal to the given Point pnt.
 */
bool Point::equals(Point pnt) {
    if(pnt.x == x && pnt.y == y){
        return true;
    }
    return false;
}

/*
 * Returns the position of this Point as a Point.
 */
Point Point::get_location() {
    Point ret;
    ret.x = x;
    ret.y = y;
    return ret;
}

/*
 * Sets this point's coordinates equals to that of the
 * given Point (x_coord, y_coord).
 */
void Point::set_location(int x_coord, int y_coord) {
    x = x_coord;
    y = y_coord;
}

/*
 * Sets this point's coordinates equals to that of the
 * given Point pnt.
 */
void Point::set_location(Point pnt) {
    x = pnt.x;
    y = pnt.y;
}

/*
 * Returns this Point as a string in the format (x, y).
 */
string Point::to_string() {
   string ret;
	ret += "(";
	ret += std::to_string(x);
	ret += ",";
	ret += std::to_string(y);
	ret += ")";

	return ret;
}
/*
 * Moves this Point by dx in the x direction and dy in the
 * y direction. The position of this Point becomes
 * (x + dx, y + dy).
 */
void Point::translate(int dx, int dy) {
    x = x + dx;
    y = y + dy;
}
