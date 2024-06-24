#include "ASCIICanvas.h"
#include "Figure.h"
#include "ConfigParser.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
        return 1;
    }

    ConfigParser parser(argv[1]);
    try {
        parser.parse();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    ASCIICanvas canvas(parser.getCanvasWidth(), parser.getCanvasHeight(), parser.getEmptyPixelSymbol());

    for (const auto &fig : parser.getFigures()) {
        if (fig.type == "rectangle") {
            Rectangle rect(fig.x, fig.y, fig.size1, fig.size2, fig.symbol);
            rect.draw(canvas);
        } else if (fig.type == "square") {
            Square square(fig.x, fig.y, fig.size1, fig.symbol);
            square.draw(canvas);
        } else if (fig.type == "circle") {
            Circle circle(fig.x, fig.y, fig.size1, fig.symbol);
            circle.draw(canvas);
        }
    }

    canvas.render();
    canvas.saveToFile(parser.getOutputFile());

    return 0;
}
