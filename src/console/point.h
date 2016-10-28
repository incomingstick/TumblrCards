/*
 * point.h
 *
 *  Created on: June 12, 2016
 *      Author: Tumblr
 */

#ifndef SRC_POINT_H_
#define SRC_POINT_H_

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int x_coord, int y_coord);
    Point(const Point& clone);
    virtual ~Point();
    bool equals(Point pnt);
    Point get_location();
    int get_x() { return x; }
    int get_y() { return y; }
    void set_location(int x_coord, int y_coord);
    void set_location(Point pnt);
    std::string to_string();
    void translate(int dx, int dy);
};

#endif /* SRC_POINT_H_ */
