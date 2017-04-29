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
}

#endif
