#include "ASCIICanvas.h"
#include <iostream>
#include <fstream>

ASCIICanvas::ASCIICanvas(int w, int h, char empty) : Canvas(w, h, empty), canvas(h, std::string(w, empty)) {}

void ASCIICanvas::draw(int x, int y, char c) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        canvas[y][x] = c;
    }
}

void ASCIICanvas::render() const {
    for (const auto& line : canvas) {
        std::cout << line << std::endl;
    }
}

void ASCIICanvas::saveToFile(const std::string &filename) const {
    std::ofstream file(filename);
    for (const auto& line : canvas) {
        file << line << std::endl;
    }
}
