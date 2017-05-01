#include <algorithm>
#include <cmath>

#include "SDL_Plotter.h"
#include "Color.h"

#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

class Point {
public:
    int x; // x location of point
    int y; // y location of point
    Color color = COLOR::BLACK; // plotter color

	/****************************************************
	 * description: default constructor
	 * return: none 
	 * precondition: none
	 * postcondition: none
	 ***************************************************/
    Point();

	/****************************************************
	 * description: constructor
	 * return: none 
	 * precondition: none
	 * postcondition: x and y are set to the values that
	 * 	were passed in
	 ***************************************************/
    Point(int, int);

	/****************************************************
	 * description: copy constructor
	 * return: none 
	 * precondition: none
	 * postcondition: all attributes of this point are 
	 * 	equal to the attributes of the point that was
	 * 	passed in
	 ***************************************************/
    Point(const Point&);

	/****************************************************
	 * description: overloaded equality operator
	 * return: boolean 
	 * precondition: none
	 * postcondition: returns true if both points have
	 * 	the same x and y values
	 ***************************************************/
    bool operator==(const Point &other) const;

	/****************************************************
	 * description: color setter
	 * return: none 
	 * precondition: none
	 * postcondition: color attribute is updated
	 ***************************************************/
    void setColor(Color color);

	/****************************************************
	 * description: draws a point at the x and y
	 * 	location of this point
	 * return: none 
	 * precondition: none
	 * postcondition: a point was drawn at that location
	 * 	using the plotter
	 ***************************************************/
    void draw(SDL_Plotter&);
};

class Line {
public:
    Point p1; // first point
    Point p2; // second point
    int stroke = 1; // line thickness
    Color color = Color(0, 0, 0); // color of line
	
	/****************************************************
	 * description: creates a new line between the two
	 * 	points that are passed in
	 * return: none 
	 * precondition: none
	 * postcondition: the two points that are passed in
	 * 	are stored
	 ***************************************************/
    Line(Point, Point);

	/****************************************************
	 * description: draws a line on these screen between
	 * 	the two points of the line
	 * return: none 
	 * precondition: none
	 * postcondition: a line was drawn on the plotter
	 ***************************************************/
    void draw(SDL_Plotter&);

	/****************************************************
	 * description: draws a line between the two points
	 * 	of this line and offsets the line based on the
	 * 	point that was passed in
	 * return: none 
	 * precondition: none
	 * postcondition: a line was drawn on the plotter
	 ***************************************************/
    void offsetDraw(SDL_Plotter&, Point);

	/****************************************************
	 * description: color setter
	 * return: none 
	 * precondition: none
	 * postcondition: color was updated
	 ***************************************************/
    void setColor(Color color);

	/****************************************************
	 * description: stroke setter
	 * return: none
	 * precondition: none
	 * postcondition: stroke was updated
	 ***************************************************/
    void setStroke(int);
};

class Rectangle {
public:
    Point loc; // top left corner of rectangle
    int width; // width of rectangle
    int height; // height of rectangle
    Color color = COLOR::BLACK; // fill color

	/****************************************************
	 * description: constructor
	 * return: none 
	 * precondition: none
	 * postcondition: attributes are set
	 ***************************************************/
    Rectangle(Point, int, int);

	/****************************************************
	 * description: draws a rectangle on the screen
	 * return: none 
	 * precondition: none
	 * postcondition: rectangle is drawn on the screen
	 ***************************************************/
    void draw(SDL_Plotter&);

	/****************************************************
	 * description: color setter
	 * return: none 
	 * precondition: none
	 * postcondition: color is updated
	 ***************************************************/
    void setColor(Color);
};

class Circle{
public:
    Point center; // center location of the circle
    int radius; // radius of circle
    bool filled; // whether or not the circle is filled
    Color color = COLOR::BLACK; // color of circle

	/****************************************************
	 * description: constructor
	 * return: none 
	 * precondition: none
	 * postcondition: attributes are set
	 ***************************************************/
    Circle(Point,int);

	/****************************************************
	 * description: draws the circle to the screen
	 * return: none 
	 * precondition: none
	 * postcondition: circle was drawn to the screen
	 ***************************************************/
    void draw(SDL_Plotter&);

	/****************************************************
	 * description: color setter
	 * return: none 
	 * precondition: none
	 * postcondition: color was updated
	 ***************************************************/
    void setColor(Color);
};

#endif // SHAPES_H_INCLUDED
