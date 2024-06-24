#include "ConfigParser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

ConfigParser::ConfigParser(const std::string &filename) : filename(filename), canvasWidth(0), canvasHeight(0), emptyPixelSymbol(' ') {}

void ConfigParser::parse() {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open config file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        if (!(iss >> key)) { continue; }
        if (key == "canvas_width") {
            iss >> canvasWidth;
        } else if (key == "canvas_height") {
            iss >> canvasHeight;
        } else if (key == "output_file") {
            iss >> outputFile;
        } else if (key == "empty_pixel") {
            iss >> emptyPixelSymbol;
        } else if (key == "figure") {
            FigureConfig fig;
            iss >> fig.type >> fig.x >> fig.y >> fig.size1 >> fig.size2 >> fig.symbol;
            figures.push_back(fig);
        }
    }
}

int ConfigParser::getCanvasWidth() const {
    return canvasWidth;
}

int ConfigParser::getCanvasHeight() const {
    return canvasHeight;
}

std::string ConfigParser::getOutputFile() const {
    return outputFile;
}

char ConfigParser::getEmptyPixelSymbol() const {
    return emptyPixelSymbol;
}

const std::vector<FigureConfig>& ConfigParser::getFigures() const {
    return figures;
}
