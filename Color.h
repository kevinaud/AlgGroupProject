#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class Color {
  public:
    static const Planet MERCURY;
    static const Planet VENUS;
    // ...

  private:
    double mass;   // in kilograms
    double radius; // in meters

  private:
    Planet(double mass, double radius) {
        this->mass = mass;
        this->radius = radius;
    }

  public:
    // Properties and methods go here
};

#endif
