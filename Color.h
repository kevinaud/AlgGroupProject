/**
* Authors: Kevin Aud|Jesse McNicoll|Connor Blandin|Jackson Swenson
* Assignment Title: Group Project
* Assignment Description: This header file contains the function prototypes for
*	the Color class
* Due Date: 5/1/2017
* Date Created: 4/28/2017
* Date Last Modified: 5/1/2017
*/
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class Color {
  public:
    Color(){
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }
    Color(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    int r;
    int g;
    int b;
};

namespace COLOR {
    const Color BLACK(0, 0, 0);
    const Color WHITE(255,255,255);
    const Color RED(255, 0, 0);
    const Color GREEN(0, 255, 0);
    const Color BLUE(0, 0, 255);
    const Color PURPLE(128,66,244);
    const Color ORANGE(232,116,0);
    const Color PINK(255,192,203);
}

#endif
