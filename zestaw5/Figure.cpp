#include "Figure.h"
#include "ASCIICanvas.h"
#include <cmath>
#include <algorithm>

const double VERTICAL_CORRECTION_FACTOR = 2.0;  // Koryguje proporcje pikseli w pionie

// Rectangle implementation
Rectangle::Rectangle(int x, int y, int width, int height, char fill_char)
    : Figure(x, y, fill_char), rect_width(width), rect_height(height) {}

void Rectangle::draw(Canvas &c) const {
    ASCIICanvas *ac = dynamic_cast<ASCIICanvas*>(&c);
    if (ac) {
        for (int i = std::max(0, y - rect_height / 2); i < std::min(ac->getHeight(), y + rect_height / 2); ++i) {
            for (int j = std::max(0, x - rect_width / 2); j < std::min(ac->getWidth(), x + rect_width / 2); ++j) {
                ac->draw(j, i, fill_char);
            }
        }
    }
}

// Square implementation
Square::Square(int x, int y, int size, char fill_char)
    : Rectangle(x, y, size, size, fill_char) {}

// Circle implementation
Circle::Circle(int x, int y, int radius, char fill_char)
    : Figure(x, y, fill_char), radius(radius) {}

void Circle::draw(Canvas &c) const {
    ASCIICanvas *ac = dynamic_cast<ASCIICanvas*>(&c);
    if (ac) {
        for (int i = 0; i < ac->getHeight(); ++i) {
            for (int j = 0; j < ac->getWidth(); ++j) {
                if (std::sqrt((j - x) * (j - x) + ((i - y) * VERTICAL_CORRECTION_FACTOR) * ((i - y) * VERTICAL_CORRECTION_FACTOR)) <= radius) {
                    ac->draw(j, i, fill_char);
                }
            }
        }
    }
}
