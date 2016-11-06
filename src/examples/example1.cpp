/*
 * Example 1 testing:
 * 		- get_intersection()
 *		- get_union()
 *		- to_string()
 *		- is_empty()
 *		- is_square()
 *		- is_line()
 *		- enlarge()
 */

#include <iostream>
#include "/home/agalal/develop/cards/TumblrCards/src/console/rectangle.h"

using namespace std;

int main() {
	// Rectangle 1
	Rectangle rect1 = Rectangle(8, 5, 8, 96);

	// Rectangle 2
	Rectangle rect2 = Rectangle(4, 12, 16, 3);

	if ( rect1.intersects(rect2) )
		cout << "Both rectangles intersect\n";
	else
		cout << "Rectangles are not intersecting\n";

	Rectangle rectIntersect = rect1.get_intersection(rect2);

	cout << "Intersection: " << rectIntersect.to_string() << endl;

	Rectangle rectUnion = rect1.get_union(rect2);

	cout << "Union: " << rectUnion.to_string() << endl;

	// Empty Rectangle
	Rectangle rectEmpty = Rectangle(0, 0, 0, 0);
	if ( rectEmpty.is_empty() )
		cout << "Rectangle(0,0,0,0) is empty\n";
	else
		cout << "Rectangle(0,0,0,0) is not Empty\n";

	// Square Rectangle
	Rectangle rectSquare = Rectangle(0, 0, 5, 5);
	if ( rectSquare.is_empty() )
		cout <<"Rectangle(0,0,5,5) is a empty\n";
	else
		cout << "Rectangle(0,0,5,5) is not a empty\n";

	if ( rectSquare.is_square() )
		cout << "Rectangle(0,0,5,5) is a square\n";
	else
		cout << "Rectangle(0,0,5,5) is not a square\n";

	rectEmpty.enlarge(0, 5); // rectEmpty became a line

	if (rectEmpty.is_line())
		cout << "Rectangle(0,0,0,5) is a line\n";
	else
		cout << "Rectangle(0,0,0,5) is a not line\n";


	rectEmpty.enlarge(5, 0); // rectEmpty became a square

	if ( rectEmpty.is_square() )
		cout << "Rectangle(0,0,5,5) is a square\n";
	else
		cout << "Rectangle(0,0,5,5) is not a square\n";

	return 0;
}
