#ifndef CANVAS_H
#define CANVAS_H
#include <string>
class Canvas {
protected:
    int width;
    int height;
    char emptyPixel;

public:
    Canvas(int w, int h, char empty) : width(w), height(h), emptyPixel(empty) {}

    virtual ~Canvas() = default;

    virtual void draw(int x, int y, char c) = 0;
    virtual void render() const = 0;
    virtual void saveToFile(const std::string &filename) const = 0;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    char getEmptyPixel() const { return emptyPixel; }
};

#endif // CANVAS_H
