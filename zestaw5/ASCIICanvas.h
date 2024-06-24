#ifndef ASCIICANVAS_H
#define ASCIICANVAS_H

#include "Canvas.h"
#include <vector>
#include <string>

class ASCIICanvas : public Canvas {
private:
    std::vector<std::string> canvas;

public:
    ASCIICanvas(int w, int h, char empty);

    void draw(int x, int y, char c) override;
    void render() const override;
    void saveToFile(const std::string &filename) const override;
};

#endif // ASCIICANVAS_H
