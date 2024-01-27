#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "main.h"

using namespace std;

/**
 * The main function that prints out "Hello World!" and performs various
 * operations with rectangles and circles.
 *
 * @return 0 indicating successful execution
 *
 * @throws None
 */
int main()
{
    // Create a rectangle object with width and height both set to 5
    Rectangle r(5, 5);

    // Create a circle object with radius 1 and color "blue"
    Circle c(1, "blue");

    // Print area and perimeter of the 5x5 rectangle
    cout << "Area and perimeter of 5x5 rectangle\n";
    cout << r.Area() << '\n';
    cout << r.Perimeter() << '\n';

    // Print area and perimeter of the circle with radius 1
    cout << "Area and perimeter of circle with radius 1\n";
    cout << c.Area() << '\n';
    cout << c.Perimeter() << '\n'
         << '\n';

    // Create an array of 5 rectangle objects
    Rectangle rectangles[5];

    // Loop to input length and width for each rectangle
    for (int i = 0; i < 5; i++)
    {
        cout << "rectangle " << i << '\n';
        double len;
        double wid;
        cout << "enter length: ";
        cin >> len;
        rectangles[i].setLength(len); // Set length for the current rectangle
        cout << "enter width: ";
        cin >> wid;
        rectangles[i].setWidth(wid); // Set width for the current rectangle
    }

    // Print the greatest area among the input rectangles
    cout << "\ngreatest area:";
    cout << greatestArea(rectangles, 5);

    return 0;
}

/**
 * Calculate the greatest area among the given rectangles.
 *
 * @param r an array of Rectangle objects
 * @param len the length of the array
 *
 * @return the greatest area among the rectangles
 *
 * @throws None
 */
double greatestArea(Rectangle r[], int len)
{
    // Initialize max area with the area of the first rectangle
    double max = r[0].Area();

    // Iterate through the array to find the greatest area
    for (int i = 1; i < len; i++)
    {
        double area = r[i].Area();
        max = (max > area) ? max : area;  // Update max if the current area is greater
    }
    return max;  // Return the greatest area
}
