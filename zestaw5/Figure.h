#ifndef FIGURE_H
#define FIGURE_H

#include "Canvas.h"

class Figure {
protected:
    int x; // współrzędna x środka figury
    int y; // współrzędna y środka figury
    char fill_char; // znak wypełnienia figury

public:
    Figure(int x, int y, char fill_char) : x(x), y(y), fill_char(fill_char) {}

    virtual ~Figure() = default;

    virtual void draw(Canvas &c) const = 0;
};

class Rectangle : public Figure {
protected:
    int rect_width;
    int rect_height;

public:
    Rectangle(int x, int y, int width, int height, char fill_char);

    void draw(Canvas &c) const override;
};

class Square : public Rectangle {
public:
    Square(int x, int y, int size, char fill_char);
};

class Circle : public Figure {
private:
    int radius;

public:
    Circle(int x, int y, int radius, char fill_char);

    void draw(Canvas &c) const override;
};

#endif // FIGURE_H
